#include <Arduino.h>
#include "constants.hpp"
#include "note.hpp"
#include "gate.hpp"
#include "globals.hpp"
#include "utils.hpp"
#include "velocity.hpp"

namespace nwm_01 {

	// callback for handling NOTE ON messages
	void noteOn(uint8_t channel, uint8_t note, uint8_t velocity) {

		if (forChannel(channel)) {
			if ((note >= _config.lowNote) && (note <= (_config.lowNote + TUNING_LENGTH))) {

				const uint8_t canonicalNote = note - _config.lowNote;
				_keysDown |= (1 << canonicalNote);
				_numberOfKeysDown++;
				
				const uint8_t cv = _tuneTable[canonicalNote];

				gateOn();
				triggerOn();
				analogWrite(NOTE_OUT, cv);

				bool velocityIsReassigned = (_config.velocityCCReassign != 0);
				if (velocityIsReassigned == false) {
					analogWrite(VELOCITY_OUT, calculateVelocityPWM(velocity));
				}
			}
		}
	}

	// callback for handling NOTE OFF messages
	void noteOff(uint8_t channel, uint8_t note, uint8_t velocity) {

		if (forChannel(channel)) {

			const uint8_t canonicalNote = note - _config.lowNote;
			_keysDown ^= (1 << canonicalNote);
			_numberOfKeysDown--;

			bool velocityIsReassigned = (_config.velocityCCReassign != 0);
			if (velocityIsReassigned == false) {
				analogWrite(VELOCITY_OUT, calculateVelocityPWM(velocity));
			}
			triggerOff();
			gateOff();
		}
	}
}