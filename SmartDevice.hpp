
#ifndef DEVICES_SmartDevice_HPP
#define DEVICES_SmartDevice_HPP
#include<iostream>
#include <utility>
class SmartDevice{
protected:
    bool IsOn;
    int id;
    std::string name;

    inline static int IdCounter = 100;
public:
    SmartDevice(bool IsOn, std::string name){
        this->IsOn= IsOn;
        this->id = IdCounter++;
        this->name = std::move(name);

    } virtual ~SmartDevice()= default;
    virtual void showStatus() = 0;
    virtual void turnDevices() = 0;
    virtual SmartDevice* CreateNewDevice(std::string tempName) = 0;
    int getID() const {return id;}
    };

#endif // Devices_SmartDevice_HPP
