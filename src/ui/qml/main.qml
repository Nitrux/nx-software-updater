import QtQuick 2.7
import QtQuick.Controls 2.2

import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents

import org.nxos.softwareupdater 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 600
    height: 250
    title: qsTr("NX Software Updater")

    PlasmaComponents.Button {
        text: "Remind Later"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onClicked: {
            RemindLaterViewController.clicked()
        }
    }
}
