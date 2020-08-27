#define LS1 A0
#define LS2 A1
#define LS3 A2   
#define RS1 A3
#define RS2 A4
#define RS3 A5 
#define LM1 3      
#define LM2 5      
#define RM1 6       
#define RM2 11       
const int trigPin = 9;
const int echoPin = 10;


long duration;
int distance;


void setup()
{ 
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);
  pinMode(LS3, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(RS3, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
 
}



int dist() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);
return(distance);
}
void check()
{
  if(dist()<=12)
  {
  
   digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    digitalWrite(12, LOW);
    
    
  check();
  }
}

int left()
{
 
  return(digitalRead(LS1)+digitalRead(LS2)+digitalRead(LS3));
  
}
int right()
{

  return(digitalRead(RS1)+digitalRead(RS2)+digitalRead(RS3));
 
}
void loop()
{

 
  check();
  if(left() == right())     
  {
  analogWrite(LM1, 150);
    analogWrite(LM2, 0);
    analogWrite(RM1, 150);
    analogWrite(RM2, 0);
  }
  
  else if((left() < right()))     
  {
    analogWrite(LM1, 0);
    analogWrite(LM2, 255);
    analogWrite(RM1, 255);
    analogWrite(RM2, 0);
    delay(100);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(100);
  }
  
  else if((left()) > (right()))   
  {
    analogWrite(LM1, 255);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 255);
     delay(100);
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(100);
  }
  
   else if(((left()==4) && (right()==4)))     
  {
   analogWrite(LM1, 0);
    analogWrite(LM2, 255);
    analogWrite(RM1, 255);
    analogWrite(RM2, 0);
  }
  
  if(((left()==0) && (right()==0)))     
  {
   analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
   
  

}
}