/* TinyTone for ATtiny85 */

// Notes
const int Note_C  = 239;
const int Note_CS = 225;
const int Note_D  = 213;
const int Note_DS = 201;
const int Note_E  = 190;
const int Note_F  = 179;
const int Note_FS = 169;
const int Note_G  = 159;
const int Note_GS = 150;
const int Note_A  = 142;
const int Note_AS = 134;
const int Note_B  = 127;

int Speaker = 1;

void setup()
{
  pinMode(Speaker, OUTPUT);
  pinMode(0,INPUT_PULLUP);
   pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
  
  
}

void loop()
{
  //playTune1();
  if(digitalRead(0)==0)
  {
   TinyTone(Note_C, 4, 100);
 TinyTone(Note_D, 4, 100);  
  }
  if(digitalRead(2)==0)
  {
   TinyTone(Note_E, 4, 100);
 TinyTone(Note_F, 4, 100);  
 TinyTone(Note_G, 4, 100);
  }
  if(digitalRead(3)==0)
  {
   
 TinyTone(Note_A, 4, 100); 
 TinyTone(Note_B, 4, 100);  
 TinyTone(Note_C, 4, 100);
  }

  //delay(10000);
}

void TinyTone(unsigned char divisor, unsigned char octave, unsigned long duration)
{
  TCCR1 = 0x90 | (8-octave); // for 1MHz clock
   //TCCR1 = 0x90 | (11-octave); // for 8MHz clock
  OCR1C = divisor-1;         // set the OCR
  delay(duration);
  TCCR1 = 0x90;              // stop the counter
}

// Play a scale
void playTune(void)
{
 TinyTone(Note_C, 4, 500);
 TinyTone(Note_D, 4, 500);
 TinyTone(Note_E, 4, 500);
 TinyTone(Note_F, 4, 500);
 TinyTone(Note_G, 4, 500);
 TinyTone(Note_A, 4, 500);
 TinyTone(Note_B, 4, 500);
 TinyTone(Note_C, 5, 500);
}

void playTune1(void)
{
 TinyTone(Note_CS, 4, 500);
 TinyTone(Note_DS, 4, 500);
 TinyTone(Note_E, 4, 500);
 TinyTone(Note_FS, 4, 500);
 TinyTone(Note_GS, 4, 500);
 TinyTone(Note_AS, 4, 500);
 TinyTone(Note_B, 4, 500);
 TinyTone(Note_C, 5, 500);
}
