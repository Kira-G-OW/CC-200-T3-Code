
#define btnPin_ArrowLeft 1
#define btnPin_ArrowRight 2
#define btnPin_ArrowUp 3
#define btnPin_ArrowDown 4
#define btnPin_ShiftRight 5
#define btnPin_ShiftLeft 6
#define btnPin_Space 7
#define btnPin_ExtApp 8
// #define scrollWheel 9 (Still figuring out this scroll wheel)

uint8_t buf[8] = { 0 }; //Keyboard Report buffer

byte lastBtnState = 0; //btn toggle

void setup() 
{
  Serial.begin(9600);

  pinMode(btnPin_ArrowLeft, INPUT);
  pinMode(btnPin_ArrowRight, INPUT);
  pinMode(btnPin_ArrowUp, INPUT);
  pinMode(btnPin_ArrowDown, INPUT);
  pinMode(btnPin_ShiftRight, INPUT);
  pinMode(btnPin_ShiftLeft, INPUT);
  pinMode(btnPin_Space, INPUT);
  pinMode(btnPin_ExtApp, INPUT);

}

void loop() 
{
  arrowLeft();
  arrowRight();
  arrowUp();
  arrowDown();
  shiftLeft();
  shiftRight();
  space();
  
  releaseKey();
}


void arrowLeft()
{
  if (digitalRead(btnPin_ArrowLeft)== 0) 
  {
  buf[2] = 0x50;
  Serial.write(buf, 8);
  releaseKey();
  }
}


void arrowRight()
{
  if (digitalRead(btnPin_ArrowRight)== 0) 
  {
  buf[2] = 0x4F;
  Serial.write(buf, 8);
  releaseKey();
  }
}


void arrowUp()
{
  if (digitalRead(btnPin_ArrowUp)== 0) 
  {
  buf[2] = 0x52;
  Serial.write(buf, 8);
  releaseKey();
  }
}


void arrowDown()
{
  if (digitalRead(btnPin_ArrowDown)== 0) 
  {
  buf[2] = 0x51;
  Serial.write(buf, 8);
  releaseKey();
  }
}


void shiftLeft()
{
  if (digitalRead(btnPin_ShiftLeft)== 0) 
  {
  buf[2] = 0xE1;
  Serial.write(buf, 8);
  releaseKey();
  }
}


void shiftRight()
{
  if (digitalRead(btnPin_ShiftRight)== 0) 
  {
  buf[2] = 0xE5;
  Serial.write(buf, 8);
  releaseKey();
  }
}


void space()
{
  if (digitalRead(btnPin_Space)== 0) 
  {
  buf[2] = 0x2C;
  Serial.write(buf, 8);
  releaseKey();
  }
}


// void extApp()
// {
//   if (digitalRead(btnPin_ExtApp)== 0) 
//   {
//   buf[2] = ; //I'm still figuring this out
//   Serial.write(buf, 8);
//   releaseKey();
//   }
// }


// void scroll()
// {
//   if (digitalRead(btnPin_scroll)== 0) 
//   {
//   buf[2] = ; //I'm still figuring this out
//   Serial.write(buf, 8);
//   releaseKey();
//   }
// }



void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}








