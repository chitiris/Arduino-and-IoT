#include <SPI.h>
#include <Ethernet.h>
#include "ThingSpeak.h"

// Διεύθυνση MAC — συνήθως υπάρχει σε αυτοκόλλητο πάνω στο shield.
// Αν δεν έχει, άφησε αυτή (αρκεί να είναι μοναδική στο δίκτυό σου).
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient client;

unsigned long myChannelNumber = 1234567;        // Το ID του καναλιού σου
const char* myWriteAPIKey = "ΤΟ_WRITE_API_KEY"; // Από την καρτέλα API Keys

const int lm35Pin = A0;  // Αναλογικό pin του LM35

void setup() {
  Serial.begin(9600);

  // Σύνδεση στο δίκτυο μέσω DHCP
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Αποτυχια συνδεσης μεσω DHCP");
    while (true);  // σταμάτα εδώ
  }
  Serial.print("IP: ");
  Serial.println(Ethernet.localIP());

  ThingSpeak.begin(client);
}

void loop() {
  // Ανάγνωση LM35
  int reading = analogRead(lm35Pin);
  float voltage = reading * (5.0 / 1024.0);  // μετατροπή σε Volt
  float temperatureC = (voltage * 100.0);       // 10mV ανά °C

  Serial.print("Θερμοκρασια: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Αποστολή στο Field1
  int status = ThingSpeak.writeField(myChannelNumber, 1, temperatureC, myWriteAPIKey);
  if (status == 200) {
    Serial.println("Σταλθηκε επιτυχως");
  } else {
    Serial.println("Σφαλμα: " + String(status));
  }

  delay(20000);  // 20 δευτ. (μην κατεβαίνεις κάτω από 15 στον δωρεάν λογαριασμό)
}