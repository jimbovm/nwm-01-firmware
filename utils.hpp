#ifndef utils_hpp
#define utils_hpp

#include <Arduino.h>

namespace nwm_01 {

	bool forChannel(uint8_t channel);
	bool expired(unsigned long epoch, int duration);
	uint8_t* getHeldNotes();
}

#endif