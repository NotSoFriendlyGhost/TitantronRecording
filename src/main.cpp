#include "main.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
	selector::init();
	master.clear();
	pros::delay(60);
	master.set_text(0,0, "Calibrating Intertial...");
	pros::delay(60);
	imu.reset(true);
	master.clear_line(0);
	pros::delay(60);
	master.set_text(0,0,"Inertial Calibrated");
	pros::delay(60);

	drive.setPID(625, 1, 6);
	drive.setGearRatio(3, 5);

	intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	drive.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	switch(selector::auton){
		case 1:
			redLeft();
			break;
		case 2:
			redRight();
			break;
		case -1:
			blueLeft();
			break;
		case -2:
			blueRight();
			break;
		case 0:
			skills();
			break;
		default:
			break;
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	master.set_text(1,0,"Flywheel Velocity: 50%");
	master.print(1, 0, "Flywheel Velocity: 50%");
	drive.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
	while (true) {
		drive.arcadeDrive();
		
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			intake.move_voltage(12000);
			if(recording) trackIntake(1);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
			intake.move_voltage(-12000);
			if(recording) trackIntake(-1);
		}
		else{
			intake.brake();
			if(recording) trackIntake(0);
		}

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
			flywheel.move_velocity(600*flywheelVelocity);
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			flywheel.move_velocity(-600*flywheelVelocity);
		else flywheel.brake();

		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
			if(flywheelVelocity==0.5){
				flywheelVelocity = 0.75;
				master.clear_line(1);
				master.set_text(1,0,"Flywheel Velocity: 75%");
			}
			else{
				flywheelVelocity = 0.5;
				master.clear_line(1);
				master.set_text(1,0,"Flywheel Velocity: 50%");
			}
		}

		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
			wingState = !wingState;
			//if(recording) trackWings(wingState);
		} 
		wings.set_value(wingState);

		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) autonomous();

		if(recording) ofs<<'\n';

		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
			if(!recording){
				master.clear_line(1);
				pros::delay(60);
				master.set_text(1,0,"Recording...");
				pros::delay(60);
				startRecording("recording.txt");
			}
			else {
				stopRecording();
				master.clear_line(1);
				pros::delay(60);
				master.set_text(1,0,"Recording Saved");
				pros::delay(60);
			}
		}
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
			master.clear_line(1);
			pros::delay(60);
			master.set_text(1,0, "Replaying...");
			pros::delay(60);
			playback("recording.txt");
			master.clear_line(1);
			pros::delay(60);
			master.set_text(1,0, "Replay Done");
			pros::delay(60);

		}
	
		pros::delay(2);
	}
}
