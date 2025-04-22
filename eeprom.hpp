#ifndef eeprom_hpp
#define eeprom_hpp
#include "enums.hpp"

namespace nwm_01 {

	bool EEPROMIsBlank();
	void initConfig();
	void loadConfig(const int startOfFile);
	void saveConfig();
	void setStartOfNextFile(const int startOfFile);
}
#endif