#include "sysex.hpp"
#include "cc.hpp"
#include "config.hpp"
#include "constants.hpp"
#include "globals.hpp"
#include "enums.hpp"

#include <Arduino.h>

#define DEFAULT_LOW_NOTE 21

namespace nwm_01 {

	void doSysex(uint8_t array[], unsigned size) {

		if (
			validManufacturerId(array, size) &&
			validDeviceId(array, size)
		) {

			// If we're here, we may have a message addressed to the module
			if (size < (sysex::Offset::OPCODE + 1)) return;
			sysex::Opcode opcode = (sysex::Opcode) array[sysex::Offset::OPCODE];

			switch (opcode) {
				case sysex::Opcode::SET_INDIVIDUAL_PARAMETER:
					if (size < (sysex::Offset::PARAMETER_VALUE_LOW + 1)) return;
					const uint8_t parameter = array[sysex::Offset::PARAMETER_NUMBER];
					const uint8_t high_value = array[sysex::Offset::PARAMETER_VALUE_HIGH];
					const uint8_t low_value = array[sysex::Offset::PARAMETER_VALUE_LOW];
					const uint8_t value = low_value | (high_value << 7);
					setIndividualParameter(parameter, value);
					break;
				case sysex::Opcode::SET_TUNING:		
					if (size < (TUNING_LENGTH + 1)) return;
					setTuning(array, size);
				default:
					return;
			}
		}
	}

	bool validManufacturerId(uint8_t array[], unsigned size) {

		if (size < (sysex::Offset::M + 1)) return false;

		return ((array[sysex::Offset::MANUFACTURER_ID] == _config.manufacturerID) &&
			(array[sysex::Offset::N] == 'N') &&
			(array[sysex::Offset::W] == 'W') &&
			(array[sysex::Offset::M] == 'M'));
	}

	bool validDeviceId(uint8_t array[], unsigned size) {

		if (size < (sysex::Offset::DEVICE_VARIANT + 1)) return false;

		return true;
	}

	void setIndividualParameter(uint8_t parameter, uint8_t value) {
		switch (parameter) {
			case settings::Parameter::VELOCITY_CURVE:
				_config.velocityCurve = (velocity::Curve) ((value <= velocity::Curve::MAX) ? value : velocity::Curve::OFF);
				break;
			case settings::Parameter::VELOCITY_CC_REASSIGN:
				setVelocityCCReassign((value <= 127) ? value : 1);
				break;
			case settings::Parameter::GATE_POLARITY:
				_config.gatePolarity = (gate::Polarity) ((value < 2) ? value : 0);
				break;
			case settings::Parameter::TRIGGER_POLARITY:
				_config.triggerPolarity = (trigger::Polarity) ((value < 2) ? value : 0);
				break;
			case settings::Parameter::TRIGGER_DURATION:
				_config.triggerDuration = value;
				break;
			case settings::Parameter::CLOCK_DURATION:
				_config.clockDuration = value;
				break;
			case settings::Parameter::MANUFACTURER_ID:
				_config.manufacturerID = value;
				break;
			case settings::Parameter::LOW_NOTE:
				_config.lowNote = (value < 127) ? value : DEFAULT_LOW_NOTE;
				break;
			case settings::Parameter::RECEIVE_CHANNEL:
				_config.receiveChannel = (value > 16) ? 0 : value;
				break;
			case settings::Parameter::FORCE_INTERNAL_CLOCK:
				_config.forceInternalClock = (value < 2) ? value : 0;
				break;
			case settings::Parameter::INTERNAL_CLOCK_TEMPO:
				_config.internalClockTempo = value;
				break;
			case settings::Parameter::INPUT_CLOCK_PPQN:
				_config.inputClockPPQN = value;
				break;
			case settings::Parameter::OUTPUT_CLOCK_PPQN:
				_config.outputClockPPQN = value;
				break;
			default:
				return;
		}
	}

	void setTuning(uint8_t tuning[], unsigned size) {
	}
}