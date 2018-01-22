import QtQuick 2.8
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2

import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents

import org.nxos.softwareupdater 1.0 as SoftwareUpdater

Item {
    id: applicationWindow
    visible: true
    implicitWidth: 600
    implicitHeight: 350
//    minimumWidth: 600
//    minimumHeight: 350
//    title: qsTr("NX Software Updater")

    MainComponentForm {
        id: mainComponent
        Component.onCompleted: {
            SoftwareUpdater.PackageListViewController.fetchPackageList();
        }

        buttonsContainerComponent.btnQuit.onClicked: {
            SoftwareUpdater.QuitViewController.doQuit();
        }
        buttonsContainerComponent.btnUpdate.onClicked: {
            mainComponent.packageListComponent.packageModel = "";

            buttonsContainerComponent.btnQuit.enabled = false;
            buttonsContainerComponent.btnUpdate.enabled = false;
            buttonsContainerComponent.btnUpgrade.enabled = false;
            packageListComponent.fetchingListComponent.showUpdatingPackages();
            SoftwareUpdater.UpdateViewController.doUpdate();
        }
        buttonsContainerComponent.btnUpgrade.onClicked: {
            buttonsContainerComponent.btnQuit.enabled = false;
            buttonsContainerComponent.btnUpdate.enabled = false;
            buttonsContainerComponent.btnUpgrade.enabled = false;
            packageListComponent.fetchingListComponent.showUpgradingPackages();
            SoftwareUpdater.UpgradeViewController.doUpgrade();
        }
    }

    Dialog {
        id: minimizeDialog
        visible: false
        title: "Minimize to System Tray"
        standardButtons: StandardButton.Ok | StandardButton.Cancel
        modality: Qt.ApplicationModal
        width: 400
        height: 150

        onAccepted: {
            applicationWindow.hide();
            SoftwareUpdater.MainViewController.showTray();
        }

        Rectangle {
            Label {
                text: "Application will minimize to System Tray"
            }
        }
    }

//    onClosing: {
//        close.accepted = false;
//        minimizeDialog.visible = true;
//    }

    Connections {
        target: SoftwareUpdater.MainViewController

        onShowWindow: {
            applicationWindow.show();
        }
    }

    Connections {
        target: SoftwareUpdater.PackageListViewController

        onPackageListChanged: {
            console.log('>>>> QML packageListChanged....');

            mainComponent.buttonsContainerComponent.btnQuit.enabled = true;
            mainComponent.buttonsContainerComponent.btnUpdate.enabled = true;

            mainComponent.packageListComponent.fetchingListComponent.showPackageListText();
            mainComponent.packageListComponent.packageModel = packageList;

            if(packageList.length > 0) {
                mainComponent.packageListComponent.labelUpdated.visible = false;
                mainComponent.buttonsContainerComponent.btnUpgrade.enabled = true;
            } else {
                mainComponent.packageListComponent.labelUpdated.visible = true;
                mainComponent.buttonsContainerComponent.btnUpgrade.enabled = false;
            }
        }
    }

    Connections {
        target: SoftwareUpdater.UpdateViewController

        onUpdateComplete: {
            console.log('>>>> Update Complete....');

            mainComponent.packageListComponent.fetchingListComponent.showFetchingPackages()
            SoftwareUpdater.PackageListViewController.fetchPackageList();
        }
    }

    Connections {
        target: SoftwareUpdater.UpgradeViewController

        onUpgradeComplete: {
            console.log('>>>> Upgrade Complete....');

            mainComponent.buttonsContainerComponent.btnQuit.enabled = true;
            mainComponent.packageListComponent.packageModel = "";

            mainComponent.packageListComponent.fetchingListComponent.showFetchingPackages()
            SoftwareUpdater.PackageListViewController.fetchPackageList();
        }
    }

    function getInstance() {
        return mainComponent
    }
}
