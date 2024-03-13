#pragma once

#include "main.h" // IWYU pragma: keep

class Drivetrain{
    private:
        pros::Motor* leftFront;
        pros::Motor* leftBack;
        pros::Motor* rightFront;
        pros::Motor* rightBack;  
        double kP, kI, kD;
        double turnkP, turnkI, turnkD;
        double ballTurnkP, ballTurnkI, ballTurnkD;
        double gearRatio;
        double wheelCircumference;
        double calcDegrees(double inches);
        void drivePID(double target);
        void driveAll(double power);
    public:
        /**
         *
         * Sets up four motor drive train by inputting port numbers. Entering a negative number reverses the motor.
         *
         */
        Drivetrain(int leftA, int leftB, int rightA, int rightB, double wheelDiameter);

        void setGearRatio(double drivenGear, double drivingGear);
        void setDrivePID(double p, double i, double d);
        void setTurnPID(double p, double i, double d);
        void setBallTurnPID(double p, double i, double d);
        void resetDriveEncoders();
        void arcadeDrive();
        void playbackDrive(double leftStick, double rightStick);
        void setBrakeMode(pros::motor_brake_mode_e brakeMode);
        void brakeAll();
        void driveInches(double inches);
        void turnDegrees(double target);
        void turnToBall();
};
