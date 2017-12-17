import QtQuick 2.4

import org.nxos.softwareupdater 1.0 as SoftwareUpdater

ButtonsContainerComponentForm {
    button.onClicked: {
        SoftwareUpdater.PackageListViewController.updateClicked();
    }
}
