/*
Created by Dmitry-78 
09.2023
game_test Wolf&Eggs_Boy for Arduboy/ArduboyFX
will be supplemented..
*/

#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "Tinyfont.h"
//#include <avr/pgmspace.h>

Arduboy2 arduboy;
Arduboy2Audio audio;
ArduboyTones sound(arduboy.audio.enabled);


#define wolfLEFT arduboy.drawBitmap(39, 16, WolfLeft, 31, 48, 1);
#define wolfRIGHT arduboy.drawBitmap(53, 16, WolfRight, 27, 48, 1);
#define handLeftUP arduboy.drawBitmap(25, 20, HandLeftUp, 27, 24, 1);
#define handLeftDOWN arduboy.drawBitmap(27, 37, HandLeftDown, 26, 24, 1);
#define handRightUP arduboy.drawBitmap(77, 22, HandRightUp, 25, 26, 1);
#define handRightDOWN arduboy.drawBitmap(74, 40, HandRightDown, 27, 21, 1);
#define border arduboy.drawRect (1, 1, 127, 63, WHITE);


#define RABBIT_WIDTH 40
#define RABBIT_HEIGHT 40
#define BLACK 0

#define rabbit_1 arduboy.drawBitmap(10, 0, rabit_1, 40, 40, 1);
#define rabbit_2 arduboy.drawBitmap(10, 0, rabit_2, 40, 40, 1);
#define rabbit_3 arduboy.drawBitmap(10, 0, rabit_3, 40, 40, 1);
#define rabbit_4 arduboy.drawBitmap(10, 0, rabit_4, 40, 40, 1);
#define rabbit_5 arduboy.drawBitmap(10, 0, rabit_5, 40, 40, 1);
#define rabbit_6 arduboy.drawBitmap(10, 0, rabit_6, 40, 40, 1);



const uint8_t PROGMEM WolfLeft[] = {//31, 48,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x48, 0x2c, 0xb4, 0xf6, 0xfc, 0xfe, 0xfa, 0xfe, 0xfc, 0xfa, 0xfb, 0x9e, 0xec, 0x64, 0x14, 0xe4, 0xfc, 0x84, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x3e, 0xcf, 0x6d, 0xcf, 0x48, 0xd8, 0x90, 0x97, 0x9d, 0xf9, 0xdf, 0xcd, 0x19, 0x1f, 0x43, 0x77, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xdf, 0x1f, 0x33, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x05, 0x0f, 0x09, 0x09, 0x0d, 0xc6, 0xe4, 0x7c, 0x1c, 0x06, 0x82, 0xc0, 0xf3, 0xff, 0x7f, 0x3f, 0x1b, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xe0, 0xf8, 0xfc, 0xff, 0xef, 0xff, 0xfc, 0xfe, 0xff, 0xff, 0xc7, 0x61, 0xe0, 0xb0, 0xf8, 0x7c, 0x3c, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x38, 0x6c, 0xc7, 0x8d, 0x99, 0x71, 0x67, 0xfd, 0x9a, 0x9e, 0x17, 0x11, 0x19, 0x11, 0x11, 0x17, 0x1b, 0x1e, 0x1c, 0x3f, 0x3f, 0xe7, 0x76, 0x04, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x30, 0x38, 0x78, 0x48, 0x79, 0x69, 0x6b, 0x6a, 0x7e, 0x6d, 0x79, 0x62, 0x6e, 0x3c, 0x38, 0x00, 0x00, 0x00, 0x00, 0x38, 0x66, 0x7b, 0x6c, 0x27, 0x36, 0x34, 0x14, 0x1a, 0x1e, 0x0f, 0x04,
};

