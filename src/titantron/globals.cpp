#include "main.h"


Drivetrain drive(-1,-12,10,18);

pros::Motor intake(2);
pros::Motor flywheel(15, pros::E_MOTOR_GEAR_BLUE, true);
pros::ADIDigitalOut wings('A', false);

pros::Controller master (CONTROLLER_MASTER);
pros::Imu imu(8);

float flywheelVelocity = 0.5;
bool wingState = 0;

// TODO: Lifter setup - wait for lifter build