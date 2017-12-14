import QtQuick 2.8
import QtQuick.Controls 2.2

import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents

import org.nxos.softwareupdater 1.0 as SoftwareUpdater

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 600
    height: 350
    title: qsTr("NX Software Updater")

    MainComponentForm {
    }
}
