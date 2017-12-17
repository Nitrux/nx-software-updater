cmake_minimum_required(VERSION 3.2)

enable_testing()

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Test)

###
# TEST ENTITIES
###

set (
    ENTITIES_SOURCE

    # START Interactors
    ../interactors/interactor.h
    ../interactors/interactor.cpp

    ../interactors/downloadandinstallinteractor.h
    ../interactors/downloadandinstallinteractor.cpp

    ../interactors/packagelistinteractor.h
    ../interactors/packagelistinteractor.cpp

    ../interactors/remindlaterinteractor.h
    ../interactors/remindlaterinteractor.cpp

    ../interactors/superuseraccessinteractor.h
    ../interactors/superuseraccessinteractor.cpp
    # END Interactors

    # START Helpers
    ../helpers/apthelper.h
    ../helpers/apthelper.cpp

    ../helpers/shellhelper.h
    ../helpers/shellhelper.cpp
    # END Helpers

    # START Entities
    ../entities/packages.h
    ../entities/packages.cpp

    ../entities/reminder.h
    ../entities/reminder.cpp

    ../entities/superuser.h
    ../entities/superuser.cpp
    # END Entities

    # START View Controllers
    ../ui/viewcontroller.h
    ../ui/viewcontroller.cpp

    ../ui/remindlaterviewcontroller.h
    ../ui/remindlaterviewcontroller.cpp

    ../ui/packagelistviewcontroller.cpp
    ../ui/packagelistviewcontroller.h
    # END View Controllers

    # START DTO
    ../dto/packagedto.h
    ../dto/packagedto.cpp
    # END DTO

    # START Dummy Classes
    DummyAptHelper.h
    DummyAptHelper.cpp
    # END Dummy Classes

    entities_tests.cpp

    ${ENTITIES_SOURCE}
)

add_executable(entities_tests ${ENTITIES_SOURCE})
target_compile_options(entities_tests PUBLIC -fexceptions)
target_link_libraries(
    entities_tests
    Qt5::Test
)
add_test(entities_tests entities_tests)
