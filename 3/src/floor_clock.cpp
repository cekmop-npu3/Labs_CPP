#include "floor_clock.hpp"
#include "mechanical_clock.hpp"
#include <iostream>
#include <ostream>


FloorClock::FloorClock(const std::string& brand, double price, 
                                 int weight, int powerReserve, bool isAutomatic,
                                 int height, bool chimesEnabled)
    : MechanicalClock(brand, price, weight, powerReserve, isAutomatic),
      height(height), chimesEnabled(chimesEnabled) {}

int FloorClock::getHeight() const { return height; }
bool FloorClock::getChimesEnabled() const { return chimesEnabled; }

void FloorClock::setHeight(int newHeight) { height = newHeight; }
void FloorClock::setChimesEnabled(bool enabled) { chimesEnabled = enabled; }

void FloorClock::displayTime() const {
    std::cout << "Large analog dial of grandfather clock" << std::endl;
}

void FloorClock::playChimes() const {
    if (chimesEnabled) {
        std::cout << "Playing chimes..." << std::endl;
    } else {
        std::cout << "Chimes disabled" << std::endl;
    }
}

void FloorClock::adjustPendulum() const {
    std::cout << "Adjusting pendulum..." << std::endl;
}

std::string FloorClock::getType() const {
    return "Floor Clock";
}

void FloorClock::printInfo(std::ostream& os, bool cr) const {
    MechanicalClock::printInfo(os, false);
    os << "height: " << height << ", chimes: " << (chimesEnabled ? "Enabled" : "Disabled") << (cr ? "}" : ", ");
}

std::ostream& operator<<(std::ostream& os, const FloorClock& floor_clock){
    floor_clock.printInfo();
    return os;
}
