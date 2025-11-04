#include "clock.hpp"
#include <iostream>
#include <ostream>


Clock::Clock(const std::string& brand, double price, int weight)
    : brand(brand), price(price), weight(weight) {}

std::string Clock::getBrand() const { return brand; }
double Clock::getPrice() const { return price; }
int Clock::getWeight() const { return weight; }

void Clock::setBrand(const std::string& newBrand) { brand = newBrand; }
void Clock::setPrice(double newPrice) { price = newPrice; }
void Clock::setWeight(int newWeight) { weight = newWeight; }

void Clock::displayTime() const {
    std::cout << "Showing time..." << std::endl;
}

void Clock::checkBattery() const {
    std::cout << "Checking power source..." << std::endl;
}

std::string Clock::getType() const {
    return "Regular Clock";
}

void Clock::printInfo(std::ostream& os, bool cr) const {
    os << "{type: " << getType() << ", brand: " << brand << ", price: " << price << "weight: " << weight << (cr ? "}" : ", ");
}

std::ostream& operator<<(std::ostream& os, const Clock& clock){
    clock.printInfo(os);
    return os;
}

