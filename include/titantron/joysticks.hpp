#pragma once

/*
 * @brief Transforms the joystick value for the left joystick
 * 
 * @param stickInput Input from the joystick
 * 
 * @return Returns transformed joystick value
 */
double opcontrolLeftCurve(double stickInput); 

/*
 * @brief Transforms the joystick value for the right joystick
 * 
 * @param stickInput Input from the joystick
 * 
 * @return Returns transformed joystick value
 */
double opcontrolRightCurve(double stickInput); 
