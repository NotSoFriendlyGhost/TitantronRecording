#include "globals.hpp"
#include "main.h"
#include "pros/vision.h"
#include "pros/vision.hpp"
#include <fstream>


Drivetrain drive(-1,-12,10,18, 3.25);

pros::Motor intake(2);
pros::Motor flywheel(15, pros::E_MOTOR_GEAR_BLUE, true);
pros::ADIDigitalOut wings('A', false);

pros::Controller master (CONTROLLER_MASTER);
pros::Imu imu(13);

float flywheelVelocity = 0.5;
bool wingState = 0;

std::ofstream ofs; //Used for recording
bool recording = false;

pros::Vision vision(8,pros::E_VISION_ZERO_CENTER);
pros::vision_signature_s_t greenTriball = pros::c::vision_signature_from_utility(1, -6151, -4923, -5536, -6821, -5653, -6238, 7.300, 0);

// TODO: Lifter setup - wait for lifter build