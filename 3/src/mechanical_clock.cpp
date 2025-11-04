#include "mechanical_clock.hpp"
#include "clock.hpp"
#include <iostream>
#include <ostream>


MechanicalClock::MechanicalClock(const std::string& brand, double price,
                               int weight, int powerReserve, bool isAutomatic)
    : Clock(brand, price, weight), powerReserve(powerReserve), isAutomatic(isAutomatic) {}

int MechanicalClock::getPowerReserve() const { return powerReserve; }
bool MechanicalClock::getIsAutomatic() const { return isAutomatic; }

void MechanicalClock::setPowerReserve(int reserve) { powerReserve = reserve; }
void MechanicalClock::setIsAutomatic(bool automatic) { isAutomatic = automatic; }

void MechanicalClock::displayTime() const {
    std::cout << "Analog dial: showing time" << std::endl;
}

void MechanicalClock::checkBattery() const {
    std::cout << "Power reserve: " << powerReserve << " hours" << std::endl;
}

void MechanicalClock::windUp() const {
    if (isAutomatic) {
        std::cout << "Automatic winding - no manual winding needed" << std::endl;
    } else {
        std::cout << "Wound up!" << std::endl;
    }
}

std::string MechanicalClock::getType() const {
    return "Mechanical Clock";
}

void MechanicalClock::printInfo(std::ostream& os, bool cr) const {
    Clock::printInfo(os, false);
    os << "power_reserve: " << powerReserve << " hours" << ", mechanism_type: " << (isAutomatic ? "Automatic" : "Manual") << (cr ? "}" : ", ");
}

std::ostream& operator<<(std::ostream& os, const MechanicalClock& mechanical_clock){
    mechanical_clock.printInfo();
    return os;
}
