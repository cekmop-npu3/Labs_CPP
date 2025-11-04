#ifndef MECHANICAL_CLOCK_H
#define MECHANICAL_CLOCK_H

#include "clock.hpp"
#include <ostream>

class MechanicalClock : public Clock {
    protected:
        int powerReserve;
        bool isAutomatic;

    public:
        explicit MechanicalClock(const std::string& brand = "Unknown",
                double price = 0.0,
                int weight = 0,
                int powerReserve = 48,
                bool isAutomatic = false);

        int getPowerReserve() const;
        bool getIsAutomatic() const;

        void setPowerReserve(int reserve);
        void setIsAutomatic(bool automatic);

        void displayTime() const override;
        void checkBattery() const override;
        void windUp() const;
        std::string getType() const override;
        void printInfo(std::ostream& os = std::cout, bool cr = true) const override;
};

#endif

