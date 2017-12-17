import QtQuick 2.4
import QtQuick.Controls 2.2

import org.kde.plasma.components 2.0 as PlasmaComponents

Rectangle {
    width: 600
    height: 250
    color: '#ffffff'

    ScrollView {
        id: scrollView
        anchors.fill: parent
        anchors.topMargin: 20
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        anchors.bottomMargin: 20

        ListView {
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            model: ListModel {
                ListElement {
                    name: "One"
                }
                ListElement {
                    name: "Two"
                }
                ListElement {
                    name: "Three"
                }
                ListElement {
                    name: "Four"
                }
                ListElement {
                    name: "Five"
                }
                ListElement {
                    name: "One"
                }
                ListElement {
                    name: "Two"
                }
                ListElement {
                    name: "Three"
                }
                ListElement {
                    name: "Four"
                }
                ListElement {
                    name: "Five"
                }
                ListElement {
                    name: "One"
                }
                ListElement {
                    name: "Two"
                }
                ListElement {
                    name: "Three"
                }
                ListElement {
                    name: "Four"
                }
                ListElement {
                    name: "Five"
                }
                ListElement {
                    name: "One"
                }
                ListElement {
                    name: "Two"
                }
                ListElement {
                    name: "Three"
                }
                ListElement {
                    name: "Four"
                }
                ListElement {
                    name: "Five"
                }
            }
            delegate: Text {
                text: name
            }
        }
    }
}
