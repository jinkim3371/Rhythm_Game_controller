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
int Bt_A = 2;
int Bt_B = 3;
int Bt_C = 4;
int Bt_D = 5;
int Bt_E = 6;
int Bt_F = 7;
int Bt_G = 8;
int Bt_H = 9;




// assign LED pins
int BTALED = 10;
int BTBLED = 11;
int BTCLED = 12;
int BTDLED = 14;
int BTELED = 15;
int BTFLED = 16;
int BTGLED = 17;
int BTHLED = 18;


#define clpin 1
#define dtpin 0
#define swpin 21

int encoderVal = 0;
static int oldA = HIGH;
static int oldB = HIGH;



void setup() {
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

  pinMode (clpin, INPUT_PULLUP);
  pinMode (dtpin, INPUT_PULLUP);
  pinMode (swpin, INPUT);
  digitalWrite (swpin, HIGH);
  Serial.begin(9600);
  
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
    Keyboard.press('l');
    digitalWrite(BTGLED, HIGH);
  }
  else {
    Keyboard.release('l');
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

  ////////// Encoder //////////========================   
  int change = getEncoderTurn();
  encoderVal = encoderVal + change;
  if (change > 0){
    Keyboard.press( '+' ); 
  }
  else {
    Keyboard.release( '+' );
  }
  if (change < 0){
    Keyboard.press( '-' ); 
  }
  else {
    Keyboard.release( '-' );
  }

            
  if (digitalRead(swpin) == LOW)
  {
    Keyboard.press( 0xB0 );
  }
  else {
    Keyboard.release( 0xB0 );
  }



  
  delay(10);
}




int getEncoderTurn(void)
{
  int result = 0;
  int newA = digitalRead(clpin);
  int newB = digitalRead(dtpin);
  if (newA != oldA || newB != oldB)
  {
    if (oldA == HIGH && newA == LOW)
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}

