import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Rectangle {
    id: container
    anchors.fill: parent
    color: '#eeeeee'

    property alias packageListComponent: packageListComponent
    property alias buttonsContainerComponent: buttonsContainerComponent

    PackageListComponent {
        id: packageListComponent

        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 70
    }

    ButtonsContainerComponent {
        id: buttonsContainerComponent

        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
    }
}
