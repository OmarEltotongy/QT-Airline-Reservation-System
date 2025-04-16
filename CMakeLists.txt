cmake_minimum_required(VERSION 3.19)
project(AirlineSystem LANGUAGES CXX)

# ==================== Qt Configuration ====================
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# ==================== C++ Standard ====================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ==================== Project Structure ====================
# Include all necessary directories
include_directories(
    ${CMAKE_SOURCE_DIR}
    include
    include/JSON_HPP
    include/AIRCRAFT_HPP
    include/FLIGHT_HPP
    include/RESERVATION_HPP
    include/USERS_HPP
    include/ENUMS
)


set(DATA_DIR ${CMAKE_SOURCE_DIR}/data)

# Make sure build directory is in include path
include_directories(${CMAKE_BINARY_DIR})


# Add this near the top of your file, after project() but before qt_add_executable
set(RESOURCES
    Resources.qrc
)


# ==================== Executable ====================
qt_add_executable(AirlineSystem
    WIN32 MACOSX_BUNDLE

    # List UI files first

    _1_mainwindow.ui
    _2_mainadminmenu.ui
    _2a4admingeneratereports.ui
    _2a3adminmangeusers.ui
    _2a2adminmangeaircraft.ui
    _2a1adminmanageflights.ui
    _3_mainagentmenu.ui
    _4_mainpassengermenu.ui

    # Main application files
    src/MAIN/main.cpp
    _1_mainwindow.cpp
    _1_mainwindow.h

    # Admin window files
    _2_mainadminmenu.h
    _2_mainadminmenu.cpp
    _2a1adminmanageflights.h
    _2a1adminmanageflights.cpp
    _2a2adminmangeaircraft.h
    _2a2adminmangeaircraft.cpp
    _2a3adminmangeusers.h
    _2a3adminmangeusers.cpp
    _2a4admingeneratereports.h
    _2a4admingeneratereports.cpp

    # Booking Agent Files

    _3_mainagentmenu.h
    _3_mainagentmenu.cpp


    # Passenger Files
    _4_mainpassengermenu.h
    _4_mainpassengermenu.cpp


    # Core application classes
    src/AIRCRAFT_CPP/Aircraft.cpp
    src/FLIGHT_CPP/Flight.cpp
    src/JSONHELPERFUNCTION_CPP/jsonHelperFunctions.cpp
    src/RESERVATION_CPP/Reservation.cpp
    src/USERS_CPP/userClasses.cpp

    # Header files (for moc)
    include/AIRCRAFT_HPP/Aircraft.hpp
    include/ENUMS/aircraft_enums.hpp
    include/ENUMS/flights_enum.hpp
    include/ENUMS/user_enums.hpp
    include/FLIGHT_HPP/Flight.hpp
    include/JSON_HPP/json.hpp
    include/JSON_HPP/jsonHelperFunctions.hpp
    include/RESERVATION_HPP/Reservation.hpp
    include/USERS_HPP/userClasses.hpp
    data/aircraft.json data/flightAttendant.json data/flights.json data/maintenance.json data/pilots.json data/reservation.json data/users.json

    # Resources
    ${RESOURCES}




)

# ==================== Libraries ====================
target_link_libraries(AirlineSystem
    PRIVATE
        Qt6::Core
        Qt6::Widgets
)

# ==================== Install/Deploy ====================
include(GNUInstallDirs)
install(TARGETS AirlineSystem
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET AirlineSystem
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
