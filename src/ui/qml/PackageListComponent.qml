import QtQuick 2.4

import org.nxos.softwareupdater 1.0 as SoftwareUpdater

PackageListComponentForm {
    width: 600
    height: 160

    Connections {
        target: SoftwareUpdater.PackageListViewController

        onPackageListChanged: {
            console.log('>>>> QML paclageListChanged....')
        }
    }
}
