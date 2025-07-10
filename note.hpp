#ifndef note_hpp
#define note_hpp

namespace nwm_01 {

	void noteOn(uint8_t channel, uint8_t note, uint8_t velocity);
	void noteOff(uint8_t channel, uint8_t note, uint8_t velocity);
}
#endif