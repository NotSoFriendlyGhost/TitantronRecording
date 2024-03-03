#pragma once

#include <cmath>

double leftCurveScale = 0;
double rightCurveScale = 0;

double opcontrolLeftCurve(double stickInput) {
  if (leftCurveScale != 0) {
    return tan((M_PI/4)*pow(abs(stickInput)/127,leftCurveScale))*stickInput;
  }
  return stickInput;
}

double opcontrolRightCurve(double stickInput) {
  if (rightCurveScale != 0) {
    return tan((M_PI/4)*pow(abs(stickInput)/127,rightCurveScale))*stickInput;
  }
  return stickInput;
}