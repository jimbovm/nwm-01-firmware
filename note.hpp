#ifndef note_hpp
#define note_hpp
#include "gate.hpp"

namespace nwm_01 {

	void noteOn(unsigned char channel, unsigned char pitch, unsigned char velocity);
	void noteOff(unsigned char channel, unsigned char pitch, unsigned char velocity);
}
#endif