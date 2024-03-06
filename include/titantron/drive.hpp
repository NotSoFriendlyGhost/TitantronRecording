#pragma once

#include "main.h"
#include "pros/motors.hpp"

class Drivetrain{
    private:
        pros::Motor leftFront;
        pros::Motor leftBack;
        pros::Motor rightFront;
        pros::Motor rightBack;  
    public:
        Drivetrain(){
            pros::Motor leftFront(1);
            pros::Motor leftBack(10);
            pros::Motor rightFront(11);
            pros::Motor rightBack(20);
        }
        void resetDriveEncoders();
};
