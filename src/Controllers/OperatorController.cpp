#include "OperatorController.h"
#include <iostream>

OperatorController::OperatorController(CowControlBoard *controlboard)
    :
    m_CB(controlboard)
{
}

void OperatorController::handle(CowRobot *bot)
{
    if(m_CB->GetDriveButton(1))
    {
        bot->TurnToHeading(90);
        //bot->DriveDistanceWithHeading(0, 12, 0.5);
    }
    else
    {
        bot->DriveSpeedTurn(m_CB->GetDriveStickY(),
                            m_CB->GetSteeringX(),
                            m_CB->GetSteeringButton(FAST_TURN));
    }

    if(m_CB->GetOperatorButton(6))
    {
    		bot->GetArm()->SetPosition(CONSTANT("ARM_DOWN"));

    }
    if(m_CB->GetOperatorButton(9))
    {
    		bot->GetArm()->SetPosition(CONSTANT("ARM_UP"));
    }

    if(m_CB->GetOperatorButton(3))
    {
    		bot->GetArm()->SetPosition(CONSTANT("HUMAN_INTAKE"));
    		bot->GetArm()->SetModulatedSpeed(CONSTANT("INTAKE_SPEED"));
    }

    float armJoystickDeadband = CowLib::Deadband(m_CB->GetOperatorGamepadAxis(1), 0.2);
    float manualArmPosition = bot->GetArm()->GetSetpoint() + (armJoystickDeadband * 28);
    bot->GetArm()->SetPosition(manualArmPosition);

    if(m_CB->GetOperatorButton(5))
    	{
    		if(m_CB->GetOperatorButton(8))
    		{
    			bot->GetArm()->ScoreReverse();
    		}
    		else
    		{
        		bot->GetArm()->ScoreForward();
    		}

    	}

    if(m_CB->GetOperatorButton(4))
    {
    		//Exhaust
    		if(m_CB->GetOperatorButton(10))
    		{
    			bot->GetArm()->SetIntakeSpeed(CONSTANT("INTAKE_EXHAUST_LOW"));
    		}
    		else
    		{
    			bot->GetArm()->SetIntakeSpeed(CONSTANT("INTAKE_EXHAUST"));
    		}
    }
    else if(m_CB->GetOperatorButton(7))
    {
    		//Intake
    		bot->GetArm()->SetModulatedSpeed(CONSTANT("INTAKE_SPEED"));
    }
    else
    {
    		if(bot->GetElevator()->GetDistance() < 40)
    		{
    			bot->GetArm()->SetIntakeSpeed(CONSTANT("STATIC_INTAKE_SPEED"));
    		}
    		else
    		{
    			bot->GetArm()->SetIntakeSpeed(0);
    		}
    }

    //bot->GetElevator()->SetSpeed(m_CB->GetOperatorGamepadAxis(1));

    if(m_CB->GetSteeringButton(4))
    {
    		//do something to go to the scale
    		bot->GetElevator()->SetPosition(CONSTANT("ELEVATOR_SCALE"));
    }
    else if(m_CB->GetSteeringButton(1))
    {
    		//go to switch
    		bot->GetElevator()->SetPosition(CONSTANT("ELEVATOR_SWITCH"));
    }
    else if(m_CB->GetSteeringButton(2))
    	{
    		//go to ground
    		bot->GetElevator()->SetPosition(CONSTANT("ELEVATOR_GROUND"));
    	}


}

