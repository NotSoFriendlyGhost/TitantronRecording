#pragma once

#include "main.h"

class Drivetrain{
    private:
        pros::Motor* leftFront;
        pros::Motor* leftBack;
        pros::Motor* rightFront;
        pros::Motor* rightBack;  
        double kP, kI, kD;
        double gearRatio;
        double wheelCircumference;
        double calcDegrees(double inches);
        void drivePID(double encoderDegrees);
        void driveAll(double power);
    public:
        /**
         *
         * Sets up four motor drive train by inputting port numbers. Entering a negative number reverses the motor.
         *
         */
        Drivetrain(int leftA, int leftB, int rightA, int rightB, double wheelDiameter);

        void setGearRatio(double drivenGear, double drivingGear);
        void setPID(double p, double i, double d);
        void resetDriveEncoders();
        void arcadeDrive();
        void playbackDrive(double leftStick, double rightStick);
        void setBrakeMode(pros::motor_brake_mode_e brakeMode);
        void brakeAll();
        void driveInches(double inches);
};
