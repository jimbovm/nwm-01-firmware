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
		velocity::Curve velocityCurve;
		uint8_t velocityCCReassign;
		arpeggiator::Pattern arpeggiatorPattern;
		gate::Polarity gatePolarity;
		trigger::Polarity triggerPolarity;
		uint8_t triggerDuration;
		uint8_t lowNote;
		OperatingMode operatingMode;
		uint8_t clockDuration;
		uint8_t receiveChannel;
		uint8_t manufacturerID;
		uint8_t internalClockTempo;
		uint8_t forceInternalClock;
		uint8_t inputClockPPQN;
		uint8_t outputClockPPQN;
		uint8_t tuning;
	};

	extern struct config _config;
		
	extern uint8_t _tuneTable[TUNING_LENGTH];

	extern unsigned long _clockOnEpoch;
	extern unsigned long _triggerOnEpoch;

	extern uint8_t _numberOfKeysDown;
        extern unsigned long long _keysDown;

	extern midi::MidiInterface<HardwareSerial, midi::DefaultSettings> MIDI;

}
#endif