import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Item {
    id: rectangle
    width: 600
    height: 50

    property alias btnUpdate: btnUpdate
    property alias btnUpgrade: btnUpgrade
    property alias btnRemindLater: btnRemindLater
    property alias btnQuit: btnQuit

    Row {
        id: row
        spacing: 10
        anchors.fill: parent
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        layoutDirection: Qt.RightToLeft

        PlasmaComponents.Button {
            id: btnUpgrade

            text: qsTr("Install")
            anchors.verticalCenter: parent.verticalCenter
            enabled: false
        }

        PlasmaComponents.Button {
            id: btnUpdate
            text: qsTr("Check for Updates")
            anchors.verticalCenter: parent.verticalCenter
            enabled: false
        }

        PlasmaComponents.Button {
            id: btnRemindLater
            text: qsTr("Remind Later")
            anchors.verticalCenter: parent.verticalCenter
            visible: false
        }

        PlasmaComponents.Button {
            id: btnQuit
            text: qsTr("Quit")
            anchors.verticalCenter: parent.verticalCenter
            enabled: false
            visible: false
        }
    }
}
