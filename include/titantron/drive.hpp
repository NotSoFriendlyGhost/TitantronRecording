#pragma once

#include "main.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

class Drivetrain{
    private:
        pros::Motor* leftFront;
        pros::Motor* leftBack;
        pros::Motor* rightFront;
        pros::Motor* rightBack;  
    public:
        Drivetrain(int leftA, int leftB, int rightA, int rightB);
        void resetDriveEncoders();
        void arcadeDrive();
        void setBrakeMode(pros::motor_brake_mode_e brakeMode);
};
