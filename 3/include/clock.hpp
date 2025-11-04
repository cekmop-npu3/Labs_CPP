#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <ostream>
#include <string>


class Clock {
    protected:
        std::string brand;
        double price;
        int weight;

    public:
        explicit Clock(const std::string& brand = "Unknown", double price = 0.0, int weight = 0);
        virtual ~Clock() = default;

        std::string getBrand() const;
        double getPrice() const;
        int getWeight() const;

        void setBrand(const std::string& newBrand);
        void setPrice(double newPrice);
        void setWeight(int newWeight);

        virtual void displayTime() const;
        virtual void checkBattery() const;
        virtual std::string getType() const;
        virtual void printInfo(std::ostream& os = std::cout, bool cr = true) const;
};

std::ostream& operator<<(std::ostream& os, const Clock& clock);

#endif

