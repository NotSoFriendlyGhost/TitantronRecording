#pragma once
#include <string>

void startRecording(std::string filename);
void stopRecording();
void trackIntake(short state);
void trackLeftStick(double value);
void trackRightStick(double value);
void trackWings(bool state);