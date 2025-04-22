#include <Arduino.h>
#include "gate.hpp"
#include "constants.hpp"
#include "globals.hpp"

namespace nwm_01 {

	void gateOn() {
		digitalWrite(GATE_OUT, _config.gatePolarity == gate::ACTIVE_LOW ? LOW : HIGH);
	}

	void gateOff() {
		digitalWrite(GATE_OUT, _config.gatePolarity == gate::ACTIVE_LOW ? HIGH : LOW);
	}
}