import QtQuick 2.8
import QtQuick.Controls 2.2

import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents

import org.nxos.softwareupdater 1.0 as SoftwareUpdater

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 600
    height: 350
    title: qsTr("NX Software Updater")

    MainComponentForm {
        id: mainComponent
        Component.onCompleted: {
            SoftwareUpdater.PackageListViewController.fetchPackageList();
        }

        buttonsContainerComponent.btnQuit.onClicked: {
            Qt.quit();
        }
        buttonsContainerComponent.btnUpdate.onClicked: {
            mainComponent.packageListComponent.packageModel = "";

            packageListComponent.fetchingListComponent.showUpdatingPackages()
            SoftwareUpdater.UpdateViewController.doUpdate();
        }
        buttonsContainerComponent.btnUpgrade.onClicked: {
            packageListComponent.fetchingListComponent.showUpgradingPackages()
            SoftwareUpdater.UpgradeViewController.doUpgrade();
        }
    }

    Connections {
        target: SoftwareUpdater.PackageListViewController

        onPackageListChanged: {
            console.log('>>>> QML packageListChanged....')

            mainComponent.packageListComponent.fetchingListComponent.showPackageListText()
            mainComponent.packageListComponent.packageModel = packageList

            if(packageList.length > 0) {
                mainComponent.packageListComponent.labelUpdated.visible = false
                mainComponent.buttonsContainerComponent.btnUpgrade.visible = true
            } else {
                mainComponent.packageListComponent.labelUpdated.visible = true
                mainComponent.buttonsContainerComponent.btnUpgrade.visible = false
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

            mainComponent.packageListComponent.packageModel = "";

            mainComponent.packageListComponent.fetchingListComponent.showFetchingPackages()
            SoftwareUpdater.PackageListViewController.fetchPackageList();
        }
    }

    function getInstance() {
        return mainComponent
    }
}
