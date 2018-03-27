enable_testing()

# Find the Qt libraries for Qt Quick/QML
find_package(Qt5Core CONFIG REQUIRED Qml Quick Gui Concurrent Widgets)
find_package(Qt5Quick)
find_package(Qt5Qml)
find_package(Qt5Gui)
find_package(Qt5Concurrent)
find_package(Qt5Widgets)
find_package(KF5 REQUIRED COMPONENTS Auth)

include(KDEInstallDirs)

# Add KAuth actions File
kauth_install_actions(org.nxos.softwareupdater actions/org.nxos.softwareupdater.actions)

add_executable(
    ${PROJECT_NAME}_helper
    helpers/rootshellkauthhelper.h
    helpers/rootshellkauthhelper.cpp
)
target_link_libraries(
    ${PROJECT_NAME}_helper
    ${KDE5_KDECORE_LIBS}
    Qt5::Core
    KF5::Auth
)
install(TARGETS ${PROJECT_NAME}_helper DESTINATION ${KAUTH_HELPER_INSTALL_DIR})
kauth_install_helper_files(${PROJECT_NAME}_helper org.nxos.softwareupdater root)

# add source files
set (
    SOURCE
    ${SOURCE}

    softwareupdaterplugin.h
    softwareupdaterplugin.cpp

    # START Interactors
    interactors/interactor.h
    interactors/interactor.cpp

    interactors/downloadandinstallinteractor.h
    interactors/downloadandinstallinteractor.cpp

    interactors/packagelistinteractor.h
    interactors/packagelistinteractor.cpp

    interactors/remindlaterinteractor.h
    interactors/remindlaterinteractor.cpp

    interactors/superuseraccessinteractor.h
    interactors/superuseraccessinteractor.cpp

    interactors/updateinteractor.h
    interactors/updateinteractor.cpp

    interactors/upgradeinteractor.h
    interactors/upgradeinteractor.cpp

    interactors/quitinteractor.h
    interactors/quitinteractor.cpp
    # END Interactors

    # START Helpers
    helpers/apthelper.h
    helpers/apthelper.cpp

    helpers/nxihelper.h
    helpers/nxihelper.cpp

    helpers/shellhelper.h
    helpers/shellhelper.cpp
    # END Helpers

    # START Entities
    entities/packages.h
    entities/packages.cpp

    entities/reminder.h
    entities/reminder.cpp

    entities/superuser.h
    entities/superuser.cpp

    entities/packagemanager.cpp
    entities/packagemanager.h

    entities/apt.cpp
    entities/apt.h

    entities/nxi.cpp
    entities/nxi.h
    # END Entities

    # START View Controllers
    ui/viewcontroller.h
    ui/viewcontroller.cpp

    ui/mainviewcontroller.h
    ui/mainviewcontroller.cpp

    ui/remindlaterviewcontroller.h
    ui/remindlaterviewcontroller.cpp

    ui/packagelistviewcontroller.cpp
    ui/packagelistviewcontroller.h

    ui/updateviewcontroller.cpp
    ui/updateviewcontroller.h

    ui/upgradeviewcontroller.cpp
    ui/upgradeviewcontroller.h

    ui/quitviewcontroller.h
    ui/quitviewcontroller.cpp
    # END View Controllers

    # START Listeners
    listeners/packagelistlistener.h
    listeners/updatelistener.h
    listeners/upgradelistener.h
    # END Listeners

    # START DTO
    dto/packagedto.h
    dto/packagedto.cpp
    # END DTO

    # START Others
    actions/actionids.h
    # END Others

    qmldir
)

add_library(nx_software_updater_plugin SHARED ${SOURCE})
target_link_libraries(nx_software_updater_plugin
    Qt5::Qml
    Qt5::Quick
    Qt5::Concurrent
    KF5::Auth
    Qt5::Widgets
)

set(INSTALL_PATH ${QML_INSTALL_DIR}/org/nxos/softwareupdater)

install(TARGETS nx_software_updater_plugin DESTINATION ${INSTALL_PATH})
install(FILES qmldir DESTINATION ${INSTALL_PATH})

#add_executable (
#    ${PROJECT_NAME}
#    ${SOURCE}
#    ${qml_QRC}
#)

#target_link_libraries(
#    ${PROJECT_NAME}
#    Qt5::Qml
#    Qt5::Quick
#    Qt5::Concurrent
#    KF5::Auth
#    Qt5::Widgets
#)

#install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#install(FILES "org.nxos.softwareupdater.desktop" DESTINATION share/applications)

#add_subdirectory(tests)
