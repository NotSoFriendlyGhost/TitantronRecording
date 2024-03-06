#pragma once

#include "main.h"



extern pros::Motor intake;
extern pros::Motor flywheel;
extern pros::ADIDigitalOut wings;

extern pros::Controller master;
extern pros::Imu imu;

extern float flywheelVelocity;
extern bool wingState;