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

bool checkVitals(float value, float min, float max) {
    return value < min || value > max;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (checkVitals(temperature, MIN_TEMPERATURE, MAX_TEMPERATURE)) {
        printWarning("Temperature");
        return 0;
    }

    if (checkVitals(pulseRate, MIN_PULSE_RATE, MAX_PULSE_RATE)) {
        printWarning("Pulse Rate");
        return 0;
    }

    if (checkVitals(spo2, MIN_SPO2, MAX_SPO2)) {
        printWarning("Oxygen Saturation");
        return 0;
    }

    return 1;
}
