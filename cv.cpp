#include "constants.hpp"
#include "globals.hpp"

namespace nwm_01 {

	// converts MIDI note to 1V/oct voltage level
	inline double noteToCV(int note) {
		double normalized = -_config.lowNote + note;
		return (normalized * ONE_SEMITONE);
	}

	// converts output of noteToCV (volts) to duty cycle
	// for Arduino 'analogue' out
	inline int cvToDuty(double cv) {
		return (255/5) * cv;
	}
}