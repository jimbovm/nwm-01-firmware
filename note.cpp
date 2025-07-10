#include <Arduino.h>
#include "constants.hpp"
#include "note.hpp"
#include "cv.hpp"
#include "gate.hpp"
#include "globals.hpp"

namespace nwm_01 {

	// callback for handling NOTE ON messages
	void noteOn(unsigned char channel, unsigned char pitch, unsigned char velocity) {
		if ((pitch >= _config.lowNote) && (pitch <= _config.highNote)) {
			int cv = _tuneTable[(int) pitch - _config.lowNote];
			gateOn();
			triggerOn();
			analogWrite(NOTE_OUT, cv);
			analogWrite(VELOCITY_OUT, velocity << 1);
		}
	}

	// callback for handling NOTE OFF messages
	void noteOff(unsigned char channel, unsigned char note, unsigned char velocity) {
		analogWrite(VELOCITY_OUT, 0);
		triggerOff();
		gateOff();
	}
}