#include "CowMotorController.h"

namespace CowLib
{
	CowMotorController::CowMotorController(int deviceNum)
		:
		m_DeviceNum(deviceNum)
	{
		m_CowControlMode = CowMotorController::PERCENTVBUS;
		m_CowNeutralMode = CowMotorController::COAST;
		m_MotorController = new TalonSRX(deviceNum);
	}

	CowMotorController::~CowMotorController()
	{
		delete m_MotorController;
	}

	void CowMotorController::SetNeutralMode(CowMotorController::CowNeutralMode mode)
	{
		m_CowNeutralMode = mode;
		switch(mode)
		{
			case CowMotorController::JUMPER :
				m_MotorController->SetNeutralMode(EEPROMSetting);
				break;
			case CowMotorController::BRAKE :
				m_MotorController->SetNeutralMode(Brake);
				break;
			case CowMotorController::COAST :
				m_MotorController->SetNeutralMode(Coast);
				break;
			default :
				// What?
				break;
		}
	}

	void CowMotorController::SetControlMode(CowMotorController::CowControlMode mode)
	{
		m_CowControlMode = mode;
	}

	ControlMode CowMotorController::TranslateControlMode(enum CowMotorController::CowControlMode mode)
	{
		ControlMode retVal = ControlMode::Disabled;

		switch(mode)
		{
			case CowMotorController::PERCENTVBUS :
				retVal = ControlMode::PercentOutput;
				break;
			case CowMotorController::CURRENT :
				retVal = ControlMode::Current;
				break;
			case CowMotorController::SPEED :
				retVal = ControlMode::Velocity;
				break;
			case CowMotorController::POSITION :
				retVal = ControlMode::Position;
				break;
			case CowMotorController::VOLTAGE :
				// Unsupported
				break;
			case CowMotorController::FOLLOWER :
				retVal = ControlMode::Follower;
				break;
			case CowMotorController::MOTIONPROFILE :
				retVal = ControlMode::MotionProfile;
				break;
			default :
				// What?
				break;
		}

		return retVal;
	}

	enum CowMotorController::CowControlMode CowMotorController::GetControlMode()
	{
		return m_CowControlMode;
	}

	void CowMotorController::Set(float value)
	{
		m_MotorController->Set(TranslateControlMode(GetControlMode()), value);
	}
}
