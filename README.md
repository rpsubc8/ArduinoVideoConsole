# Arduino Video Console demoscene
<h1>Retro diskmag EXILIUM port Arduino</h1>
Video console emulate with Arduino

<h1>Change</h1>
You choose to use the Arduinocade hardware (https://github.com/rossumur/Arduinocade), and modify the libraries and utilities:
The sprite editing tool is allowed to use the background color with the right mouse button, while the left is the foreground. This allows you to draw more quickly.
<br><br>
Add support to load chr A (base64 16 colours) in tile.
<br><br>
Add support to load Map (automatic sprite to tiles and map 40x24).
<center><img src="previewArduinocade.png"></center>
<center><img src="previewMap.png"></center>

Demostration with Arduino uno chino with ch340. Change power supply external to 5.2v to get hsync correct. cut the temples of the crystal to the minimum.
<center><img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/arduinochinoAlimentacionExterna.jpg'></center>

<center><img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/chinocolor.jpg'></center>

<h1>Hardware</h1>
<ul>
 <li>Arduino atmega328</li>
 <li>crystal 28.6363 Mhz</li>
 <li>crystal 16 Mhz</li>
 <li>switch crystals</li>
 <li>i2C eprom 24LC256</li>
 <li>1 rca video</li>
 <li>1 jack audio output mono</li>
 <li>gamepad atari 5 buttons</li>
 <li>gamepad nes</li>
 <li>gamepad snes</li>
 <li>audio input 1wire capacitor to transfer program</li>
 <li>bootloader i2c eprom</li>
 <li>16 colours up 27 colours opcional</li>
 <li>NTSC colour</li>
 <li>tilemap 40x24</li>
 <li>sprites 4x8 pixels</li>
 <li>resolution 160x192</li>
</ul>


<h1>Gamepad simple swith</h1>
I have made a trial version that uses buttons in ground pullpup mode. I used the pins:
<ul>
 <li>A0 (pin 14) UP</li>
 <li>A1 (pin 15) DOWN</li>
 <li>A2 (pin 16) LEFT</li>
 <li>A3 (pin 17) RIGTH</li>
</ul>

It is defined in the file config.h

In file arduinocade.cpp, setup pullup input:

void setup()
{
    pinMode(pin_btn_up,INPUT_PULLUP); //Joystick UP atari
    pinMode(pin_btn_down,INPUT_PULLUP); //Joystick DOWN atari
    pinMode(pin_btn_left,INPUT_PULLUP); //Joystick LEFT atari
    pinMode(pin_btn_right,INPUT_PULLUP); //Joystick RIGHT atari  
    ...

}


And file PACMAN.INO

byte ChooseDir(int dir, Sprite* s)
{
 ....
            if (choice[0] != 0x7FFF && (digitalRead(pin_btn_up)==LOW)) return MUp;
            if (choice[1] != 0x7FFF && (digitalRead(pin_btn_left)==LOW)) return MLeft;
            if (choice[2] != 0x7FFF && (digitalRead(pin_btn_down)==LOW)) return MDown;
            if (choice[3] != 0x7FFF && (digitalRead(pin_btn_right)==LOW)) return MRight;
}


Remove or comment call joystick IR and Intelligent Artificial
//test        if (_ai && *readJoy()) {














<h1>First prototype (deprecated)</h1>
Minimum videoconsole (one chip) ARDUINO (ATMEGA 328P) with video TV output (DAC R2R 4 bits 16 colors grayscale), and sound (DAC R2R 4 bits)<br>
<img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/previewVideoconsola.png'>
<img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/previewVideoconsola2.png'>
<img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/previewVideoconsola3.png'><br>
Parser emulator in Javascript, which allows you to generate a game with the different video modes:
<ul>
 <li>84x48 (framebuffer 4 and 8 colors)</li>
 <li>84x64 (framebuffer 4 colors)</li>
 <li>96x64 (framebuffer 4 colors)</li>
 <li>96x96 (tiles)</li>
 <li>128x96 (tiles)</li>
 <li>128x128 (tiles)</li>
 <li>256x128 (tiles)</li>
 <li>480x240 (tiles)</li>
</ul>
 Tiles mode combination with framebuffer.<br>
 With code in JS and P5JS, video output can be simulated, allowing intermediate C code for Arduino, which can later be compiled and viewed in real chip.<br><br>
 It uses a hardware similar to the TVOUT of arduino, but with multiple improvements, to be able to support 16 shades of gray.<br><br>
 Old diskmag <a href='http://www.pouet.net/prod.php?which=5967'>EXILIUM</a> port for minimal hardware chip ATMEGA328 (32 KB) gfx text mode.

 




<h1>State project</h1>
In development


Videoconsola minima (un solo chip) ARDUINO (ATMEGA 328P) con salida de video TV (DAC R2R 4 bits 16 colours escala de grises), and sound (DAC R2R 4 bits)
Emulador Parser en Javascript, que permite generar un juego con los diferentes modos de videos:
<ul>
 <li>84x48 (framebuffer 4 y 8 colores)</li>
 <li>84x64 (framebuffer 4 colores)</li>
 <li>96x64 (framebuffer 4 colores)</li>
 <li>96x96 (tiles)</li>
 <li>128x96 (tiles)</li>
 <li>128x128 (tiles)</li>
 <li>256x128 (tiles)</li>
 <li>480x240 (tiles)</li>
 </ul>
 Combinacion de modo Tiles con framebuffer.

 Con codigo en JS y P5JS, se puede simular la salida de video, permitiendo generar código intermedio en C para Arduino, que posteriormente se puede compilar y ver en chip real.

 Se utiliza un hardware similar al TVOUT de arduino, pero con múltiples mejoras, al poder soportar 16 tonalidades de gris.
 Se portará la vieja diskmag multiplataforma EXILIUM de mi grupo SLIDERS a un chip ATMEGA328 (32 KB).
