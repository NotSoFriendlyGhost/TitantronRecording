#include "autons.hpp"
#include "globals.hpp"
#include "main.h"
#include "recording.hpp"

void leftScore(){
    drive.driveInches(36);
    drive.brakeAll();
    drive.turnDegrees(90);
    drive.brakeAll();
    intake.move_voltage(12000);
    drive.driveInches(24);
    drive.brakeAll();
    intake.move_voltage(-12000);
}

void leftWP(){
}

void rightScore(){

}

void rightWP(){

}

void replay(){
    playback("recording.txt");
}

void skills(){

}