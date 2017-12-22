import QtQuick 2.4

FetchingListComponentForm {
    function showFetchingPackages() {
        fetchingIndicator.visible = true;

        packageListTxt.visible = false;
        updatingPackageListTxt.visible = false;
        upgradingPackageListTxt.visible = false;
        fetchingListTxt.visible = true;
    }

    function showUpdatingPackages() {
        fetchingIndicator.visible = true;

        packageListTxt.visible = false;
        updatingPackageListTxt.visible = true;
        upgradingPackageListTxt.visible = false;
        fetchingListTxt.visible = false;
    }

    function showUpgradingPackages() {
        fetchingIndicator.visible = true;

        packageListTxt.visible = false;
        updatingPackageListTxt.visible = false;
        upgradingPackageListTxt.visible = true;
        fetchingListTxt.visible = false;
    }

    function showPackageListText() {
        fetchingIndicator.visible = false;

        packageListTxt.visible = true;
        updatingPackageListTxt.visible = false;
        upgradingPackageListTxt.visible = false;
        fetchingListTxt.visible = false;
    }
}
