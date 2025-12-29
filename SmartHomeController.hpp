#ifndef SMARTHOME_SMARTHOMECONTROLLER_HPP
#define SMARTHOME_SMARTHOMECONTROLLER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "SmartDevice.hpp"
// Diğer include'lar main'de gerekli olacak, burada zorunlu değil ama kalabilir.
#include "Light.hpp"
#include "Fan.hpp"
#include "Thermostat.hpp"

class SmartHomeController {
private:
    std::vector<SmartDevice*> devices;

public:

    ~SmartHomeController() {
        for (auto device : devices) {
            delete device;
        }
        devices.clear();
    }

    void addDevice(SmartDevice* device) {
        devices.push_back(device);
    }

    void removeDevice(int id) {
        auto it = std::remove_if(devices.begin(), devices.end(), [id](SmartDevice* device) {
            if (device->getID() == id) { // SmartDevice sınıfına getId() eklenmeli
                delete device;
                return true;
            }
            return false;
        });
        devices.erase(it, devices.end());
    }

    void turnDevice(int id) {
        for (auto device : devices) {
            if (device->getID() == id) {
                device->turnDevices();
                break;
            }
        }
    }

    void showAllStatuses() const {
        std::cout << "\n--- Home ---" << std::endl;
        for (const auto& device : devices) {
            device->showStatus();
        }
    }
};

#endif //SMARTHOME_SMARTHOMECONTROLLER_HPP