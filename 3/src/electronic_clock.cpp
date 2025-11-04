#include "electronic_clock.hpp"
#include <iostream>
#include <ostream>


ElectronicClock::ElectronicClock(const std::string& brand, double price, 
                               int weight, int batteryLife, bool hasBacklight)
    : Clock(brand, price, weight), batteryLife(batteryLife), hasBacklight(hasBacklight) {}

int ElectronicClock::getBatteryLife() const { return batteryLife; }
bool ElectronicClock::getHasBacklight() const { return hasBacklight; }

void ElectronicClock::setBatteryLife(int life) { batteryLife = life; }
void ElectronicClock::setHasBacklight(bool backlight) { hasBacklight = backlight; }

void ElectronicClock::displayTime() const {
    std::cout << "Digital display: 12:45" << std::endl;
}

void ElectronicClock::checkBattery() const {
    std::cout << "Battery remaining: " << batteryLife << " hours" << std::endl;
}

void ElectronicClock::toggleBacklight() const {
    if (hasBacklight) {
        std::cout << "Backlight " << (hasBacklight ? "enabled" : "disabled") << std::endl;
    } else {
        std::cout << "Backlight not supported" << std::endl;
    }
}

std::string ElectronicClock::getType() const {
    return "Electronic Clock";
}

void ElectronicClock::printInfo(std::ostream& os, bool cr) const {
    Clock::printInfo(os, false);
    os << "battery_life: " << batteryLife << ", backlight: " << (hasBacklight ? "Yes" : "No") << (cr ? "}" : ", ");
}

std::ostream& operator<<(std::ostream& os, const ElectronicClock& electronic_clock){
    electronic_clock.printInfo(os);
    return os;
}

