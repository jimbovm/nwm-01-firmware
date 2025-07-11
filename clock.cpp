#include <Arduino.h>
#include "clock.hpp"
#include "globals.hpp"

#include "constants.hpp"

namespace nwm_01 {

	void clockTick() {
		digitalWrite(CLOCK_OUT, HIGH);
		_clockOnEpoch = micros();
	}

	void clockTock() {
		digitalWrite(CLOCK_OUT, LOW);
	}

	void start() {
		digitalWrite(STARTSTOP_OUT, HIGH);
	}
	
	void stop() {
		digitalWrite(STARTSTOP_OUT, LOW);
	}
}