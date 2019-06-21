
/* Copyright (c) 2010-2015, Peter Barrett
 **
 ** Permission to use, copy, modify, and/or distribute this software for
 ** any purpose with or without fee is hereby granted, provided that the
 ** above copyright notice and this permission notice appear in all copies.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 ** WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 ** WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
 ** BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
 ** OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 ** WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 ** ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 ** SOFTWARE.
 */

#include "config.h"

//==============================================================
//==============================================================

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
    pinMode(pin_btn_up,INPUT_PULLUP); //Joystick UP atari
    pinMode(pin_btn_down,INPUT_PULLUP); //Joystick DOWN atari
    pinMode(pin_btn_left,INPUT_PULLUP); //Joystick LEFT atari
    pinMode(pin_btn_right,INPUT_PULLUP); //Joystick RIGHT atari
    //pinMode(pin_btn_fire,INPUT_PULLUP); //Joystick FIRE atari
  
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
