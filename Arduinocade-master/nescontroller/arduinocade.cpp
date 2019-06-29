
//* Copyright (c) 2010-2015, Peter Barrett
//** Mod by ackerman Jaime Jose Gavin Sierra
//**
//** Permission to use, copy, modify, and/or distribute this software for
//** any purpose with or without fee is hereby granted, provided that the
//** above copyright notice and this permission notice appear in all copies.
//**
//** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
//** WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
//** WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
//** BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
//** OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
//** WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
//** ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
//** SOFTWARE.
//*

#include "config.h"

//==============================================================
//==============================================================

#ifdef _use_gamepad_nes
 inline void NESstrobe(void)
 {
  digitalWrite(pin_nes_strobe,HIGH);
  //delayMicroseconds(22); //12 ms in 28.6363 mhz = 1,78976875 = 21,477225 = 22 ms
  digitalWrite(pin_nes_strobe,LOW);
 }

 inline byte NESshiftin(void)
 {
  byte ret = digitalRead(pin_nes_data);
  //delayMicroseconds(22); //remove delay test
  digitalWrite(pin_nes_clock,HIGH);
  //delayMicroseconds(22);
  digitalWrite(pin_nes_clock,LOW);
  return ret;
 }

 byte NESreadButtons(void)
 {
  byte ret = 0;
  byte i;
  NESstrobe();
  for (i = 0; i < 8; i++) {
    ret |= NESshiftin() << i;
  }
  return ~ret;   
 }
#endif

Game* _current_game = 0;
Game::Game()
{
    _current_game = this;
}

Game* current_game()   // TODO: Game member?
{
    return _current_game;
}

void setup()
{    
   #ifdef _use_gamepad_atari
    pinMode(pin_btn_up,INPUT_PULLUP); //Joystick UP atari
    pinMode(pin_btn_down,INPUT_PULLUP); //Joystick DOWN atari
    pinMode(pin_btn_left,INPUT_PULLUP); //Joystick LEFT atari
    pinMode(pin_btn_right,INPUT_PULLUP); //Joystick RIGHT atari
    //pinMode(pin_btn_fire,INPUT_PULLUP); //Joystick FIRE atari
   #endif
      
   #ifdef _use_gamepad_nes
    pinMode(pin_nes_strobe,OUTPUT);
    pinMode(pin_nes_clock,OUTPUT);
    pinMode(pin_nes_data,INPUT_PULLUP);
    //NESstrobe();
   #endif
  
    _current_game->init();
    video_start();
}

//int _counter = 0;
void loop()
{
    _current_game->step();
    _current_game->draw();
    //_counter++;
}
