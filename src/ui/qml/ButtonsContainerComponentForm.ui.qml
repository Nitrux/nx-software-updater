import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Item {
    id: rectangle
    width: 600
    height: 100

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
            id: button

            text: qsTr("Update Now")
            anchors.verticalCenter: parent.verticalCenter
        }

        PlasmaComponents.Button {
            id: button1
            text: qsTr("Try Again")
            anchors.verticalCenter: parent.verticalCenter
        }

        PlasmaComponents.Button {
            id: button2
            text: qsTr("Remind Later")
            anchors.verticalCenter: parent.verticalCenter
        }

        PlasmaComponents.Button {
            id: button3
            text: qsTr("Quit")
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
