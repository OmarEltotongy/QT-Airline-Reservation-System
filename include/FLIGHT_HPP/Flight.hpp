#ifndef __FLIGHT_H__
#define __FLIGHT_H__
#include "../USERS_HPP/userClasses.hpp"
#include "../ENUMS/flights_enum.hpp"
#include "../ENUMS/user_enums.hpp"
#include <QObject>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define DEBUG 1

// Forward declaration of Administrator class
class User;
class Administrator;

class Flight: public QObject
{
    Q_OBJECT
private:
    std::string flightNumber;      // Unique identifier for the flight.
    std::string departureLocation; // Origin
    std::string arrivalLocation;   // Destination
    std::string departureTime;     // Scheduled departure time.
    std::string arrivalTime;       // Scheduled arrival time.
    std::string aircraftID;        // ID of the assigned aircraft.
    flightStatus status;           // Current status of the flight (e.g., "On Time", "Delayed").
    AssignedCrew assignedCrew;     // Nested struct for assigned crew
    int maxSeats;                  // Maximum number of seats on the flight.
    double price;                  // Price of the flight.
    int availableSeats;            // Number of available seats.
    std::string gate;              // Gate for the flight.

public:
    Flight(const std::string &FN, const std::string &origin, const std::string &destination,
           const std::string &DT, const std::string &AT, const flightStatus &FS,
           const std::string &ACID, const AssignedCrew &assignedCrew,
           int maxSeats, double price, const std::string &gate);
    Flight(Administrator &admin);
    static void ManageFlightsMenu(Administrator &admin);
    json toJson() const; // Method to convert Flight object to JSON

    /************************************Flights Functions*************************************/
    AssignedCrew assignCrewToFlight(const std::string &flightNumber, json &pilots, json &Flight_Attendant);
    flightProcess addFlight(Flight &flight_admin);
    flightProcess updateFlight(Flight &flight_admin);
    flightProcess deleteFlight();
    /******************************************************************************************/

    void viewAllFlights(); // Print the database

    ~Flight();
};

flightStatus intStatusToflightStatus(int s);
std::string intStatusToStringStatus(int s);
std::string flightStatusToString(flightStatus status);
std::string roleToString(rolesTypes role);

#endif // __FLIGHT_H__
