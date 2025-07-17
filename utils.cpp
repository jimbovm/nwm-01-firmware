#include "utils.hpp"

#include "globals.hpp"

#include <Arduino.h>
#include <stdlib.h>

namespace nwm_01 {

	bool forChannel(uint8_t channel) {
		return ((_config.receiveChannel == MIDI_CHANNEL_OMNI) || (_config.receiveChannel == channel));
	}

	bool expired(unsigned long epoch, int duration) {
		return (micros() - epoch) >= duration;
	}

	inline int compareAscend(const void* a_, const void* b_) {
		const int a = *((const int*) a_);
		const int b = *((const int*) b_); 
		return (a > b) - (b < a);
	}

	uint8_t* getHeldCanonicalNotes(unsigned long long keysDown) {
	
		if (_numberOfKeysDown == 0) {
			return nullptr;
		}

		uint8_t heldNotes[_numberOfKeysDown];
		uint8_t i = 0;

		while (keysDown != 0LL) {
			const uint8_t trailingZeroes = __builtin_ctzll(keysDown);
			const uint8_t heldMidiNote = trailingZeroes + 1;
			const uint8_t canonicalNote = heldMidiNote - _config.lowNote;

			heldNotes[i] = canonicalNote;
			i++;

			// mask out note just seen
			keysDown ^= 1 << heldMidiNote;
		}

		if (_config.arpeggiatorPattern != arpeggiator::Pattern::RANDOM) {
			qsort(heldNotes, _numberOfKeysDown, sizeof(uint8_t), compareAscend);
		}

		return heldNotes;
	}
}