#include "wrist_watch.hpp"
#include "mechanical_clock.hpp"
#include <iostream>
#include <ostream>


Wristwatch::Wristwatch(const std::string& brand, double price, int weight,
                     int powerReserve, bool isAutomatic, bool waterproof,
                     const std::string& strapMaterial)
    : MechanicalClock(brand, price, weight, powerReserve, isAutomatic),
      waterproof(waterproof), strapMaterial(strapMaterial) {}

bool Wristwatch::getWaterproof() const { return waterproof; }
std::string Wristwatch::getStrapMaterial() const { return strapMaterial; }

void Wristwatch::setWaterproof(bool proof) { waterproof = proof; }
void Wristwatch::setStrapMaterial(const std::string& material) { strapMaterial = material; }

void Wristwatch::displayTime() const {
    std::cout << "Elegant wristwatch dial" << std::endl;
}

void Wristwatch::checkWaterResistance() const {
    if (waterproof) {
        std::cout << "Watch is waterproof" << std::endl;
    } else {
        std::cout << "Watch is not waterproof" << std::endl;
    }
}

void Wristwatch::changeStrap() const {
    std::cout << "Changing strap to " << strapMaterial << std::endl;
}

std::string Wristwatch::getType() const {
    return "Wristwatch";
}

void Wristwatch::printInfo(std::ostream& os, bool cr) const {
    MechanicalClock::printInfo(os, false);
    os << "waterproof: " << (waterproof ? "Yes" : "No") << ", strap_material: " << strapMaterial << (cr ? "}" : ", ");
}

std::ostream& operator<<(std::ostream& os, const Wristwatch& wrist_watch){
    wrist_watch.printInfo();
    return os;
}
