#ifndef sysex_hpp
#define sysex_hpp

#include <Arduino.h>

namespace nwm_01 {

void doSysex(uint8_t array[], unsigned size);
	void setIndividualParameter(uint8_t parameter, uint8_t value);
	void setTuning(uint8_t array[], unsigned size);
	bool validManufacturerId(uint8_t array[], unsigned size);
	bool validDeviceId(uint8_t array[], unsigned size);
}
#endif