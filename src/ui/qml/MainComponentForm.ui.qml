import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Rectangle {
    id: container
    width: 600
    height: 350

    PackageListComponent {
        id: packageListComponent
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    ButtonsContainerComponent {
        id: buttonsContainerComponent

        anchors.top: packageListComponent.bottom
        anchors.topMargin: 0
    }
}
