/*
References
https://www.electronicwings.com/arduino/lm35-interfacing-with-arduino-uno
https://projecthub.arduino.cc/tropicalbean/how-to-use-a-photoresistor-1143fd */
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  //temp open
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(A0);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10)-282;	/* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.println(" Degree Celsius\n");
  delay(1000);
  //temp close

  //light open
  int light =  analogRead(A2);
  Serial.print("Light Value: ");
  Serial.println(light);
  //light close
  delay(2000);
}
