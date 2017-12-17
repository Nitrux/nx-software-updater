import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Rectangle {
    id: container
    width: 600
    height: 350
    color: '#eeeeee'

    FetchingListComponent {
        id: fetchingListComponent
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    PackageListComponent {
        id: packageListComponent

        anchors.top: fetchingListComponent.bottom
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    ButtonsContainerComponent {
        id: buttonsContainerComponent

        anchors.top: packageListComponent.bottom
        anchors.topMargin: 0
    }
}
