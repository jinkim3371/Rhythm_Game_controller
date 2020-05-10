/*  Last updated : 2020-05-10
    Key mapping :

    ButtonA     :  s      
    ButtonB     :  d
    ButtonC     :  f
    ButtonD     :  'Space'
    ButtonE     :  j
    ButtonF     :  k
    ButtonG     :  l
    ButtonH     :  'ESC'

    Edited by Jayden Kim.
*/

#include <Keyboard.h>

// assign pins for each button
int Bt_A = 1;
int Bt_B = 2;
int Bt_C = 3;
int Bt_D = 4;
int Bt_E = 5;
int Bt_F = 6;
int Bt_G = 7;
int Bt_H = 8;

// assign LED pins
int BTALED = 9;
int BTBLED = 10;
int BTCLED = 11;
int BTDLED = 12;
int BTELED = 13;
int BTFLED = 14;
int BTGLED = 15;
int BTHLED = 16;


void setup() {
//  HJpinMode(4, INPUT_PULLUP);   // START(I | 2)
  pinMode(Bt_A, INPUT_PULLUP);
  pinMode(Bt_B, INPUT_PULLUP);
  pinMode(Bt_C, INPUT_PULLUP);
  pinMode(Bt_D, INPUT_PULLUP);
  pinMode(Bt_E, INPUT_PULLUP);
  pinMode(Bt_F, INPUT_PULLUP);
  pinMode(Bt_G, INPUT_PULLUP);
  pinMode(Bt_H, INPUT_PULLUP);
  
  pinMode(BTALED, OUTPUT);
  pinMode(BTBLED, OUTPUT);
  pinMode(BTCLED, OUTPUT);
  pinMode(BTDLED, OUTPUT);
  pinMode(BTELED, OUTPUT);
  pinMode(BTFLED, OUTPUT);
  pinMode(BTGLED, OUTPUT);
  pinMode(BTHLED, OUTPUT);
}

void loop() {

  // Pin number of Keyboard
  int bControlA = digitalRead( Bt_A );
  int bControlB = digitalRead( Bt_B );
  int bControlC = digitalRead( Bt_C );
  int bControlD = digitalRead( Bt_D );
  int bControlE = digitalRead( Bt_E );
  int bControlF = digitalRead( Bt_F );
  int bControlG = digitalRead( Bt_G );
  int bControlH = digitalRead( Bt_H );
  
  ////////// button A //////////========================
  if (bControlA == LOW) {
    Keyboard.press('s');
    digitalWrite(BTALED, HIGH);
  }
  else {
    Keyboard.release('s');
    digitalWrite(BTALED, LOW);
  }
 
  ////////// button B //////////========================
  if (bControlB == LOW) {
    Keyboard.press('d');
    digitalWrite(BTBLED, HIGH);
  }
  else {
    Keyboard.release('d');
    digitalWrite(BTBLED, LOW);
  }

  ////////// button C //////////========================
  if (bControlC == LOW) {
    Keyboard.press('f');
    digitalWrite(BTCLED, HIGH);
  }
  else {
    Keyboard.release('f');
    digitalWrite(BTCLED, LOW);
  }

  ////////// button D //////////========================              # SPACE   <<<< NEED TO CHECK 
  if (bControlD == LOW) {
    Keyboard.press(' ');
    digitalWrite(BTDLED, HIGH);
  }
  else {
    Keyboard.release(' ');
    digitalWrite(BTDLED, LOW);
  }
  
  ////////// button E //////////========================
  if (bControlE == LOW) {
    Keyboard.press('j');
    digitalWrite(BTELED, HIGH);
  }
  else {
    Keyboard.release('j');
    digitalWrite(BTELED, LOW);
  }
 
  ////////// button F //////////========================
  if (bControlF == LOW) {
    Keyboard.press('k');
    digitalWrite(BTFLED, HIGH);
  }
  else {
    Keyboard.release('k');
    digitalWrite(BTFLED, LOW);
  }

  ////////// button G //////////========================
  if (bControlG == LOW) {
    Keyboard.press('k');
    digitalWrite(BTGLED, HIGH);
  }
  else {
    Keyboard.release('k');
    digitalWrite(BTGLED, LOW);
  }

  ////////// button H //////////========================              # ESC   <<<< NEED TO CHECK 
  if (bControlH == LOW) {
    Keyboard.press( 0xB1 );
    digitalWrite(BTHLED, HIGH);
  }
  else {
    Keyboard.release( 0xB1 );
    digitalWrite(BTHLED, LOW);
  }
  delay(10);
}
