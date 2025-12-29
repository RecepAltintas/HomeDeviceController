#ifndef DEVICES_LIGHT_HPP
#define DEVICES_LIGHT_HPP

#include <iostream>
#include "SmartDevice.hpp"
#include "SmartHomeController.hpp"

class Light : public SmartDevice {
private:
    int brightness;

public:
    Light(bool IsOn, std::string name, int brightness = 100)
            : SmartDevice(IsOn, std::move(name)) {
        this->brightness = brightness;
    }

    void showStatus() override {
        std::cout << "ID: " << id << " | " << name
                  << " | Status: " << (IsOn ? "ON" : "OFF")
                  << " | Brightness: " << brightness << "%" << std::endl;
    }

    void turnDevices() override {
        IsOn = !IsOn;
    }
    SmartDevice* CreateNewDevice(std::string tempName) override{
        return new Light(false,tempName,0);
    }

};

#endif //DEVICES_LIGHT_HPP