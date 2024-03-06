#include "drive.hpp"
#include "main.h"

void Drivetrain::resetDriveEncoders(){
    this->leftFront.tare_position();
    this->leftBack.tare_position();
    this->rightFront.tare_position();
    this->rightBack.tare_position();
}