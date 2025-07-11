#ifndef enums_hpp
#define enums_hpp

namespace nwm_01 {

	namespace gate {
		enum Polarity: uint8_t {
			ACTIVE_HIGH = 0,
			ACTIVE_LOW = 1
		};
	}

	namespace trigger {
		enum Polarity: uint8_t {
			ACTIVE_HIGH = 0,
			ACTIVE_LOW = 1
		};
	}

	namespace arpeggiator {
		enum Pattern: uint8_t {
			OFF = 0,
			UP = 1,
			DOWN = 2,
			UP_DOWN = 3,
			DOWN_UP = 4,
			RANDOM = 5
		};
	}

	namespace velocity {
		enum Curve: uint8_t {
			OFF = 0,
			LINEAR = 1,
			STEEP = 2,
			EXPONENTIAL = 3,
			LOGARITHMIC = 4
		};
	}
	
	namespace clock {
		enum Source: uint8_t {
			MIDI = 0,
			SELF = 1
		};
	}

	enum OperatingMode: uint8_t {
		INIT = 0,
		NORMAL = 1,
		ARPEGGIATOR = 2,
		SEQUENCER = 3,
		BULK_DUMP = 4,
		BULK_RECEIVE = 5
	};
}
#endif