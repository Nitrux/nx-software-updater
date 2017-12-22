import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Item {
    id: rectangle
    width: 600
    height: 100
    property alias btnUpdate: btnUpdate
    property alias btnUpgrade: btnUpgrade
    property alias btnRemindLater: btnRemindLater
    property alias btnQuit: btnQuit

    Row {
        id: row
        height: 100
        spacing: 10
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        layoutDirection: Qt.RightToLeft

        PlasmaComponents.Button {
            id: btnUpgrade

            text: qsTr("Upgrade Now")
            anchors.verticalCenter: parent.verticalCenter
        }

        PlasmaComponents.Button {
            id: btnUpdate
            text: qsTr("Update")
            anchors.verticalCenter: parent.verticalCenter
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
        }
    }
}
