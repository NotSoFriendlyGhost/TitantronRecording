#include "main.h"

pros::Motor leftFront(1,pros::E_MOTOR_GEAR_GREEN,true);
pros::Motor leftBack(12,pros::E_MOTOR_GEAR_GREEN, true);
pros::Motor rightFront(10, pros::E_MOTOR_GEAR_GREEN);
pros::Motor rightBack(18, pros::E_MOTOR_GEAR_GREEN);

pros::Motor intake(5);
pros::Motor flywheel(15, pros::E_MOTOR_GEAR_BLUE, true);
pros::ADIDigitalOut wings('A', false);

pros::Controller master (CONTROLLER_MASTER);
pros::Imu imu(8);

float flywheelVelocity = 0.5;
bool wingState = 0;

// TODO: Lifter setup - wait for lifter build