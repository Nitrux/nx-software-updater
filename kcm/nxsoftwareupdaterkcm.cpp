#include "nxsoftwareupdaterkcm.h"

#include <KAboutData>
#include <KLocalizedString>
#include <KPluginFactory>
#include <KAboutData>

K_PLUGIN_FACTORY_WITH_JSON(NxSoftwareUpdaterKCMFactory,
                           "org_nxos_softwareupdater.json",
                           registerPlugin<NxSoftwareUpdaterKCM>();)

K_EXPORT_PLUGIN(
    NxSoftwareUpdaterKCMFactory("org.nxos.softwareupdater" /* kcm name */,
                                "org.nxos.softwareupdater" /* catalog name */))

NxSoftwareUpdaterKCM::NxSoftwareUpdaterKCM(QObject* parent,
                                           const QVariantList& args)
    : KQuickAddons::ConfigModule(parent, args) {
  KAboutData* about =
      new KAboutData("org.nxos.softwareupdater", i18n("GUI Software Updater"),
                     "0.2", QString(), KAboutLicense::Unknown);
  about->addAuthor(i18n("Anupam Basak"), QString(), "anupam.basak27@gmail.com");
  setAboutData(about);
  setButtons(Help | Apply | Default);
}

NxSoftwareUpdaterKCM::~NxSoftwareUpdaterKCM() {}

#include "nxsoftwareupdaterkcm.moc"
