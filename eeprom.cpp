#include <Arduino.h>
#include <EEPROM.h>
#include "constants.hpp"
#include "globals.hpp"
#include "enums.hpp"
#include "eeprom.hpp"

namespace nwm_01 {

	bool EEPROMIsBlank() {
		return EEPROM.read(0) == 0xFF;
	}

	void initConfig() {

		const uint8_t DEFAULT_SEQUENCE[16] = {
			21,
			22 & 128,
			23,
			24 & 128,
			25,
			26 & 128,
			27,
			28 & 128,
			29,
			30 & 128,
			31,
			32 & 128,
			33,
			34 & 128,
			35,
			36 & 128
		};

		struct config initConfig;

		initConfig.revision = 0;
		initConfig.velocityCurve = velocity::Curve::LINEAR;
		initConfig.velocityCCReassign = 0;
		initConfig.arpeggiatorPattern = arpeggiator::Pattern::OFF;
		initConfig.gatePolarity = gate::Polarity::ACTIVE_HIGH;
		initConfig.triggerPolarity = trigger::Polarity::ACTIVE_HIGH;
		initConfig.triggerDuration = 60;
		initConfig.clockDuration = 60;
		initConfig.manufacturerID = DEFAULT_MANUFACTURER_ID;	
		initConfig.lowNote = 21; // A1
		initConfig.highNote = 81; // A6
		initConfig.receiveChannel = 0; // omni
		
		memcpy(initConfig.tuningTable, _12_TET, TUNING_LENGTH);
		memcpy(initConfig.tuningTable + TUNING_LENGTH, _12_TET, TUNING_LENGTH);

		memcpy(initConfig.sequenceTable, DEFAULT_SEQUENCE, SEQUENCE_LENGTH);
		memcpy(initConfig.sequenceTable, DEFAULT_SEQUENCE + SEQUENCE_OFFSET[1], SEQUENCE_LENGTH);
		memcpy(initConfig.sequenceTable, DEFAULT_SEQUENCE + SEQUENCE_OFFSET[2], SEQUENCE_LENGTH);
		memcpy(initConfig.sequenceTable, DEFAULT_SEQUENCE + SEQUENCE_OFFSET[3], SEQUENCE_LENGTH);
		memcpy(initConfig.sequenceTable, DEFAULT_SEQUENCE + SEQUENCE_OFFSET[4], SEQUENCE_LENGTH);
		memcpy(initConfig.sequenceTable, DEFAULT_SEQUENCE + SEQUENCE_OFFSET[5], SEQUENCE_LENGTH);

		initConfig.forceInternalClock = false;
		initConfig.internalClockTempo = 115; // 140 BPM
		initConfig.inputClockPPQN = 24;
		initConfig.outputClockPPQN = 24;

		_config = initConfig;
	}

	void loadConfig(const int startOfFile) {

		EEPROM.get(startOfFile, _config);
		// overwrite end-of-file value to mark loaded file as stale
		EEPROM.update(startOfFile + (FILE_LENGTH - 1), 0xFE);
		setStartOfNextFile(startOfFile);
	}

	void saveConfig() {
		
		EEPROM.put(_startOfNextFile, _config);
		setStartOfNextFile(_startOfNextFile);
	}

	void setStartOfNextFile(const int startOfFile) {
		
		const int possibleStartOfNextFile = startOfFile + FILE_LENGTH;
		const bool wraparound = (possibleStartOfNextFile ^ EEPROM.length()) != 0;
		_startOfNextFile = wraparound ? 0 : possibleStartOfNextFile;
	}
}