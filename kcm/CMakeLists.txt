include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(kcm_SRCS
    nxsoftwareupdaterkcm.h
    nxsoftwareupdaterkcm.cpp
)

add_library(org.nxos.softwareupdater MODULE ${kcm_SRCS})

target_link_libraries(org.nxos.softwareupdater
    Qt5::Quick
    KF5::CoreAddons
    KF5::Declarative
    KF5::I18n
    KF5::QuickAddons
)

kcoreaddons_desktop_to_json(org.nxos.softwareupdater org_nxos_softwareupdater.desktop SERVICE_TYPES kcmodule.desktop)

#this desktop file is installed only for retrocompatibility with sycoca
install(FILES org_nxos_softwareupdater.desktop DESTINATION ${SERVICES_INSTALL_DIR})
install(TARGETS org.nxos.softwareupdater DESTINATION ${PLUGIN_INSTALL_DIR}/kcms)

kpackage_install_package(package org.nxos.softwareupdater kcms)
