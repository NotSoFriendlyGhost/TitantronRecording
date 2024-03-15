#include "autons.hpp"
#include "globals.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include "recording.hpp"

void leftScore(){
    drive.driveInches(36);
    drive.brakeAll();
    pros::delay(20);
    drive.turnDegrees(90);
    drive.brakeAll();
    pros::delay(20);
    intake.move_voltage(12000);
    drive.driveInches(24);
    drive.brakeAll();
    intake.move_voltage(-12000);
}

void leftWP(){
}

void rightScore(){
    drive.driveInches(36);
    drive.turnDegrees(90);
    intake.move_voltage(12000);
    drive.driveInches(24);
    intake.move_voltage(-12000);
}

void rightWP(){

}

void replay(){
    playback("recording.txt");
}

void skills(){

}