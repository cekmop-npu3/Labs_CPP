#ifndef WRISTWATCH_H
#define WRISTWATCH_H

#include "mechanical_clock.hpp"
#include <ostream>


class Wristwatch : public MechanicalClock {
    private:
        bool waterproof;
        std::string strapMaterial;

    public:
        explicit Wristwatch(const std::string& brand = "Unknown",
                double price = 0.0,
                int weight = 0,
                int powerReserve = 48,
                bool isAutomatic = true,
                bool waterproof = false,
                const std::string& strapMaterial = "Leather");

        bool getWaterproof() const;
        std::string getStrapMaterial() const;

        void setWaterproof(bool proof);
        void setStrapMaterial(const std::string& material);

        void displayTime() const override;
        void checkWaterResistance() const;
        void changeStrap() const;
        std::string getType() const override;
        void printInfo(std::ostream& os = std::cout, bool cr = true) const override;
};

#endif

