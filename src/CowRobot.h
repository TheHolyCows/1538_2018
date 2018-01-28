//==================================================
// Copyright (C) 2018 Team 1538 / The Holy Cows
//==================================================

#ifndef __COW_ROBOT_H__
#define __COW_ROBOT_H__

#include <CowLib/CowLogger.h>
#include <WPILib.h>
#include "Controllers/GenericController.h"
#include "CowLib/CowLib.h"
#include "CowControlBoard.h"
#include "CounterBase.h"
#include "CowConstants.h"
#include "CowLib/CowAlphaNum.h"
#include "CowGyro.h"
#include "CowLib/CowMotorController.h"

class CowRobot
{
private:
    int m_DSUpdateCount;
    
    GenericController *m_Controller;
    
    // Drive Motors
    CowLib::CowMotorController *m_LeftDriveA;
    CowLib::CowMotorController *m_LeftDriveB;
    CowLib::CowMotorController *m_LeftDriveC;

    CowLib::CowMotorController *m_RightDriveA;
    CowLib::CowMotorController *m_RightDriveB;
    CowLib::CowMotorController *m_RightDriveC;
    
    CowLib::CowGyro *m_Gyro;
    Encoder *m_DriveEncoder;
    Encoder *m_DriveEncoderLeft;
    Encoder *m_DriveEncoderRight;

    PowerDistributionPanel *m_PowerDistributionPanel;

    CowLib::CowAlphaNum *m_LEDDisplay;
    CowLib::CowLogger *m_WebServer;

    float m_LeftDriveValue;
    float m_RightDriveValue;

    double m_PreviousGyroError;
    double m_PreviousDriveError;

    double m_MatchTime;
    double m_StartTime;

    void SetLeftMotors(float val);
    void SetRightMotors(float val);

public:
    CowRobot();
    void Reset();
    void GyroHandleCalibration();
    void GyroFinalizeCalibration();
    void SetController(GenericController *controller);
    void PrintToDS();
    double GetDriveDistance();
    bool DriveDistance(double distance);
    bool DriveDistanceWithHeading(double heading, double distance, double speed);
    bool DriveWithHeading(double heading, double speed);
    bool DriveWithHeading(double heading, double speed, double maxSpeed);
    void DriveSpeedTurn(float speed, float turn, bool quickTurn);
    void DriveLeftRight(float leftDriveValue, float rightDriveValue);
    bool TurnToHeading(double heading);
    void QuickTurn(float turn);
    
    void StartTime();

    CowLib::CowAlphaNum *GetDisplay()
    {
        return m_LEDDisplay;
    }

    PowerDistributionPanel *GetPowerDistributionPanel()
    {
        return m_PowerDistributionPanel;
    }

    CowLib::CowGyro *GetGyro()
    {
        return CowLib::CowGyro::GetInstance();
    }

    Encoder *GetEncoder()
    {
        return m_DriveEncoder;
    }

    void UseLeftEncoder()
    {
        m_DriveEncoder = m_DriveEncoderLeft;
    }

    void UseRightEncoder()
    {
        m_DriveEncoder = m_DriveEncoderRight;
    }

    void ResetEncoders()
    {
        m_DriveEncoderLeft->Reset();
        m_DriveEncoderRight->Reset();
    }

    void handle();
};

#endif
