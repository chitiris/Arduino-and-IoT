/********************************
 * Libraries included
 *******************************/
#include <Ethernet.h>
#include <SPI.h>
#include <UbidotsEthernet.h>

/********************************
 * Constants and objects
 *******************************/
/* Assigns the Ubidots parameters */
char const * TOKEN = "..."; // Assign your Ubidots TOKEN
char const * VARIABLE_LABEL_1 = "temperature"; // Assign the unique variable label to send the data
char const * VARIABLE_LABEL_2 = "light"; // Assign the unique variable label to send the data

/* Enter a MAC address for your controller below */
/* Newer Ethernet shields have a MAC address printed on a sticker on the shield */
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

/* initialize the instance */
Ubidots client(TOKEN);

/********************************
 * Main Functions
 *******************************/
void setup() {
  Serial.begin(9600);
  //client.setDebug(true);// uncomment this line to visualize the debug message
  /* start the Ethernet connection */
  Serial.print(F("Starting ethernet..."));
  if (!Ethernet.begin(mac)) {
    Serial.println(F("failed"));
  } else {
    Serial.println(Ethernet.localIP());
  }
  /* Give the Ethernet shield a second to initialize */
  delay(2000);
  Serial.println(F("Ready"));
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  Ethernet.maintain();
  //temp open
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(A0);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10)-282;	/* LM35 gives output of 10mv/°C */
  //temp close
  /* Sensors readings */
  float value_1 = temp_val;
  float value_2 = analogRead(A2);
  /* Sending values to Ubidots */
  client.add(VARIABLE_LABEL_1, value_1);
  client.add(VARIABLE_LABEL_2, value_2);
  client.sendAll();
  delay(15000);
}
