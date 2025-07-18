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
			RANDOM = 5,
			MAX = RANDOM
		};
	}

	namespace velocity {
		enum Curve: uint8_t {
			OFF = 0,
			LINEAR = 1,
			STEEP = 2,
			EXPONENTIAL = 3,
			LOGARITHMIC = 4,
			MAX = LOGARITHMIC
		};
	}
	
	namespace clock {
		enum Source: uint8_t {
			MIDI = 0,
			SELF = 1
		};
	}

	namespace sysex {
		enum Offset: uint8_t {
			BEGIN_SYSEX = 0,
			MANUFACTURER_ID = 1,
			N = 2,
			W = 3,
			M = 4,
			DEVICE_MODEL = 5,
			DEVICE_VARIANT = 6,
			OPCODE = 7,
			PARAMETER_NUMBER = 8,
			PARAMETER_VALUE_HIGH = 9,
			PARAMETER_VALUE_LOW = 10,
		};

		enum Opcode: uint8_t {
			SET_INDIVIDUAL_PARAMETER,
			SET_TUNING,
		};
	}

	namespace settings {
		enum Parameter: uint8_t {
			VELOCITY_CURVE = 0x01,
			VELOCITY_CC_REASSIGN = 0x02,
			ARPEGGIATOR_PATTERN = 0x03,
			GATE_POLARITY = 0x04,
			TRIGGER_POLARITY = 0x05,
			TRIGGER_DURATION = 0x06,
			CLOCK_DURATION = 0x07,
			LOW_NOTE = 0x08,
			RECEIVE_CHANNEL = 0x09,
			MANUFACTURER_ID = 0x0A,
			FORCE_INTERNAL_CLOCK = 0x0B,
			INTERNAL_CLOCK_TEMPO = 0x0C,
			INPUT_CLOCK_PPQN = 0x0D,
			OUTPUT_CLOCK_PPQN = 0x0E,
			TUNING = 0x0F,
			MAX = TUNING
		};
	}

	enum OperatingMode: uint8_t {
		INIT = 0,
		NORMAL = 1,
		ARPEGGIATOR = 2,
		SEQUENCER_WRITE = 3,
		SEQUENCER_PLAY = 4,
		BULK_RECEIVE = 5
	};
}
#endif