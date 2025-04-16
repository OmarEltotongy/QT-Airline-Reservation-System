# ✈️ QT Airline Reservation System

![Application Logo](resources/airplane.png)

A comprehensive airline management system with GUI interface built using QT framework, featuring role-based access, flight/reservation management, and JSON data persistence.

## 📂 Project Structure

```
airline-reservation/
├── data/                       # JSON data files
│   ├── aircraft.json           # Aircraft specifications
│   ├── flightAttendant.json    # Crew members data
│   ├── flights.json            # Flight schedules
│   ├── maintenance.json        # Maintenance records
│   ├── pilots.json             # Pilot information
│   ├── reservation.json        # Booking data
│   └── users.json              # User credentials
│
├── include/                    # Header files
│   ├── AIRCRAFT_HPP/           # Aircraft class
│   ├── ENUMS/                  # System enumerations
│   ├── FLIGHT_HPP/             # Flight management
│   ├── JSON_HPP/               # JSON handling
│   ├── RESERVATION_HPP/        # Booking system
│   └── USERS_HPP/              # User management
│
├── src/                        # Source implementation
│   ├── AIRCRAFT_CPP/           # Aircraft logic
│   ├── FLIGHT_CPP/             # Flight operations
│   ├── JSONHELPERFUNCTION_CPP/ # Data persistence
│   ├── RESERVATION_CPP/        # Reservation handling
│   └── USERS_CPP/              # User authentication
│
├── UI Modules/                 # QT Designer files
│   ├── Main Window/
│   │   ├── _1_mainwindow.cpp
│   │   ├── _1_mainwindow.h
│   │   └── _1_mainwindow.ui
│   ├── Admin Modules/
│   │   ├── Flight Management/
│   │   │   ├── _2a1adminmanageflights.cpp
│   │   │   ├── _2a1adminmanageflights.h
│   │   │   └── _2a1adminmanageflights.ui
│   │   └── ... (other admin modules)
│   ├── Agent Modules/
│   │   └── _3_mainagentmenu.*
│   └── Passenger Modules/
│       └── _4_mainpassengermenu.*
│
├── resources/                  # Application assets
│   ├── airplane.ico            # Application icon
│   └── airplane.png            # Main logo
│
└── docs/                       # Documentation
    ├── Project.pdf             # Project specification
    └── TestCases.md            # Validation scenarios
```

## 🌟 Key Features

### Role-Based Access Control
- **Admin**: Full system configuration
- **Agent**: Booking management
- **Passenger**: Self-service portal

### Core Functionalities
- Flight scheduling with status tracking
- Aircraft maintenance logging
- Reservation management system
- JSON-based data persistence
- Interactive QT interfaces

## 🛠️ Installation

### Prerequisites
- QT 6.8 or later
- C++17 compiler
- CMake 3.5+

### Build & Run
```bash
# Clone repository
git clone https://github.com/OmarEltotongy/QT-Airline-Reservation-System.git
cd QT-Airline-Reservation-System

# Configure and build
mkdir build && cd build
cmake ..
make

# Run application
./AirlineReservation
```

## 👥 User Guide

### Login Credentials
| Role      | Username  | Password    |
|-----------|-----------|-------------|
| Admin     | admin1    | admin123    |
| Agent     | agent1    | agent456    |
| Passenger | passenger1| pass123     |

### Navigation
1. **Main Window**: Authentication portal
2. **Admin Dashboard**: 
   - Flight/Aircraft management
   - User administration
   - Reporting tools
3. **Agent Interface**: Booking operations
4. **Passenger Portal**: Flight search and self-booking

## 📊 Data Management
- All data stored in JSON format
- Automatic file creation on first run
- Modular data handlers for each entity type

## 📜 License
MIT License - See included LICENSE file

## 📧 Contact
For support or contributions, please contact:
- Omar Eltoutongy on my [linkedin](https://www.linkedin.com/in/omar-eltoutongy/) 
- GitHub: [@OmarEltotongy](https://github.com/OmarEltotongy)
```
