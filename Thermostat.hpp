#ifndef SMARTHOME_THERMOSTAT_HPP
#define SMARTHOME_THERMOSTAT_HPP

#include <iostream>
#include <random>
#include "SmartDevice.hpp"
class Thermostat : public SmartDevice {
private:
    double ambientTemperature;

public:
    explicit Thermostat(bool IsOn, std::string name, double ambientTemperature = 25)
            : SmartDevice(IsOn, std::move(name)) {
        this->ambientTemperature = ambientTemperature;
    }

    ~Thermostat() override = default;

    void showStatus() override {
        std::cout << "ID: " << id << " | " << name
                  << " | Status: " << (IsOn ? "ON" : "OFF")
                  << " | Temp: " << ambientTemperature << " C" << std::endl;
    }

    void turnDevices() override {
        IsOn = !IsOn;
    }
    SmartDevice* CreateNewDevice(std::string tempName) override{
        return new Thermostat(false,tempName,0);
    }

};

#endif //SMARTHOME_THERMOSTAT_HPP