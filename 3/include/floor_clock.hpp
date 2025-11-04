#ifndef FLOOR_CLOCK_H
#define FLOOR_CLOCK_H

#include "mechanical_clock.hpp"
#include <ostream>


class FloorClock : public MechanicalClock {
    private:
        int height;
        bool chimesEnabled;

    public:
        explicit FloorClock(const std::string& brand = "Unknown",
                double price = 0.0,
                int weight = 0,
                int powerReserve = 168,
                bool isAutomatic = false,
                int height = 200,
                bool chimesEnabled = true);

        int getHeight() const;
        bool getChimesEnabled() const;

        void setHeight(int newHeight);
        void setChimesEnabled(bool enabled);

        void displayTime() const override;
        void playChimes() const;
        void adjustPendulum() const;
        std::string getType() const override;
        void printInfo(std::ostream& os = std::cout, bool cr = true) const override;
};

std::ostream& operator<<(std::ostream& os, const FloorClock& floor_clock);

#endif

