#include "tuning.hpp"
#include "globals.hpp"
#include "constants.hpp"

namespace nwm_01 {

	void tune(const uint8_t *tuning) {
		for (int note = 0; note < TUNING_LENGTH; note++) {
			_tuneTable[note] = tuning[note];
		}
	}
}