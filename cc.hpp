#ifndef cc_hpp
#define cc_hpp

#include <Arduino.h>

namespace nwm_01 {

    void controlChange(uint8_t channel, uint8_t number, uint8_t value);
    void setVelocityCCReassign(uint8_t number);
}

#endif