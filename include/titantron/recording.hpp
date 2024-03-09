#pragma once
#include "main.h"
#include <vector>
using std::vector;

class Recording{
    private:
        vector<int> intakeState;
        vector<double> leftStick;
        vector<double> rightStick;
        vector<bool> wingState;
        //vector<double> liftPosition;
    public:
        Recording(std::string filename);
        void trackIntake(int state);
        void trackLeftStick(double value);
        void trackRightStick(double value);
        void trackWings(bool state);
};