import QtQuick 2.4

Rectangle {
    id: rectangle
    property string packageName
    height: 30
    color: 'transparent'

    Image {
        id: packageImage

        source: "ic_package.png"
        fillMode: Image.PreserveAspectFit

        width: 20
        height: 20

        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        color: "#666666"
        text: packageName
        anchors.left: packageImage.right
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }
}
