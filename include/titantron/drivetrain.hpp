#pragma once

#include "main.h"

class Drivetrain{
    private:
        pros::Motor* leftFront;
        pros::Motor* leftBack;
        pros::Motor* rightFront;
        pros::Motor* rightBack;  
        double kP, kI, kD;
    public:
        Drivetrain(int leftA, int leftB, int rightA, int rightB);
        void setPID(double p, double i, double d);
        void resetDriveEncoders();
        void arcadeDrive();
        void setBrakeMode(pros::motor_brake_mode_e brakeMode);
        void driveForwardPID(double encoderDegrees);
        void driveBackward();
        void driveForwardPID();
};
