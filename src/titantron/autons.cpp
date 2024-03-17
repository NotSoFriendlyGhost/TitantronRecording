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
    imu.set_heading(0);
    drive.swingTurn(90, 1, 0.2);
}

/**
 * Right scoring autonomous
 * Best case scenario: scores 5 triballs
*/
void rightScore(){
    imu.set_heading(-45); // Start touching corner, facing ball on barrier
    intake.move_voltage(12000);
    drive.driveInches(2* diagTileLength); // Drive towards ball, intake, and back up
    drive.driveInches(-diagTileLength / 2);
    drive.turnHeading(90); // Turn to goal
    wings.set_value(1); // Spread wings and push
    drive.driveInches(tileLength * 1.25);
    intake.move_voltage(-12000); // Release ball from intake, bump goal to push balls in
    drive.driveInches(-tileLength * 0.1);
    drive.driveInches(tileLength * 0.1); // 2 balls scored
    wings.set_value(0);
    drive.turnHeading(-95); // Get other barrier triball
    intake.move_voltage(12000);
    drive.driveInches(1.5 * tileLength);
    drive.turnHeading(90); // Drive back to corner
    drive.driveInches(tileLength);
    drive.turnHeading(180);
    drive.driveInches(2*tileLength);
    drive.turnHeading(45); // Face goal
    wings.set_value(1);
    intake.move_voltage(-12000);
    drive.driveInches(0.75 * diagTileLength); // Scoop corner triball out
    drive.turnHeading(10);
    drive.driveInches(tileLength); //Push matchload and triball in goal
    drive.driveInches(-0.1*tileLength); // Back up
}

void rightWP(){

}

void replay(){
    playback("recording.txt");
}

void skills(){

}