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
		)

		// If we're here, we may have a message addressed to the module
		if (size < sysex::Offset::OPCODE) return;
		sysex::Opcode opcode = (sysex::Opcode) array[sysex::Offset::OPCODE];

		switch (opcode) {
			case sysex::Opcode::SET_INDIVIDUAL_PARAMETER:
				if (size < sysex::Offset::PARAMETER_VALUE) return;
				const settings::Parameter parameter = (settings::Parameter) array[sysex::Offset::PARAMETER_NUMBER];
				const uint8_t value = array[sysex::Offset::PARAMETER_VALUE];
				setIndividualParameter(parameter, value);
				break;
			case sysex::Opcode::SET_TUNING:		
				if (size < (TUNING_LENGTH + 1)) return;
				setTuning(array, size);
			default:
				return;
		}
	}

	bool validManufacturerId(uint8_t array[], unsigned size) {

		if (size < sysex::Offset::M) return false;

		return ((array[sysex::Offset::MANUFACTURER_ID] == _config.manufacturerID) &&
			(array[sysex::Offset::N] == 'N') &&
			(array[sysex::Offset::W] == 'W') &&
			(array[sysex::Offset::M] == 'M'));
	}

	bool validDeviceId(uint8_t array[], unsigned size) {

		if (size < sysex::Offset::DEVICE_VARIANT) return false;

		#ifdef NWM_01_DEVICE_MODEL && NWM_01_DEVICE_VARIANT
		return (
			(array[sysex::Offset::DEVICE_MODEL] == DEVICE_MODEL) &&
			(array[sysex::Offset::DEVICE_VARIANT] == DEVICE_VARIANT));
		#endif
	}

	void setIndividualParameter(settings::Parameter parameter, uint8_t value) {
		switch (parameter) {
			case settings::Parameter::VELOCITY_CURVE:
				_config.velocityCurve = (velocity::Curve) (value < velocity::Curve::MAX ? value : 0);
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
				_config.triggerDuration = value;
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
				_config.lowNote = (value < 2) ? value : 0;
				break;
			case settings::Parameter::INTERNAL_CLOCK_TEMPO:
				_config.lowNote = value;
				break;
			case settings::Parameter::INPUT_CLOCK_PPQN:
				_config.lowNote = value;
				break;
			case settings::Parameter::OUTPUT_CLOCK_PPQN:
				_config.lowNote = value;
				break;
			default:
				return;
		}
	}

	void setTuning(uint8_t tuning[], unsigned size) {
	}
}