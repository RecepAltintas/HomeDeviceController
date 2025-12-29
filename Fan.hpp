#ifndef DEVICES_FAN_HPP
#define DEVICES_FAN_HPP

#include <iostream>
#include "SmartDevice.hpp"

class Fan : public SmartDevice {
private:
    int fanLevel;

public:
    Fan(bool isOn, std::string name, int fanLevel = 1)
            : SmartDevice(isOn, std::move(name)) {
        this->fanLevel = fanLevel;
    }

    void showStatus() override {
        std::cout << "ID: " << id << " | " << name
                  << " | Status: " << (IsOn ? "ON" : "OFF")
                  << " | Fan Level: " << fanLevel << std::endl;
    }

    void turnDevices() override {
        IsOn = !IsOn;
    }
    SmartDevice* CreateNewDevice(std::string tempName) override{
        return new Fan(false,tempName,0);
    }

};

#endif // DEVICES_FAN_HPP