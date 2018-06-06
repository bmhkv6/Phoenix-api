#pragma once

#include "ctre/phoenix/MotorControl/CAN/BaseMotorController.h"
#include "ctre/phoenix/CustomParamConfiguration.h"
//#include "ctre/phoenix/MotorControl/IMotorController.h"

namespace ctre {
namespace phoenix {
namespace motorcontrol{
namespace can {

/**
 * VEX Victor SPX Motor Configuration settings.
 */
struct VictorSPXSlotConfiguration : BaseSlotConfiguration {
	RemoteFeedbackDevice SelectedFeedbackSensor;

	VictorSPXSlotConfiguration() :
		SelectedFeedbackSensor(RemoteFeedbackDevice_None)
	{
	}

};

struct VictorSPXConfiguration : BaseMotorControllerConfiguration {
	VictorSPXSlotConfiguration Slot_0;
	VictorSPXSlotConfiguration Slot_1;
	VictorSPXSlotConfiguration Slot_2;
	VictorSPXSlotConfiguration Slot_3;
	RemoteLimitSwitchSource ForwardLimitSwitchSource;
	RemoteLimitSwitchSource ReverseLimitSwitchSource;

	VictorSPXConfiguration() :
		ForwardLimitSwitchSource(RemoteLimitSwitchSource_Deactivated), 
		ReverseLimitSwitchSource(RemoteLimitSwitchSource_Deactivated)
	{
	}	
};

/**
 * VEX Victor SPX Motor Controller when used on CAN Bus.
 */
class VictorSPX: public virtual ctre::phoenix::motorcontrol::can::BaseMotorController,
                 public virtual ctre::phoenix::motorcontrol::IMotorController {

public:
	VictorSPX(int deviceNumber);
	virtual ~VictorSPX() {
	}
	VictorSPX(VictorSPX const&) = delete;
	VictorSPX& operator=(VictorSPX const&) = delete;
	
	//------ All Configs ----------//
	ctre::phoenix::ErrorCode ConfigureSlot(VictorSPXSlotConfiguration &slot, int pidIdx = 0, int timeoutMs = 50);
	virtual ctre::phoenix::ErrorCode ConfigAllSettings(VictorSPXConfiguration &allConfigs, int timeoutMs = 50);
	virtual ctre::phoenix::ErrorCode ConfigFactoryDefault(int timeoutMs = 50);

};// class VictorSPX
} // namespace can
} // namespace motorcontrol
} // namespace phoenix
} // namespace ctre
