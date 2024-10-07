#include "./monitor.h"
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

constexpr float MAX_TEMPERATURE = 102;
constexpr float MIN_TEMPERATURE = 95;
constexpr float MAX_PULSE_RATE = 100;
constexpr float MIN_PULSE_RATE = 60;
constexpr float MIN_SPO2 = 90;
constexpr float MAX_SPO2 = 100;

void printWarningGraphics() {
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

void printWarning(const char* vitalName) {
    cout << vitalName << " is out of range!\n";
    printWarningGraphics();
}

bool checkVitals(const char* vitalName, float value, float min, float max) {
    if (value < min || value > max) {
        printWarning(vitalName);
        return false;
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool tempStatus = checkVitals("Temperature", temperature, MIN_TEMPERATURE, MAX_TEMPERATURE);
    bool pulseRateStatus = checkVitals("Pulse Rate", pulseRate, MIN_PULSE_RATE, MAX_PULSE_RATE);
    bool spo2Status = checkVitals("Oxygen Saturation", spo2, MIN_SPO2, MAX_SPO2);

    return tempStatus && pulseRateStatus && spo2Status;
}
