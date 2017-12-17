project(nx-software-updater)
cmake_minimum_required(VERSION 3.2)

enable_testing()

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the Qt libraries for Qt Quick/QML
find_package(Qt5Core CONFIG REQUIRED Qml Quick Gui)
find_package(Qt5Quick)
find_package(Qt5Qml)
find_package(Qt5Gui)

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
    # END Interactors

    # START Helpers
    src/helpers/apthelper.h
    src/helpers/apthelper.cpp

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
    # END Entities

    # START View Controllers
    src/ui/viewcontroller.h
    src/ui/viewcontroller.cpp

    src/ui/remindlaterviewcontroller.h
    src/ui/remindlaterviewcontroller.cpp

    src/ui/packagelistviewcontroller.cpp
    src/ui/packagelistviewcontroller.h
    # END View Controllers

    # START DTO
    src/dto/packagedto.h
    src/dto/packagedto.cpp
    # END DTO
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
)

add_subdirectory(src/tests)
