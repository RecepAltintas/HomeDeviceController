#include <iostream>
#include <limits> // Required for input validation
#include "SmartHomeController.hpp"
#include "Light.hpp"
#include "Fan.hpp"
#include "Thermostat.hpp"

using namespace std;

// Helper function to display the menu
void printMenu() {
    cout << "\n===================================" << endl;
    cout << "    SMART HOME CONTROL SYSTEM" << endl;
    cout << "===================================" << endl;
    cout << "1. Add Device" << endl;
    cout << "2. Remove Device (by ID)" << endl;
    cout << "3. Toggle Device ON/OFF (by ID)" << endl;
    cout << "4. List All Devices" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
}

int main() {
    SmartHomeController controller;
    int choice;

    // Adding initial devices for testing purposes
    controller.addDevice(new Light(false, "LivingRoom_Light", 0));
    controller.addDevice(new Thermostat(true, "Main_Thermostat", 24.0));

    while (true) {
        printMenu();

        // Input validation: Check if user entered a non-integer
        if (!(cin >> choice)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "ERROR: Please enter a valid number!" << endl;
            continue;
        }

        if (choice == 0) {
            cout << "Shutting down the system. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1: { // Add Device
                int type;
                string name;
                cout << "\n[SELECT TYPE] -> 1: Light | 2: Fan | 3: Thermostat" << endl;
                cout << "Selection: ";
                cin >> type;
                cout << "Enter a name for the device (No spaces): ";
                cin >> name;

                if (type == 1)
                    controller.addDevice(new Light(false, name, 100));
                else if (type == 2)
                    controller.addDevice(new Fan(false, name, 1));
                else if (type == 3)
                    controller.addDevice(new Thermostat(false, name, 22.5));
                else
                    cout << "Invalid type selection!" << endl;

                cout << "-> Device added successfully." << endl;
                break;
            }
            case 2: { // Remove Device
                int id;
                controller.showAllStatuses(); // Show list first so user knows the ID
                cout << "\nEnter the ID of the device to remove: ";
                cin >> id;
                controller.removeDevice(id);
                cout << "-> Process completed (Device removed if ID was correct)." << endl;
                break;
            }
            case 3: { // Toggle Device
                int id;
                controller.showAllStatuses();
                cout << "\nEnter the ID of the device to toggle: ";
                cin >> id;
                controller.turnDevice(id);
                cout << "-> Device state toggled." << endl;
                break;
            }
            case 4: // List Devices
                controller.showAllStatuses();
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
