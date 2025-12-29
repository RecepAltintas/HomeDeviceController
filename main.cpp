#include <iostream>
#include "SmartHomeController.hpp"
#include "Light.hpp"
#include "Fan.hpp"
#include "Thermostat.hpp"

using namespace std;

int main() {

    SmartHomeController controller;

    controller.addDevice(new Light(true, "Salon Lambasi", 80));
    controller.addDevice(new Fan(false, "Tavan Pervanesi", 3));
    controller.addDevice(new Thermostat(true, "Ana Termostat", 24.5));

    controller.showAllStatuses();

    cout << "\n[Islem] ID 100 durumu degistiriliyor..." << endl;
    controller.turnDevice(100);

    controller.showAllStatuses();

    cout << "\n[Islem] ID 101 siliniyor..." << endl;
    controller.removeDevice(101);

    controller.showAllStatuses();

    return 0;
}