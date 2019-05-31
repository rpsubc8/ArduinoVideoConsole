# ArduinoVideoConsole demoscene
<h1>Retro diskmag EXILIUM port Arduino</h1>
Video console emulate with Arduino

<h1>Change</h1>
You choose to use the Arduinocade hardware (https://github.com/rossumur/Arduinocade), and modify the libraries and utilities:
The sprite editing tool is allowed to use the background color with the right mouse button, while the left is the foreground. This allows you to draw more quickly.

<h1>Hardware</h1>
 - Arduino atmega328
 - crystal 28.6363 Mhz
 - crystal 16 Mhz
 - switch crystals
 - i2C eprom 24LC256
 - 1 rca video
 - 1 jack audio output mono 
 - gamepad atari 5 buttons
 - gamepad nes
 - gamepad snes 
 - audio input 1wire capacitor to transfer program
 - bootloader i2c eprom
 - 16 colours up 27 colours opcional
 - NTSC colour
 - tilemap 40x24
 - sprites 4x8 pixels
 - resolution 160x192


<h1>First prototype (deprecated)</h1>
Minimum videoconsole (one chip) ARDUINO (ATMEGA 328P) with video TV output (DAC R2R 4 bits 16 colors grayscale), and sound (DAC R2R 4 bits)<br>
<img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/previewVideoconsola.png'>
<img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/previewVideoconsola2.png'>
<img src='https://github.com/rpsubc8/ArduinoVideoConsole/blob/master/previewVideoconsola3.png'><br>
Parser emulator in Javascript, which allows you to generate a game with the different video modes:
 - 84x48 (framebuffer 4 and 8 colors) 
 - 84x64 (framebuffer 4 colors)
 - 96x64 (framebuffer 4 colors) 
 - 96x96 (tiles)
 - 128x96 (tiles)
 - 128x128 (tiles)
 - 256x128 (tiles)
 - 480x240 (tiles)
 Tiles mode combination with framebuffer.<br>
 With code in JS and P5JS, video output can be simulated, allowing intermediate C code for Arduino, which can later be compiled and viewed in real chip.<br><br>
 It uses a hardware similar to the TVOUT of arduino, but with multiple improvements, to be able to support 16 shades of gray.<br><br>
 Old diskmag <a href='http://www.pouet.net/prod.php?which=5967'>EXILIUM</a> port for minimal hardware chip ATMEGA328 (32 KB) gfx text mode.





Videoconsola minima (un solo chip) ARDUINO (ATMEGA 328P) con salida de video TV (DAC R2R 4 bits 16 colours escala de grises), and sound (DAC R2R 4 bits)
Emulador Parser en Javascript, que permite generar un juego con los diferentes modos de videos:
 - 84x48 (framebuffer 4 y 8 colores)
 - 84x64 (framebuffer 4 colores)
 - 96x64 (framebuffer 4 colores)
 - 96x96 (tiles)
 - 128x96 (tiles)
 - 128x128 (tiles)
 - 256x128 (tiles)
 - 480x240 (tiles)
 Combinacion de modo Tiles con framebuffer.

 Con codigo en JS y P5JS, se puede simular la salida de video, permitiendo generar código intermedio en C para Arduino, que posteriormente se puede compilar y ver en chip real.

 Se utiliza un hardware similar al TVOUT de arduino, pero con múltiples mejoras, al poder soportar 16 tonalidades de gris.
 Se portará la vieja diskmag multiplataforma EXILIUM de mi grupo SLIDERS a un chip ATMEGA328 (32 KB).
