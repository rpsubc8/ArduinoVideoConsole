//* Copyright (c) 2009-2015, Peter Barrett
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

// wukka
// Period of 300ms or 18 frames
// 5 on, 3 off
// 1000->500 84 STEP -3
// 500->1000 69 STEP 3
#include "config.h"
#include "video.h"
#include "nescontroller.h"

#ifdef BALLBLASTER_GAME
#error Please undefine BALLBLASTER_GAME in arduinocade/config.h
#endif

#ifndef u8
typedef unsigned char u8;
typedef unsigned char byte;
typedef unsigned short u16;
typedef unsigned short ushort;
typedef unsigned long u32;
#endif

#ifdef _use_gamepad_nes
 //NESpad nintendo = NESpad(pin_nes_strobe,pin_nes_clock,pin_nes_data);
 byte nes_state = 0;
 byte NESreadButtons(void);
 inline byte NESshiftin(void);
 inline void NESstrobe(void);
#endif

extern uint16_t v_underflow;

//#define FPS 60
#define FPS 60



#define HTILEOFFSET 2



class Nescontroller : public Game
{
    //byte _dotMap[32*24/8];      // TODO Bounds
    byte _dotMap[96];      // TODO Bounds
    ushort _dots;
        
    #define COLS 40
    VRowTiles _rows[4];
    uint8_t _buf[COLS*4];       // Could be trimmed down if need be

public:
    byte GetTile(int cx, int cy)
    {
        return pgm_read_byte(_map + cy*32 + cx);
    }
                          
        
    virtual void init()
    {
        memset(_buf,1,sizeof(_buf));                
        //  Init dots from rom
        byte* map = _dotMap;
        _dots = 0;
        memset(_dotMap,0,sizeof(_dotMap));
/*        for (int i = 0; i < 32*24; i++) {
            byte t = pgm_read_byte(_map + i);
            if (t == DOT || t == PILL) {
                map[i>>3] |= (0x80 >> (i&7));
                _dots++;
            }
        }*/
    }

    
    
    //
    virtual uint8_t get_tile(uint8_t x, uint8_t y)
    {
        if (x < HTILEOFFSET)
            return 1;
        x -= HTILEOFFSET;
       //     return ((x+y)& 1) + 1;

        int i = y*32+x;
        uint8_t t = pgm_read_byte(_map + i);
        /*if (t == DOT || t == PILL)
        {
            if (!(_dotMap[i >> 3] & (0x80 >> (i&7))))
                t = 1;
        }*/
        return t;
    }
    
//  Draw playfield by inserting 1 row at a time.
//  Rows are quad buffered

    virtual void step()
    {
     nes_state = NESreadButtons();
    }

    virtual void draw()
    {
        // Wait for blanking
        // Normally don't need to if stepping frame took long enough                       
        // Init tile line buffers        
        for (uint8_t r = 0; r < 4; r++)
        {
            VRowTiles* row = _rows + r; // 4 bufs
            row->row.mode = VMODE_TILES;
            row->rom_font = _tiles;
            row->rom_font_count = sizeof(_tiles)/16;
            row->tiles = _buf + r*COLS;
            row->v_scroll = 0;
        }

        // Draw
        for (uint8_t r = 0; r < 24; r++)
        {
            VRowTiles* row = _rows + (r&3);             // 2 bufs
            while (video_queue_count() == 4)
              ;
            row->row.y = (r << 3) + 7;
            for (uint8_t x = 0; x < 32; x++)
            {
//              row->tiles[x] = 1; //esmeralda
                row->tiles[x] = get_tile(x,r);
            }
                        
            row->tiles[32] = 0;
            

             if (r==12){
               if (nes_state & NES_UP)
                row->tiles[9] = 57;                
             }
             else{
              if (r==13){
               if (nes_state & NES_LEFT)
                row->tiles[8] = 57;
               if (nes_state & NES_RIGHT)
                row->tiles[10] = 57;
              }
              else{
               if (r==14){
                if (nes_state & NES_DOWN)
                 row->tiles[9] = 57;
                if (nes_state & NES_SELECT)
                 row->tiles[13] = 57;                 
                if (nes_state & NES_START)
                 row->tiles[15] = 57;       
                if (nes_state & NES_B)
                 row->tiles[18] = 57;                  
                if (nes_state & NES_A)
                 row->tiles[20] = 57;                              
               }
              }
             }
             
            // Patch special lines
/*            switch (r) {
                case 0:
//                    for (uint8_t x = 2; x < 10; x++)
//                        row->tiles[x] = _scoreStr[x-2];   // SCORE
                    break;
                case 13:
//                    if (_state == ReadyState)
//                        for (uint8_t x = 15; x < 21; x++)
//                            row->tiles[x] = x + 58-15;   // READY
                    break;
                case 23:
//                    for (uint8_t x = 0; x < 5; x++)
//                        row->tiles[x+3] = (x < _lives) ? 20:1;    // REMAINING LIVES
                    break;

            }*/
//            row->ram_font = sprite_draw(row->tiles,r);  // Render sprites for this row
            video_enqueue((VRow*)row);
        }
        
        // don't need to wait
    }
    
};

Nescontroller _nescontroller;
