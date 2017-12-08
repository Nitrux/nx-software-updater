project(nx-software-updater)
cmake_minimum_required(VERSION 3.9)

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
    src/ui/qml.qrc
)

# add source files
set (
    SOURCE
    ${SOURCE}
    src/main.cpp
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
