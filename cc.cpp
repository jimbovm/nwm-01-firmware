#include "cc.hpp"

#include "constants.hpp"
#include "globals.hpp"
#include "utils.hpp"

#include <Arduino.h>

namespace nwm_01 {

    void controlChange(uint8_t channel, uint8_t number, uint8_t value) {
		if (forChannel(channel)) {
			if (number == _config.velocityCCReassign) {
				analogWrite(VELOCITY_OUT, value * 2);
			}
		}
    }

	void setVelocityCCReassign(uint8_t number) {
		_config.velocityCCReassign = number;
		if (number != 0) {
			MIDI.setHandleControlChange(controlChange);
		}
		else {
			MIDI.disconnectCallbackFromType(midi::ControlChange);
		}
	}
}