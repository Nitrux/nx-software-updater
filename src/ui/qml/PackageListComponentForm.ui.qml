import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.extras 2.0 as PlasmaExtras

Item {
    width: 600
    height: 260

    property alias packageModel: packageListview.model
    property alias fetchingListComponent: fetchingListComponent

    FetchingListComponent {
        id: fetchingListComponent
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 0
        anchors.leftMargin: 0
        anchors.rightMargin: 0
    }

    Rectangle {
        color: '#ffffff'

        anchors.top: fetchingListComponent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: 20
        anchors.rightMargin: 20

        PlasmaExtras.ScrollArea {
            id: scrollView
            anchors.fill: parent

            ListView {
                id: packageListview

                anchors.fill: parent
                anchors.topMargin: 20
                anchors.leftMargin: 20
                anchors.rightMargin: 20
                anchors.bottomMargin: 20

                model: packageModel
                delegate: PackageListItemDelegate {
                    packageName: modelData.packageName
                }
            }
        }
    }
}
