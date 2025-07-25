#include "globals.hpp"
#include "enums.hpp"

#include <MIDI.h>

namespace nwm_01 {

	enum OperatingMode _operatingMode;
	
	uint8_t _tuneTable[TUNING_LENGTH];
	
	struct config _config;

	int _startOfNextFile;

	unsigned long _triggerOnEpoch;
	unsigned long _clockOnEpoch;

	uint8_t _numberOfKeysDown;
        unsigned long long _keysDown;

	extern midi::MidiInterface<HardwareSerial, midi::DefaultSettings> MIDI = midi::MidiInterface<HardwareSerial>((HardwareSerial&) Serial);

}