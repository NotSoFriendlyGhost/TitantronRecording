#include "main.h"

void resetDriveEncoders(){
    leftFront.tare_position();
    leftBack.tare_position();
    rightFront.tare_position();
    rightBack.tare_position();
}