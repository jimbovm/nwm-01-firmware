#include "utils.hpp"

#include "globals.hpp"

#include <Arduino.h>

namespace nwm_01 {

	bool forChannel(uint8_t channel) {
		return ((_config.receiveChannel == MIDI_CHANNEL_OMNI) || (_config.receiveChannel == channel));
	}
}