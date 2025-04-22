#ifndef constants_hpp
#define constants_hpp
#include <Arduino.h>

namespace nwm_01 {

	// The voltage difference between two semitones when 1V = one octave.
	const double ONE_SEMITONE = 0.083333;

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
	const int TUNING_LENGTH = 60;

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
		4,
		8,
		12,
		16,
		21,
		25,
		29,
		33,
		38,
		42,
		46,
		50,
		55,
		59,
		63,
		67,
		72,
		76,
		80,
		84,
		89,
		93,
		97,
		101,
		106,
		110,
		114,
		118,
		123,
		127,
		131,
		135,
		140,
		144,
		148,
		152,
		157,
		161,
		165,
		169,
		174,
		178,
		182,
		186,
		191,
		195,
		199,
		203,
		208,
		212,
		216,
		220,
		225,
		229,
		233,
		237,
		242,
		246,
		250};
}
#endif