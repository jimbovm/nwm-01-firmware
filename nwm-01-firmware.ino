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

void setup() {
	initConfig();
	tune(_12_TET);
	pinMode(NOTE_OUT, OUTPUT);
	pinMode(VELOCITY_OUT, OUTPUT);
	pinMode(GATE_OUT, OUTPUT);
	pinMode(TRIGGER_OUT, OUTPUT);
	pinMode(STARTSTOP_OUT, OUTPUT);
	pinMode(CLOCK_OUT, OUTPUT);
	MIDI.begin();
	MIDI.turnThruOff();
	MIDI.setHandleNoteOn(noteOn);
	MIDI.setHandleNoteOff(noteOff);
	MIDI.setHandleClock(clockTick);
	MIDI.setHandleStart(start);
	MIDI.setHandleStop(stop);
	MIDI.begin(_config.receiveChannel);
	gateOff();
	digitalWrite(TRIGGER_OUT, _config.triggerPolarity == trigger::Polarity::ACTIVE_LOW ? HIGH : LOW);
}

void loop() {
	MIDI.read();
	if ((micros() - _clockOnEpoch) >= _config.clockDuration) {
		digitalWrite(CLOCK_OUT, LOW);
	}
	if ((micros() - _triggerOnEpoch) >= _config.triggerDuration) {
		triggerOff();	
	}
}