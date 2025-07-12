#include "velocity.hpp"

#include "config.hpp"
#include "globals.hpp"
#include "enums.hpp"

#include <Arduino.h>

namespace nwm_01 {

	uint8_t calculateVelocityPWM(uint8_t velocity) {

		switch (_config.velocityCurve) {
			case velocity::Curve::OFF:
				return 255;
			case velocity::Curve::LINEAR:
				return velocity * 2;
			case velocity::Curve::STEEP:
				return steepPWM[velocity];
			case velocity::Curve::LOGARITHMIC:
				return logarithmicPWM[velocity];
			case velocity::Curve::EXPONENTIAL:
				return exponentialPWM[velocity];
			default:
				return velocity * 2;
		}
	}
}