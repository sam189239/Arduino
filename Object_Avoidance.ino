#define RS A0
#define LS A1
#define BS A2   

#define LM1 3      
#define LM2 5      
#define RM1 6       
#define RM2 11       



void setup()
{ 
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(BS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  Serial.begin(9600);
 
}

void loop()
{
    if(!digitalRead(LS) && !digitalRead(RS) && !digitalRead(BS))
    {
        analogWrite(LM1, 255);
        analogWrite(LM2, 0);
        analogWrite(RM1, 255);
        analogWrite(RM2, 0);
    }   

    else if(!digitalRead(LS) && !digitalRead(RS) && digitalRead(BS))
    {
        analogWrite(LM1, 255);
        analogWrite(LM2, 0);
        analogWrite(RM1, 255);
        analogWrite(RM2, 0);
        delay(1000);
        analogWrite(LM1, 0);
        analogWrite(LM2, 0);
        analogWrite(RM1, 0);
        analogWrite(RM2, 0);
    }

    else if(digitalRead(RS))
    {
        analogWrite(LM1, 0);
        analogWrite(LM2, 255);
        analogWrite(RM1, 0);
        analogWrite(RM2, 255);
        delay(2000);
        analogWrite(LM1, 0);
        analogWrite(LM2, 255);
        analogWrite(RM1, 255);
        analogWrite(RM2, 0);
        delay(800);
        analogWrite(LM1, 0);
        analogWrite(LM2, 0);
        analogWrite(RM1, 0);
        analogWrite(RM2, 0);
    }
    
    else if(digitalRead(LS))
    {
        analogWrite(LM1, 0);
        analogWrite(LM2, 255);
        analogWrite(RM1, 0);
        analogWrite(RM2, 255);
        delay(2000);
        analogWrite(LM1, 255);
        analogWrite(LM2, 0);
        analogWrite(RM1, 0);
        analogWrite(RM2, 255);
        delay(800);
        analogWrite(LM1, 0);
        analogWrite(LM2, 0);
        analogWrite(RM1, 0);
        analogWrite(RM2, 0);
    }

    else if(digitalRead(LS) && digitalRead(RS) && digitalRead(BS))
    {
        analogWrite(LM1, 0);
        analogWrite(LM2, 0);
        analogWrite(RM1, 0);
        analogWrite(RM2, 0);
    }
    
}

