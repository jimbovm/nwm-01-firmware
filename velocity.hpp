#ifndef velocity_hpp
#define velocity_hpp

#include <Arduino.h>

namespace nwm_01 {
	
	const int steepPWM[] = {
		128,
		129,
		130,
		131,
		132,
		133,
		134,
		135,
		136,
		137,
		138,
		139,
		140,
		141,
		142,
		143,
		144,
		145,
		146,
		147,
		148,
		149,
		150,
		151,
		152,
		153,
		154,
		155,
		156,
		157,
		158,
		159,
		160,
		161,
		162,
		163,
		164,
		165,
		166,
		167,
		168,
		169,
		170,
		171,
		172,
		173,
		174,
		175,
		176,
		177,
		178,
		179,
		180,
		181,
		182,
		183,
		184,
		185,
		186,
		187,
		188,
		189,
		190,
		191,
		192,
		193,
		194,
		195,
		196,
		197,
		198,
		199,
		200,
		201,
		202,
		203,
		204,
		205,
		206,
		207,
		208,
		209,
		210,
		211,
		212,
		213,
		214,
		215,
		216,
		217,
		218,
		219,
		220,
		221,
		222,
		223,
		224,
		225,
		226,
		227,
		228,
		229,
		230,
		231,
		232,
		233,
		234,
		235,
		236,
		237,
		238,
		239,
		240,
		241,
		242,
		243,
		244,
		245,
		246,
		247,
		248,
		249,
		250,
		251,
		252,
		253,
		254,
		255	
	};

	const int logarithmicPWM[] = {
		0,
		19,
		38,
		61,
		76,
		89,
		99,
		107,
		115,
		121,
		127,
		132,
		137,
		141,
		146,
		149,
		153,
		156,
		159,
		162,
		165,
		168,
		170,
		173,
		175,
		178,
		180,
		182,
		184,
		186,
		188,
		189,
		191,
		193,
		194,
		196,
		198,
		199,
		201,
		202,
		203,
		205,
		206,
		207,
		209,
		210,
		211,
		212,
		214,
		215,
		216,
		217,
		218,
		219,
		220,
		221,
		222,
		223,
		224,
		225,
		226,
		227,
		228,
		229,
		229,
		230,
		231,
		232,
		233,
		234,
		234,
		235,
		236,
		237,
		237,
		238,
		239,
		240,
		240,
		241,
		242,
		242,
		243,
		244,
		244,
		245,
		246,
		246,
		247,
		248,
		248,
		249,
		249,
		250,
		251,
		251,
		252,
		252,
		253,
		253,
		254,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255
	};

	const int exponentialPWM[] = {
		0,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		3,
		3,
		3,
		3,
		3,
		3,
		3,
		3,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		5,
		5,
		6,
		6,
		7,
		7,
		8,
		9,
		9,
		10,
		11,
		11,
		12,
		13,
		13,
		14,
		15,
		15,
		16,
		17,
		18,
		18,
		19,
		20,
		21,
		21,
		22,
		23,
		24,
		25,
		26,
		26,
		27,
		28,
		29,
		30,
		31,
		32,
		33,
		34,
		35,
		36,
		37,
		38,
		39,
		40,
		41,
		43,
		44,
		45,
		46,
		48,
		49,
		50,
		52,
		53,
		54,
		56,
		57,
		59,
		61,
		62,
		64,
		66,
		67,
		69,
		71,
		73,
		75,
		77,
		80,
		82,
		85,
		87,
		90,
		93,
		96,
		99,
		102,
		106,
		109,
		114,
		118,
		123,
		128,
		134,
		140,
		148,
		156,
		166,
		179,
		194,
		217,
		236,
		255	
	};

	uint8_t calculateVelocityPWM(uint8_t velocity);
}

#endif