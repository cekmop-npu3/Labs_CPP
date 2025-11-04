#ifndef ELECTRONIC_CLOCK_H
#define ELECTRONIC_CLOCK_H

#include "clock.hpp"
#include <ostream>

class ElectronicClock : public Clock {
    protected:
        int batteryLife;
        bool hasBacklight;

    public:
        explicit ElectronicClock(const std::string& brand = "Unknown", 
                double price = 0.0, 
                int weight = 0,
                int batteryLife = 24,
                bool hasBacklight = false);

        int getBatteryLife() const;
        bool getHasBacklight() const;

        void setBatteryLife(int life);
        void setHasBacklight(bool backlight);

        void displayTime() const override;
        void checkBattery() const override;
        void toggleBacklight() const;
        std::string getType() const override;
        void printInfo(std::ostream& os = std::cout, bool cr = false) const override;
};

std::ostream& operator<<(std::ostream& os, const ElectronicClock& electronic_clock);

#endif

