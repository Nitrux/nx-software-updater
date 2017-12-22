import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Item {
    width: 600
    height: 90

    property alias fetchingListTxt: fetchingListTxt
    property alias packageListTxt: packageListTxt
    property alias fetchingIndicator: fetchingIndicator
    property alias updatingPackageListTxt: updatingPackageListTxt
    property alias upgradingPackageListTxt: upgradingPackageListTxt

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

    PlasmaComponents.Label {
        id: packageListTxt

        text: qsTr("List of Packages to be Upgraded")
        color: "#666"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 14
        visible: false
    }

    PlasmaComponents.Label {
        id: updatingPackageListTxt

        text: qsTr("Updating Package List")
        color: "#666"
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 14
        visible: false
    }

    PlasmaComponents.Label {
        id: upgradingPackageListTxt

        text: qsTr("Downloading and Installing Updates")
        color: "#666"
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 14
        visible: false
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
