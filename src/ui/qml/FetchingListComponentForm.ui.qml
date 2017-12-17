import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Item {
    width: 600
    height: 90

    PlasmaComponents.Label {
        id: fetchingListTxt

        text: qsTr("Fetching Package List")
        color: "#666"
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 14
    }

    PlasmaComponents.ProgressBar {
        id: fetchingIndicator
        indeterminate: true
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: fetchingListTxt.bottom
        anchors.topMargin: 0
    }
}
