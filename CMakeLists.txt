cmake_minimum_required(VERSION 3.2)
project(nx-software-updater VERSION 0.2)

enable_testing()

set(CMAKE_INSTALL_PREFIX /usr)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(ECM 0.0.11 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

# Find the Qt libraries for Qt Quick/QML
find_package(Qt5Core CONFIG REQUIRED Qml Quick Gui Concurrent)
find_package(Qt5Quick)
find_package(Qt5Qml)
find_package(Qt5Gui)
find_package(Qt5Concurrent)
find_package(KF5 REQUIRED COMPONENTS Auth)

include(KDEInstallDirs)

# Add KAuth actions File
kauth_install_actions(org.nxos.softwareupdater src/actions/org.nxos.softwareupdater.actions)

add_executable(
    ${PROJECT_NAME}_helper
    src/helpers/rootshellkauthhelper.h
    src/helpers/rootshellkauthhelper.cpp
)
target_link_libraries(
    ${PROJECT_NAME}_helper
    ${KDE5_KDECORE_LIBS}
    Qt5::Core
    KF5::Auth
)
install(TARGETS ${PROJECT_NAME}_helper DESTINATION ${KAUTH_HELPER_INSTALL_DIR})
kauth_install_helper_files(${PROJECT_NAME}_helper org.nxos.softwareupdater root)


# add the qml.qrc file
qt5_add_resources (
    qml_QRC
    src/ui/qml/qml.qrc
)

# add source files
set (
    SOURCE
    ${SOURCE}
    src/main.cpp

    # START Interactors
    src/interactors/interactor.h
    src/interactors/interactor.cpp

    src/interactors/downloadandinstallinteractor.h
    src/interactors/downloadandinstallinteractor.cpp

    src/interactors/packagelistinteractor.h
    src/interactors/packagelistinteractor.cpp

    src/interactors/remindlaterinteractor.h
    src/interactors/remindlaterinteractor.cpp

    src/interactors/superuseraccessinteractor.h
    src/interactors/superuseraccessinteractor.cpp

    src/interactors/updateinteractor.h
    src/interactors/updateinteractor.cpp

    src/interactors/upgradeinteractor.h
    src/interactors/upgradeinteractor.cpp

    src/interactors/quitinteractor.h
    src/interactors/quitinteractor.cpp
    # END Interactors

    # START Helpers
    src/helpers/apthelper.h
    src/helpers/apthelper.cpp

    src/helpers/nxihelper.h
    src/helpers/nxihelper.cpp

    src/helpers/shellhelper.h
    src/helpers/shellhelper.cpp
    # END Helpers

    # START Entities
    src/entities/packages.h
    src/entities/packages.cpp

    src/entities/reminder.h
    src/entities/reminder.cpp

    src/entities/superuser.h
    src/entities/superuser.cpp

    src/entities/packagemanager.cpp
    src/entities/packagemanager.h

    src/entities/apt.cpp
    src/entities/apt.h

    src/entities/nxi.cpp
    src/entities/nxi.h
    # END Entities

    # START View Controllers
    src/ui/viewcontroller.h
    src/ui/viewcontroller.cpp

    src/ui/remindlaterviewcontroller.h
    src/ui/remindlaterviewcontroller.cpp

    src/ui/packagelistviewcontroller.cpp
    src/ui/packagelistviewcontroller.h

    src/ui/updateviewcontroller.cpp
    src/ui/updateviewcontroller.h

    src/ui/upgradeviewcontroller.cpp
    src/ui/upgradeviewcontroller.h

    src/ui/quitviewcontroller.h
    src/ui/quitviewcontroller.cpp
    # END View Controllers

    # START Listeners
    src/listeners/packagelistlistener.h
    src/listeners/updatelistener.h
    src/listeners/upgradelistener.h
    # END Listeners

    # START DTO
    src/dto/packagedto.h
    src/dto/packagedto.cpp
    # END DTO

    # START Others
    src/actions/actionids.h
    # END Others
)

add_executable (
    ${PROJECT_NAME}
    ${SOURCE}
    ${qml_QRC}
)

target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Qml
    Qt5::Quick
    Qt5::Concurrent
    KF5::Auth
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "org.nxos.softwareupdater.desktop" DESTINATION share/applications)

#add_subdirectory(src/tests)
