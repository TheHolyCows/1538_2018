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
        //bot->TurnToHeading(90);
        bot->DriveDistanceWithHeading(0, 12, 0.5);
    }
    else
    {
        bot->DriveSpeedTurn(m_CB->GetDriveStickY(),
                            m_CB->GetSteeringX(),
                            m_CB->GetSteeringButton(FAST_TURN));
    }

    if(m_CB->GetOperatorButton(8))
    {
    	bot->GetArm()->SetPosition(CONSTANT("ARM_DOWN"));
    }
    else
    {
    	bot->GetArm()->SetPosition(CONSTANT("ARM_UP"));
    }

    if(m_CB->GetOperatorButton(7))
    {
    	bot->GetIntake()->SetSpeed(1);
    }
    else if(m_CB->GetOperatorButton(4))
    {
    	bot->GetIntake()->SetSpeed(-1);
    }
    else
    {
    	bot->GetIntake()->SetSpeed(0);
    }


}

