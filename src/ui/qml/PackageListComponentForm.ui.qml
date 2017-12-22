import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Rectangle {
    width: 600
    height: 250
    color: '#ffffff'

    property alias packageModel: packageListview.model

    ScrollView {
        id: scrollView
        anchors.fill: parent
        anchors.topMargin: 20
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        anchors.bottomMargin: 20

        ListView {
            id: packageListview
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            model: packageModel
            delegate: Text {
                text: modelData.packageName
            }
        }
    }
}
