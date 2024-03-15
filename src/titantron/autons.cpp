#include "autons.hpp"
#include "globals.hpp"
#include "main.h"
#include "recording.hpp"

void leftScore(){
    drive.driveInches(36);
    drive.brakeAll();
    drive.turnDegrees(90);
    drive.brakeAll();
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