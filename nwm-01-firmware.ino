#include "clock.hpp"
#include "constants.hpp"
#include "eeprom.hpp"
#include "globals.hpp"
#include "note.hpp"
#include "tuning.hpp"
#include "gate.hpp"

#include <Arduino.h>
#include <EEPROM.h>
#include <MIDI.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>
#include <midi_Defs.h>
#include <midi_Message.h>

#define NWM_01_PRODUCTION

using namespace nwm_01;

// initialize MIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);

void setup() {
	if (EEPROMIsBlank()) {
		initConfig();
	}
	else {
		int startOfFile = 0;
		while (EEPROM.read(startOfFile) != 0xFF);
		loadConfig(startOfFile + 1);
	}
	tune(_12_TET);
	pinMode(NOTE_OUT, OUTPUT);
	pinMode(VELOCITY_OUT, OUTPUT);
	pinMode(GATE_OUT, OUTPUT);
	pinMode(TRIGGER_OUT, OUTPUT);
	pinMode(STARTSTOP_OUT, OUTPUT);
	pinMode(CLOCK_OUT, OUTPUT);
	MIDI.turnThruOff();
	MIDI.setHandleNoteOn(noteOn);
	MIDI.setHandleNoteOff(noteOff);
	MIDI.setHandleClock(clockTick);
	MIDI.setHandleStart(start);
	MIDI.setHandleStop(stop);
	MIDI.begin(_config.receiveChannel);
	gateOff();
}

void loop() {
	MIDI.read();
}