// C++ code
//
void setup()
{
 Serial.begin(9600);
 pinMode(2,INPUT);
 pinMode(12,OUTPUT);
  
}

void loop()
{
  int motion=digitalRead(2);
  if(motion==1)
  {
    Serial.println("Motion is detected !");
    tone(12,10);
    delay(1000);
    noTone(12);
    delay(3000);
  }
  else
  {
    Serial.println("No Motion !!!");
    delay(1000);
  }
  double data=analogRead(A2);
  double n=data/1024;
  double voltage=n*5;
  double offsetvol=voltage-0.5;
  double temp=offsetvol*100;
  if(temp>60)
  {
    Serial.println("Temperature is greater than 60 degrees !");
    Serial.println(temp);
    tone(12,100);
    delay(1000);
    noTone(12);
    delay(3000);
  }
  else
  {
	Serial.println("Temperature is less than 60 degrees !!!");
    Serial.println(temp);
    delay(1000);
  }
}