#pragma once

enum keycode_t{
	key1=1,key2,key3,key4,key5,key6,key7,key8,key9,key0,
	keyq,keyw,keye,keyr,keyt,keyy,keyu,keyi,keyo,keyp,
	keya,keys,keyd,keyf,keyg,keyh,keyj,keyk,keyl,keySEMICOLON,
	keyz,keyx,keyc,keyv,keyb,keyn,keym,keyCOMMA,keyPERIOD,keyFORWARDSLASH,
	keyEXCLAMATION=65,keyAT,keyPOUND,keyDOLLAR
};

enum keycode_t pollInput();
enum keycode_t waitInput();
