#ifndef constants_hpp
#define constants_hpp
#include <Arduino.h>

namespace nwm_01 {

	// The pin on which to output CV via PWM. By default this is pin 5, which has high resolution PWM.
	const int NOTE_OUT = 5;

	// The pin on which the gate signal is output. 
	const int GATE_OUT = 3;

	// The pin on which the trigger pulse is output.
	const int TRIGGER_OUT = 4;

	// The pin on which to output velocity data (or a reassigned CC). This has lower resolution PWM.
	const int VELOCITY_OUT = 9;

	// The pin on which to output clock pulses.
	const int CLOCK_OUT = 10;

	// The pin on which to send a start/stop pulse.
	const int STARTSTOP_OUT = 12;

	// Size (in bytes) of the memory file.
	const int FILE_LENGTH = 256;

	// Number of tuning entries in a tuning.
	const int TUNING_LENGTH = 56;

	// Maximum number of notes in a sequence.
	const int SEQUENCE_LENGTH = 16;

	const int SEQUENCE_OFFSET[6] = {
		0,
		16,
		32,
		48,
		64,
		80
	};

	// What number of microseconds to set the trigger duration to if 0 is read from EEPROM.
	const int DEFAULT_TRIGGER_DURATION = 500;

	// What to set the manufacturer ID to on first boot.
	const int DEFAULT_MANUFACTURER_ID = 0x64;

	// Default 12-tone equal temperament tuning.
	const uint8_t _12_TET[TUNING_LENGTH] = {
		0,
		5,
		9,
		14,
		19,
		23,
		28,
		32,
		37,
		42,
		46,
		51,
		56,
		60,
		65,
		70,
		74,
		79,
		83,
		88,
		93,
		97,
		102,
		107,
		111,
		116,
		121,
		125,
		130,
		134,
		139,
		144,
		148,
		153,
		158,
		162,
		167,
		172,
		176,
		181,
		185,
		190,
		195,
		199,
		204,
		209,
		213,
		218,
		223,
		227,
		232,
		236,
		241,
		246,
		250,
		255,
	};
}
#endif