
#ifndef __ARUINOCADE__H__
#define __ARUINOCADE__H__

 // #define _use_ir_original
 #define _not_sound
 //Joystick atari simple buttons pullup ground
 //#define _use_gamepad_atari
 //gamepad nes
 #define _use_gamepad_nes
 
 #ifdef _use_gamepad_atari
//   X  Right 
//   |  |  Left 
//   |  |  |  Back 
//   |  |  |  |  Up 
//   |  |  |  |  |                 
//____________________            
//\  o5 o4 o3 o2 o1  /             
// \  o9 o8 o7 o6   /                
//  ----------------                 
//    |  |  |  |                   
//    |  |  |  Fire      
//    |  |  +5V            
//    |  Ground 
//    X 
  //colour db9-1 UP orange
  //colour db9-2 DOWN blue
  //colour db9-3 LEFT red
  //colour db9-4 RIGHT yellow 
  #define pin_btn_up 14
  #define pin_btn_down 15
  #define pin_btn_left 16
  #define pin_btn_right 17
  // #define pin_btn_fire 18
 #endif
 
 //color pin strobe blue
 //color pin clock green
 //color pin data yellow 
 #ifdef _use_gamepad_nes
//        __________
//	 /          |
//	/       O 1 |   1 - Ground
//      |           |   2 - Clock
//      | 7 O   O 2 |   3 - Latch
//	|           |	4 - Data Out
//	| 6 O   O 3 |	5 - No Connection
//	|           |   6 - No Connection
//	| 5 O   O 4 |   7 - +5V
//	|___________| 
  #define pin_nes_strobe 14
  #define pin_nes_clock 15
  #define pin_nes_data 16
 
  #define NES_A       B00000001
  #define NES_B       B00000010
  #define NES_SELECT  B00000100
  #define NES_START   B00001000
  #define NES_UP      B00010000
  #define NES_DOWN    B00100000
  #define NES_LEFT    B01000000
  #define NES_RIGHT   B10000000  
 #endif
 

// If you want to build BALLBLASTER
//#define BALLBLASTER_GAME

// PICK A CONTROLLER
#define ATARI_FLASHBACK
//#define RETCON
//#define APPLE_TV

#ifdef ARDUINO
#include <Arduino.h>
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#define SPRITEPTR const uint8_t*
#define GET_SPRITE(_n) _sprite_ptrs[_n]

#else   // Building in simulator
#define PROGMEM
#define prog_char char
#define pgm_read_byte(_x) *(_x)
#define pgm_read_word(_x) *(_x)
#define strcpy_P strcpy
#define memcpy_P memcpy
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <unistd.h>

#define SPRITEPTR const uint8_t*
#define GET_SPRITE(_n) (const uint8_t*)_sprite_ptrs[_n]

#endif

// joystick bits

#define FIRE_X  0x800 
#define FIRE_Y  0x400 
#define FIRE_Z  0x200

#define FIRE_C  0x080 // also START
#define FIRE_B  0x040 // also SELECT
#define FIRE_A  0x020 // also FIRE

#define RESET 	0x100
#define START 	0x080
#define SELECT 	0x040
#define FIRE 	0x020
#define RIGHT 	0x010
#define LEFT 	0x008
#define DOWN 	0x004
#define UP      0x002
#define MENU    0x001

uint16_t* readJoy();
extern uint8_t v_framecounter;
extern int video_current_line();
void flush_video(bool cb);

class Game
{
public:
    Game();
    virtual void init()=0;
    virtual void step()=0;
    virtual void draw() = 0;    // loop?
    virtual uint8_t get_tile(uint8_t x, uint8_t y)=0;
};

void video_start();     // TODO: Game member?
Game* current_game();   // TODO: Game member?

#endif
