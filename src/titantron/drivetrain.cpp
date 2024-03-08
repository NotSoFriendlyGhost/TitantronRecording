#include "drivetrain.hpp"
#include "main.h"
#include "pros/rtos.hpp"

/**
 *
 * Sets up four motor drive train by inputting port numbers. Entering a negative number reverses the motor.
 *
*/
Drivetrain::Drivetrain(int leftA, int leftB, int rightA, int rightB){
    bool reversed;
    reversed = (leftA<0);
    leftFront = new pros::Motor(leftA,pros::E_MOTOR_GEAR_GREEN,reversed,pros::E_MOTOR_ENCODER_DEGREES);
    reversed = (leftB<0);
    leftBack = new pros::Motor(leftB,pros::E_MOTOR_GEAR_GREEN,reversed,pros::E_MOTOR_ENCODER_DEGREES);
    reversed = (rightA<0);
    rightFront = new pros::Motor(rightA,pros::E_MOTOR_GEAR_GREEN,reversed,pros::E_MOTOR_ENCODER_DEGREES);
    reversed = (rightB<0);
    rightBack = new pros::Motor(rightB,pros::E_MOTOR_GEAR_GREEN,reversed,pros::E_MOTOR_ENCODER_DEGREES);
}

void Drivetrain::setPID(double p, double i, double d){
    kP = p;
    kI = i;
    kD = d;
}

void Drivetrain::resetDriveEncoders(){
    leftFront->tare_position();
    leftBack->tare_position();
    rightBack->tare_position();
    rightFront->tare_position();
};

void Drivetrain::arcadeDrive(){
    int power = master.get_analog(ANALOG_LEFT_Y);
    power = opcontrolLeftCurve(power);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    turn = opcontrolRightCurve(turn);
    int left = power + turn;
    int right = power - turn;
    leftFront->move(left);
    leftBack->move(left);
    rightFront->move(right);
    rightBack->move(right);
}

void Drivetrain::setBrakeMode(pros::motor_brake_mode_e brakeMode){
    leftFront->set_brake_mode(brakeMode);
    leftBack->set_brake_mode(brakeMode);
    rightFront->set_brake_mode(brakeMode);
    rightBack->set_brake_mode(brakeMode);
}

void Drivetrain::brakeAll(){
    leftFront->brake();
    leftBack->brake();
    rightFront->brake();
    rightBack->brake();
}

void Drivetrain::driveAll(double power){
    leftFront->move_voltage(power);
    leftBack->move_voltage(power);
    rightFront->move_voltage(power);
    rightBack->move_voltage(power);
}

void Drivetrain::driveForwardPID(double desiredPoint){
    resetDriveEncoders();
    double error = 100;
    double prevError = 0;
    double integral = 0;
    double derivative;
    bool enablePID = true;
    while(enablePID){
        error = desiredPoint - (leftFront->get_position()+leftBack->get_position()+rightFront->get_position()+rightBack->get_position())/4;
        integral += error;
        derivative = error-prevError;
        prevError = error;
        
        double power = error*kP + integral * kI + derivative*kD;
        driveAll(power);
        
        pros::delay(20);
    }
    brakeAll();
    
    
    master.clear_line(0);
    pros::delay(1000);
    std::string position = std::to_string(leftFront->get_position());
    
    master.set_text(0,0,position);
    pros::delay(100);
}

void Drivetrain::driveBackward(){
    leftFront->move_relative(-360,100);
    leftBack->move_relative(-360,100);
    rightFront->move_relative(-360,100);
    rightBack->move_relative(-360,100);
}
