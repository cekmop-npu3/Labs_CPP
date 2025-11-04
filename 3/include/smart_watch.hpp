#ifndef SMART_WATCH_H
#define SMART_WATCH_H

#include "electronic_clock.hpp"
#include <ostream>


class SmartWatch : public ElectronicClock {
    private:
        int heartRateMonitor;
        bool gpsEnabled;
        int stepCounter;

    public:
        explicit SmartWatch(const std::string& brand = "Unknown",
                double price = 0.0,
                int weight = 0,
                int batteryLife = 24,
                bool hasBacklight = true,
                int heartRateMonitor = 0,
                bool gpsEnabled = false,
                int stepCounter = 0);

        int getHeartRateMonitor() const;
        bool getGpsEnabled() const;
        int getStepCounter() const;

        void setHeartRateMonitor(int rate);
        void setGpsEnabled(bool enabled);
        void setStepCounter(int steps);

        void displayTime() const override;
        void measureHeartRate() const;
        void trackActivity() const;
        void receiveNotification(const std::string& message) const;
        std::string getType() const override;
        void printInfo(std::ostream& os = std::cout, bool cr = true) const override;
};

#endif

