int val;
int tempPin = 0;
int redpin= 5;
int greenpin= 9;
int bluepin= 6;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(tempPin);
  float mv = ((val/1024.0)*5000);
  float cel = (mv/10)-49.71; //to 49,71 to prosthesame gia na kalimpraroume ton aisthitira
  float farh = (cel*9)/5 + 32;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  if (cel<20){
    digitalWrite (bluepin, HIGH);
    digitalWrite (greenpin, LOW);
    digitalWrite (redpin, LOW);
  }else if (cel<28){
    digitalWrite (bluepin, LOW);
    digitalWrite (greenpin, HIGH);
    digitalWrite (redpin, LOW);
  }else if (cel>28){
    digitalWrite (bluepin, LOW);
    digitalWrite (greenpin, LOW);
    digitalWrite (redpin, HIGH);
  }
  delay(1000);
}