const uint8_t PROGMEM WolfRight[] = {//27, 48,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xb8, 0x0c, 0xf6, 0x83, 0xff, 0x3c, 0x76, 0x77, 0x7c, 0x7c, 0xfc, 0xfa, 0xfa, 0xd6, 0xac, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0x37, 0xff, 0xff, 0xff, 0x7f, 0x77, 0x43, 0x20, 0x3e, 0x31, 0xbd, 0x31, 0x7d, 0x39, 0x2e, 0x20, 0x33, 0x78, 0x38, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0x03, 0x1f, 0x7e, 0xfe, 0xc0, 0x00, 0x06, 0x08, 0xf9, 0xd3, 0x27, 0x2e, 0x1b, 0x35, 0x07, 0x05, 0x03, 0x01,
  0xf8, 0xfc, 0xf0, 0xa0, 0x7e, 0x81, 0x89, 0xf9, 0x7e, 0xd4, 0xfc, 0x10, 0x1f, 0x3f, 0x7e, 0xf8, 0xfc, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x07, 0x1b, 0x3e, 0x3d, 0x32, 0x1f, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x1c, 0x1a, 0x96, 0xa1, 0x63, 0x54, 0x18, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0x54, 0x64, 0xe2, 0xab, 0xad, 0xac, 0xaa, 0xaa, 0xb3, 0x91, 0x51, 0x70, 0x10, 0x00, 0x00, 0x00,
};

const uint8_t PROGMEM HandLeftUp[] = {//27, 24,
  0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x07, 0x3b, 0xef, 0xee, 0x3c, 0x88, 0xe8, 0xcc, 0x0c, 0x18, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xe0, 0xf0, 0xf0, 0xf8, 0xff, 0xff, 0xbc, 0x3c, 0x7c, 0x7f, 0xff, 0xfc, 0x6e, 0x0f, 0x7f, 0xfc, 0xf8, 0x71, 0xc7, 0xbc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x07, 0x0f, 0x0f, 0x1d, 0x15, 0x31, 0x33, 0x30, 0x10, 0x10, 0x18, 0x10, 0x10, 0x11, 0x33, 0x36, 0x26, 0x2c, 0x28, 0x78, 0x70, 0x70, 0x60, 0x00, 0x00,
};

