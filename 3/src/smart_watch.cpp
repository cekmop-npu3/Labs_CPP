#include "smart_watch.hpp"
#include "electronic_clock.hpp"
#include <iostream>
#include <ostream>


SmartWatch::SmartWatch(const std::string& brand, double price, int weight,
                     int batteryLife, bool hasBacklight, int heartRateMonitor,
                     bool gpsEnabled, int stepCounter)
    : ElectronicClock(brand, price, weight, batteryLife, hasBacklight),
      heartRateMonitor(heartRateMonitor), gpsEnabled(gpsEnabled), stepCounter(stepCounter) {}

int SmartWatch::getHeartRateMonitor() const { return heartRateMonitor; }
bool SmartWatch::getGpsEnabled() const { return gpsEnabled; }
int SmartWatch::getStepCounter() const { return stepCounter; }

void SmartWatch::setHeartRateMonitor(int rate) { heartRateMonitor = rate; }
void SmartWatch::setGpsEnabled(bool enabled) { gpsEnabled = enabled; }
void SmartWatch::setStepCounter(int steps) { stepCounter = steps; }

void SmartWatch::displayTime() const {
    std::cout << "Smartwatch touch display: 12:45" << std::endl;
}

void SmartWatch::measureHeartRate() const {
    if (heartRateMonitor > 0) {
        std::cout << "Heart rate: " << heartRateMonitor << " bpm" << std::endl;
    } else {
        std::cout << "Heart monitor not active" << std::endl;
    }
}

void SmartWatch::trackActivity() const {
    std::cout << "Steps taken: " << stepCounter << std::endl;
    if (gpsEnabled) {
        std::cout << "GPS tracking active" << std::endl;
    }
}

void SmartWatch::receiveNotification(const std::string& message) const {
    std::cout << "Notification: " << message << std::endl;
}

std::string SmartWatch::getType() const {
    return "Smart Watch";
}

void SmartWatch::printInfo(std::ostream& os, bool cr) const {
    ElectronicClock::printInfo(os, false);
    os << "heart_rate_monitor: " << (heartRateMonitor > 0 ? "Yes" : "No") << ", GPS: " << (gpsEnabled ? "Enabled" : "Disabled") << ", step_counter: " << stepCounter << (cr ? "}" : ", ");
}

std::ostream& operator<<(std::ostream& os, const SmartWatch& smart_watch){
    smart_watch.printInfo();
    return os;
}

