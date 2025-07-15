#ifndef globals_hpp
#define globals_hpp
#include <Arduino.h>
#include "constants.hpp"
#include "enums.hpp"
#include "gate.hpp"

#include <MIDI.h>

namespace nwm_01 {

	extern int _startOfNextFile;
	extern enum OperatingMode _operatingMode;

	struct config {

		uint8_t revision;
		uint8_t velocityCurve;
		uint8_t velocityCCReassign;
		uint8_t arpeggiatorPattern;
		uint8_t gatePolarity;
		uint8_t triggerPolarity;
		uint8_t triggerDuration;
		uint8_t clockDuration;
		uint8_t manufacturerID;	
		uint8_t lowNote;
		uint8_t highNote;
		uint8_t receiveChannel;
		uint8_t tuningTable[TUNING_LENGTH * 2];
		uint8_t sequenceTable[SEQUENCE_LENGTH * 6];
		uint8_t internalClockTempo;
		uint8_t forceInternalClock;
		uint8_t inputClockPPQN;
		uint8_t outputClockPPQN;
		uint8_t reserved;
		uint8_t endOfFile;
	};

	extern struct config _config;
		
	extern int _tuneTable[60];

	extern unsigned long _clockOnEpoch;
	extern unsigned long _triggerOnEpoch;

	extern uint8_t _numberOfKeysDown;
        extern unsigned long long _keysDown;

	extern midi::MidiInterface<HardwareSerial, midi::DefaultSettings> MIDI;

}
#endif