const uint8_t PROGMEM HandLeftDown[] = {//26, 24,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xc8, 0xcc, 0xc6, 0x82, 0xe3, 0x41, 0xf1, 0xf1, 0xd1, 0x59, 0x69, 0x2d, 0x35, 0x15, 0x95, 0x95, 0xf7, 0x77, 0x50, 0x70,
  0xe0, 0xe0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xe1, 0xed, 0xff, 0xf5, 0xe0, 0xe0, 0xe0, 0xe1, 0xe0, 0x30, 0x1c, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t PROGMEM HandRightUp[] = {//25, 26,
  0x00, 0x00, 0xc0, 0x40, 0x40, 0x70, 0x30, 0x10, 0x48, 0xdc, 0xe4, 0xf6, 0xa6, 0x66, 0xce, 0x7e, 0x1c, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x01, 0x01, 0x01, 0xf1, 0xf3, 0xf6, 0xf4, 0xff, 0xff, 0x3a, 0x7a, 0xfd, 0xfd, 0xff, 0xfc, 0xfc, 0x7f, 0xff, 0xfc, 0xf8, 0xf8, 0x78, 0x00,
  0x80, 0x40, 0x40, 0x20, 0x20, 0x21, 0x23, 0x27, 0x1f, 0x1f, 0x1f, 0x00, 0x80, 0x83, 0x83, 0x83, 0x83, 0x4c, 0x46, 0x5b, 0x39, 0x0f, 0x03, 0x00, 0x00,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t PROGMEM HandRightDown[] = {//27, 21,
  0x77, 0xf7, 0x95, 0x7d, 0x69, 0xc9, 0x91, 0x36, 0x66, 0xc2, 0x93, 0xf9, 0xf1, 0x71, 0x5f, 0x56, 0xd6, 0x3e, 0x0e, 0x3c, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x06, 0x0e, 0x18, 0x39, 0xc2, 0x86, 0x06, 0x07, 0x07, 0x07, 0x07, 0x4e, 0x4e, 0x6d, 0x6e, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x04, 0x0c, 0x0a, 0x19, 0x19, 0x1b, 0x1b, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00,
};



const uint8_t PROGMEM eggLeft_Right[] = {//10, 12,
  0xe0, 0x18, 0x04, 0x02, 0x01, 0x01, 0x02, 0x04, 0x18, 0xe0,
  0x01, 0x02, 0x04, 0x08, 0x08, 0x08, 0x08, 0x04, 0x02, 0x01,
};

const uint8_t PROGMEM eggLeft_2[] = {//11, 10,
  0xf0, 0x0e, 0x04, 0x1c, 0x7b, 0xff, 0x7f, 0x1e, 0x08, 0x08, 0xf0,
  0x00, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x02, 0x02, 0x01, 0x00,
};

const uint8_t PROGMEM eggLeft_3[] = {//14, 13,
0x20, 0x60, 0xe6, 0xcc, 0x9e, 0xfb, 0xff, 0xdf, 0xce, 0xe0, 0xf0, 0xb0, 0x30, 0x10, 
0x00, 0x06, 0x09, 0x10, 0x11, 0x0b, 0x0f, 0x0f, 0x1f, 0x13, 0x11, 0x10, 0x09, 0x06, 
};

const uint8_t PROGMEM eggLeft_4[] = {//13, 10,
0x06, 0x0c, 0x0e, 0xdd, 0xff, 0xff, 0xa6, 0x70, 0xf0, 0xe0, 0xc0, 0x60, 0x20, 
0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 
};

const uint8_t PROGMEM eggLeft_5[] = {//11, 10,
0x1e, 0xdf, 0xff, 0xfd, 0xae, 0x6c, 0xf6, 0xf0, 0xe0, 0x70, 0x18, 
0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 
};

const uint8_t PROGMEM eggLeft_6[] = {//12, 12,
0x06, 0x0c, 0x9e, 0xfb, 0xff, 0xdf, 0xce, 0xe0, 0xf0, 0x30, 0x30, 0x10, 
0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x04, 0x00, 
};


const uint8_t PROGMEM eggRight_2[] = {//11, 10,
0xf0, 0x08, 0x08, 0x1e, 0x7f, 0xff, 0x7b, 0x1c, 0x04, 0x0e, 0xf0, 
0x00, 0x01, 0x02, 0x02, 0x03, 0x01, 0x01, 0x02, 0x02, 0x01, 0x00, 
};

const uint8_t PROGMEM eggRight_3[] = {//14, 13,
0x10, 0x30, 0xb0, 0xf0, 0xe0, 0xce, 0xdf, 0xff, 0xfb, 0x9e, 0xcc, 0xe6, 0x60, 0x20, 
0x06, 0x09, 0x10, 0x11, 0x13, 0x1f, 0x0f, 0x0f, 0x0b, 0x11, 0x10, 0x09, 0x06, 0x00, 
};

const uint8_t PROGMEM eggRight_4[] = {//13, 10,
0x20, 0x60, 0xc0, 0xe0, 0xf0, 0x70, 0xa6, 0xff, 0xff, 0xdd, 0x0e, 0x0c, 0x06, 
0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM eggRight_5[] = {//11, 10,
0x18, 0x70, 0xe0, 0xf0, 0xf6, 0x6c, 0xae, 0xfd, 0xff, 0xdf, 0x1e, 
0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 
};

const uint8_t PROGMEM eggRight_6[] = {//12, 12,
0x10, 0x30, 0x30, 0xf0, 0xe0, 0xce, 0xdf, 0xff, 0xfb, 0x9e, 0x0c, 0x06, 
0x00, 0x04, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 
};



const uint8_t PROGMEM rabit_1[] = {//40, 40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x19, 0x61, 0x82, 0x24, 0xc8, 0x31, 0x42, 0x84, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 0x04, 0x02, 0x01, 0x01, 0x60, 0x31, 0xb0, 0xf1, 0x22, 0x01, 0xe4, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x04, 0x70, 0xfc, 0xff, 0xf8, 0xf8, 0x78, 0xbc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0x7c, 0x10, 0xc0, 0xe0, 0x48, 0x51, 0xa2, 0xc6, 0x43, 0x40, 0x4b, 0x64, 0x3d, 0x58, 0x40, 0x90, 0x80, 0x20, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x10, 0x10, 0x11, 0x0f, 0x1f, 0x2e, 0x4f, 0x8f, 0x1f, 0x2f, 0x4f, 0x4f, 0x4b, 0x4d, 0x66, 0x23, 0x11, 0x30, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x90, 0xf0, 0x21, 0x21, 0x1e, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x14, 0x12, 0x11, 0x10, 0x30, 0xf1, 0xd2, 0x14, 0x18,
};

const uint8_t PROGMEM rabit_2[] = {//40, 40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x19, 0x61, 0x82, 0x24, 0xc8, 0x31, 0x42, 0x84, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 0x04, 0x02, 0x01, 0x01, 0x60, 0x31, 0xb0, 0xf1, 0x22, 0x01, 0xe4, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x05, 0x74, 0xf8, 0xfc, 0xff, 0xf8, 0xf8, 0xfc, 0xbc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0x7c, 0x10, 0x80, 0xc0, 0x48, 0x51, 0xa2, 0xc6, 0x43, 0x40, 0x4b, 0x64, 0x3d, 0x18, 0xc0, 0x90, 0x00, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x10, 0x10, 0x11, 0x0f, 0x1f, 0x2e, 0x4f, 0x8f, 0x1f, 0x2f, 0x4f, 0x4f, 0x4b, 0x4d, 0x66, 0x23, 0x11, 0x30, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8e, 0xd0, 0xb0, 0x21, 0x21, 0x1e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0c, 0x0a, 0x09, 0x18, 0x30, 0xf1, 0xd2, 0x14, 0x18, 0x10, 0x00,
};

const uint8_t PROGMEM rabit_3[] = {//40, 40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x69, 0x81, 0x22, 0xc4, 0x38, 0x41, 0x82, 0x3c, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xb8, 0x04, 0x02, 0x01, 0x01, 0x00, 0xb1, 0x18, 0x59, 0xfa, 0x11, 0x80, 0x70, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x05, 0x74, 0xf0, 0xfc, 0xff, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xff, 0x7f, 0x1c, 0x88, 0xe0, 0x30, 0x30, 0x68, 0xd1, 0x63, 0x21, 0x20, 0x25, 0x32, 0x0e, 0xdc, 0x90, 0x00, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x10, 0x10, 0x11, 0x0f, 0x1f, 0x2e, 0x4f, 0x8f, 0x1f, 0x2f, 0x4f, 0x4f, 0x4b, 0x4d, 0x26, 0x63, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8e, 0x50, 0x70, 0xa1, 0x21, 0x1e, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x0a, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x09, 0x09, 0x10, 0xf0, 0xd0, 0x11, 0x22, 0x24, 0x18, 0x00, 0x00,
};

const uint8_t PROGMEM rabit_4[] = {//40, 40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x61, 0x81, 0x22, 0xcc, 0x30, 0x41, 0x86, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xb8, 0x04, 0x02, 0x01, 0x01, 0x00, 0xb1, 0x18, 0x59, 0xfa, 0x11, 0x80, 0x70, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x05, 0x64, 0xf0, 0xfc, 0xff, 0xf8, 0xf8, 0xfc, 0xbc, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0x38, 0x10, 0xc0, 0xe0, 0x20, 0x68, 0xd1, 0xe3, 0x21, 0x20, 0x25, 0x32, 0x0e, 0x2c, 0x40, 0x90, 0x00, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x10, 0x10, 0x11, 0x0f, 0x1f, 0x2e, 0x4f, 0x8f, 0x1f, 0x2f, 0x4f, 0x4f, 0x8b, 0x4d, 0x26, 0x63, 0x41, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x81, 0x4e, 0xd0, 0x20, 0x21, 0x21, 0x1e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x0a, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x69, 0x69, 0x30, 0x10, 0x10, 0x30, 0x23, 0x1c, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t PROGMEM rabit_5[] = {//40, 40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x19, 0x61, 0x82, 0x24, 0xc8, 0x31, 0x42, 0x84, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xb8, 0x04, 0x02, 0x01, 0x01, 0x00, 0xb1, 0x18, 0x59, 0xfa, 0x11, 0x84, 0x70, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x04, 0x70, 0xfc, 0xff, 0xf8, 0xf8, 0xf8, 0xfc, 0xbc, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0x38, 0x00, 0xc0, 0xe0, 0x20, 0x68, 0xd1, 0xe3, 0x21, 0x20, 0x25, 0x32, 0x0e, 0x2c, 0x40, 0x90, 0x00, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x10, 0x10, 0x11, 0x0f, 0x1f, 0x2e, 0x4f, 0x8f, 0x1f, 0x2f, 0x4f, 0x4f, 0x0b, 0x4d, 0x26, 0x63, 0x41, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x8e, 0x50, 0xe0, 0x21, 0x21, 0x1e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x0a, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x69, 0x69, 0x30, 0x10, 0x10, 0x10, 0x21, 0x22, 0x2c, 0x30, 0x00,
};

const uint8_t PROGMEM rabit_6[] = {//40, 40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x19, 0x61, 0x82, 0x24, 0xc8, 0x31, 0x40, 0x84, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 0x04, 0x02, 0x01, 0x01, 0x60, 0x31, 0xb0, 0xf1, 0x22, 0x01, 0xe4, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x04, 0x70, 0xfc, 0xff, 0xf8, 0xf8, 0xf8, 0xfc, 0xbc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0x7c, 0x10, 0xc0, 0xe0, 0x48, 0x51, 0xa2, 0xc6, 0x43, 0x40, 0x4b, 0x64, 0x3d, 0x18, 0xc0, 0x90, 0x90, 0x00, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x10, 0x10, 0x11, 0x0f, 0x0f, 0x2f, 0x4e, 0x8f, 0x1f, 0x2f, 0x4f, 0x4f, 0x4b, 0x4d, 0x46, 0x23, 0x11, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x10, 0xf0, 0xa1, 0xa1, 0x1e, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x28, 0x24, 0x12, 0x11, 0x70, 0xd0, 0xc8, 0x09, 0x06,
};

const uint8_t* rabbits[] = {
  rabit_1,
  rabit_2,
  rabit_3,
  rabit_4,
  rabit_5,
  rabit_6
};

const uint8_t* brokenEggLEFT[] = {
  eggLeft_Right, //10*12
  eggLeft_2, //11*10
  eggLeft_3, //14*13
  eggLeft_4, //13*10
  eggLeft_5, //11*10
  eggLeft_6, //12*12
};

const uint8_t* brokenEggRIGHT[] = {
  eggLeft_Right, //10*12
  eggRight_2, //11*10
  eggRight_3, //14*13
  eggRight_4, //13*10
  eggRight_5, //11*10
  eggRight_6, //12*12
};



void playClickSound();
void callingRabbit();

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.invert(true);

  //arduboy.display();

  //startScreen();
  brokenEggLeft();
  brokenEggRight();
  
  while (!arduboy.pressed(A_BUTTON)) {
    arduboy.idle();
  }

  multik();
  delay(1000);
  callingRabbit();

  arduboy.clear();
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }

  border;
  shelvesLines();
  arduboy.pollButtons();
  ////debug
  // arduboy.drawBitmap(0, 0, HandLeftUp, 27, 24, 1);
  // arduboy.drawBitmap(0, 38, HandLeftDown, 26, 24, 1);
  // arduboy.drawBitmap(100, 0, HandRightUp, 25, 26, 1);
  // arduboy.drawBitmap(100, 38, HandRightDown, 29, 24, 1);
  wolfMovements();
  arduboy.display();
}

void startScreen() {
  //border;
  ////RIGHT
  wolfLEFT;
  handLeftUP;
  handLeftDOWN;

  ////LEFT
  wolfRIGHT;
  handRightUP;
  handRightDOWN;
  arduboy.display();
}

////debug
void drawBitmapMirrored(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t w, uint8_t h, uint8_t color) {
  for (int16_t i = 0; i < h; i++) {
    for (int16_t j = 0; j < w / 2; j++) {
      uint8_t a = pgm_read_byte(bitmap + (i * w + j));
      uint8_t b = pgm_read_byte(bitmap + (i * w + w - 1 - j));
      for (int16_t k = 0; k < 8; k++) {
        uint8_t bitA = (a >> k) & 0x01;
        uint8_t bitB = (b >> k) & 0x01;
        uint8_t combinedPixels = (bitA << 1) | bitB;
        arduboy.drawPixel(x + (j * 8) + k, y + i, combinedPixels == 0b11 ? color : 0);
      }
    }
  }
}


////clearSprites
void clearSprite(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
  arduboy.fillRect(x, y, width, height, BLACK);

}

///leftSide
void clearWolfLeft() {
  clearSprite(39, 16, 31, 48);
  //arduboy.drawBitmap(39, 16, WolfLeft, 31, 48, 1);
  arduboy.drawRect(39, 16, 31, 48, BLACK);
}

void clearHandLeftUp() {
  clearSprite(25, 20, 27, 24);
  //arduboy.drawBitmap(25, 20, HandLeftUp, 27, 24, 1);
  arduboy.drawRect(25, 20, 27, 24, BLACK);
}

void clearHandLeftDown() {
  clearSprite(27, 37, 26, 24);
  //arduboy.drawBitmap(27, 37, HandLeftDown, 26, 24, 1);
  arduboy.drawRect(27, 37, 26, 24, BLACK);
}

///rightSide
void clearWolfRight() {
  clearSprite(53, 16, 27, 48);
  //arduboy.drawBitmap(53, 16, WolfRight, 27, 48, 1);
  arduboy.drawRect(53, 16, 27, 48, BLACK);
}

void clearHandRightUp() {
  clearSprite(77, 22, 25, 26);
  //arduboy.drawBitmap(77, 22, HandRightUp, 25, 26, 1);
  arduboy.drawRect(77, 22, 25, 26, BLACK);
}

void clearHandRightDown() {
  clearSprite(74, 40, 27, 21);
  //arduboy.drawBitmap(74, 40, HandRightDown, 27, 21, 1);
  arduboy.drawRect(25, 20, 27, 24, BLACK);
}

void shelvesLines() {
  arduboy.drawLine (0, 20, 24, 29, WHITE);
  arduboy.drawLine (0, 21, 24, 30, WHITE);
  arduboy.drawLine (0, 22, 24, 31, WHITE);
  arduboy.drawLine (0, 40, 24, 49, WHITE);
  arduboy.drawLine (0, 41, 24, 50, WHITE);
  arduboy.drawLine (0, 42, 24, 51, WHITE);
  arduboy.drawLine (103, 29, 127, 20, WHITE);
  arduboy.drawLine (103, 30, 127, 21, WHITE);
  arduboy.drawLine (103, 31, 127, 22, WHITE);
  arduboy.drawLine (103, 49, 127, 40, WHITE);
  arduboy.drawLine (103, 50, 127, 41, WHITE);
  arduboy.drawLine (103, 51, 127, 42, WHITE);
}

void wolfMovements() {
  if (arduboy.justPressed(UP_BUTTON)) {
    playClickSound();
    clearHandLeftDown();
    clearHandRightDown();
    clearHandRightUp();
    clearWolfRight();
    wolfLEFT;
    handLeftUP;
  }
  if (arduboy.justPressed(DOWN_BUTTON)) {
    playClickSound();
    clearHandLeftUp();
    clearHandRightUp();
    clearWolfRight();
    clearHandRightDown();
    wolfLEFT;
    handLeftDOWN;
  }
  if (arduboy.justPressed(B_BUTTON)) {
    playClickSound();
    clearWolfLeft();
    clearHandLeftUp();
    clearHandLeftDown();
    clearHandRightDown();
    wolfRIGHT;
    handRightUP;
  }
  if (arduboy.justPressed(A_BUTTON)) {
    playClickSound();
    clearWolfLeft();
    clearHandLeftUp();
    clearHandLeftDown();
    clearHandRightUp();
    wolfRIGHT;
    handRightDOWN;
  }
}


void multik() {
  int frameCount = 8;
  int frameDelay = 450;

  for (int i = 0; i < frameCount; i++) {
    arduboy.clear();
    if (i % 2 == 0) {
      handRightUP;
      wolfRIGHT;
    } else {
      handLeftUP;
      wolfLEFT;
    }
    arduboy.display();
    arduboy.delayShort(frameDelay);
    arduboy.fillRect(27, 16, 100, 64, BLACK);
  }
}

void eggAnimationLeft() {
    const int numFrames = 6;
    int timeDelay = 450;
    int frameX[numFrames] = { 53, 53, 39, 25, 12, 0 };
    int frameY[numFrames] = { 50, 50, 50, 50, 50, 50 };
    int frameWidth[numFrames] = {10, 11, 14, 13, 11, 12};
    int frameHeight[numFrames] = {12, 10, 13, 10, 10, 12};
    
    unsigned long frameDuration[numFrames] = { timeDelay, timeDelay, timeDelay, timeDelay, timeDelay, timeDelay };
    for (int frame = 0; frame < numFrames; frame++) {

      arduboy.drawBitmap(frameX[frame], frameY[frame], brokenEggLEFT[frame], frameWidth[frame], frameHeight[frame], WHITE);
      arduboy.display();
      delay(frameDuration[frame]);
   
      arduboy.fillRect(frameX[frame], frameY[frame], frameWidth, frameHeight, BLACK);
  }
}


void brokenEggLeft() {
  eggAnimationLeft();
}

void eggAnimationRight() {
    const int numFrames = 6;
    int timeDelay = 450;
    int frameX[numFrames] = { 66, 66, 78, 92, 105, 116 };
    int frameY[numFrames] = { 50, 50, 50, 50, 50, 50 };

    int frameWidth[numFrames] = {10, 11, 14, 13, 11, 12};
    int frameHeight[numFrames] = {12, 10, 13, 10, 10, 12};
    unsigned long frameDuration[numFrames] = { timeDelay, timeDelay, timeDelay, timeDelay, timeDelay, timeDelay };
  for (int frame = 0; frame < numFrames; frame++) {
    arduboy.drawBitmap(frameX[frame], frameY[frame], brokenEggRIGHT[frame], frameWidth[frame], frameHeight[frame], WHITE);
    arduboy.display();
    delay(frameDuration[frame]);
    // Очистка текущего кадра
    arduboy.fillRect(frameX[frame], frameY[frame], frameWidth, frameHeight, BLACK);
  }
}

void brokenEggRight() {
  eggAnimationRight();
}

void callingRabbit() {
  int frameCount = 6;
  int frameDelay = 300;

  for (int i = 0; i < frameCount; i++) {
    arduboy.fillRect(10, 0, RABBIT_WIDTH, RABBIT_HEIGHT, BLACK);
    arduboy.drawBitmap(10, 0, rabbits[i], RABBIT_WIDTH, RABBIT_HEIGHT, 1);
    arduboy.display();
    arduboy.delayShort(frameDelay);

    if ((i + 1) % 2 == 1) { // Если номер кадра нечетный
      playDinRabbit(); 
      } else {
      playDonRabbit(); 
    }
    //arduboy.fillRect(10, 0, RABBIT_WIDTH, RABBIT_HEIGHT, BLACK);
    //arduboy.drawRect(10, 0, RABBIT_WIDTH, RABBIT_HEIGHT, BLACK);
  }
}

void playDinRabbit() {
  int frameDelay = 30;
 // for (int i = 1568; i > 750; i--) {
  sound.tone(1568, 100); 
 // }
  arduboy.delayShort(frameDelay);
  sound.noTone();
}

void playDonRabbit() {
  int frameDelay = 30;
  //for (int i = 784; i > 600; i--) {
  sound.tone(784, 100); 
 // }
  arduboy.delayShort(frameDelay);
  sound.noTone();
}

////debug
void playBellRabbit_7(){
  int bellTones[] = {1568, 1319, 1175, 1047, 932, 880, 784};
  int bellTonesLength = sizeof(bellTones) / sizeof(int);

  for (int i = 0; i < bellTonesLength; i++) {
    sound.tone(bellTones[i], 100);
    delay(100);
  }
  
  sound.noTone();
}

void playClickSound() {
  for (int i = 1200; i > 250; i--) {
    sound.tone(i, 1);
  }
  sound.noTone();
}

void playEggCaughtSound() {
  for (int i = 1000; i > 900; i--) {
    sound.tone(i, 100);
  }
  sound.noTone();
}

void playEggBrokenSound() {
  for (int i = 0; i < 1000; i++) {
    sound.tone(random(2000, 10000), 250);
  }
  sound.noTone();
}

void playGameOverSound() {
  for (int i = 0; i < 2000; i++) {
    sound.tone(random(2000, 10000), 250);
  }
  sound.noTone();
}
