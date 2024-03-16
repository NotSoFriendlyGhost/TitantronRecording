#include "main.h"
#include "pros/vision.h"
#include "pros/vision.hpp"
#include <cmath>
#include <fstream>


Drivetrain drive(-1,-11,10,20, 3.25);

pros::Motor intake(2);
pros::Motor flywheel(3, pros::E_MOTOR_GEAR_BLUE, true);
pros::ADIDigitalOut wings('A', false);

pros::Controller master (CONTROLLER_MASTER);
pros::Imu imu(13);

float flywheelVelocity = 0.5;
bool wingState = 0;

std::ofstream ofs; //Used for recording
bool recording = false;

pros::Vision vision(8,pros::E_VISION_ZERO_CENTER);

int tileLength = 24; // Length of a tile in inches
double diagTileLength = sqrt(pow(tileLength,2) + pow(tileLength,2)); // Length to travel diagonally across a tile in inches

// TODO: Lifter setup - wait for lifter build