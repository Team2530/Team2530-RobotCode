#include "Arm.h"
#include "WPILib.h"
Arm::Arm() {
	raiseArm = new Jaguar(9);  //Creat jag arm motor
	xboxController = new Joystick(2);
	joystick = new Joystick(1);
}
void Arm::RaiseArm() {
	automatic = false;
	raiseArm->SetSpeed(1);
}
void Arm::LowerArm() {
	automatic = false;
	raiseArm->SetSpeed(-1);
}
//For automatically lowering and raising the arm all the way to the top/bottom on the press of a button

void Arm::AutoArm() {

	if (xboxController->GetRawButton(3)) {
		raiseArm->SetSpeed(1);
		automatic = true;
	}
	if (xboxController->GetRawButton(4)) {
		raiseArm->SetSpeed(-1);
		automatic = true;
	}
}


void Arm::OperateArm() {
	AutoArm();
	if ((xboxController->GetRawAxis(5) >= 0.5) || (joystick->GetRawAxis(6) >= 0.5))
		RaiseArm();
	else if ((xboxController->GetRawAxis(5) <= -0.5) || (joystick->GetRawAxis(6) <= -0.5))
		LowerArm();
	else if (!automatic)
		raiseArm->SetSpeed(0);
}

void Arm::StopArm() {
	raiseArm->SetSpeed(0);
}

