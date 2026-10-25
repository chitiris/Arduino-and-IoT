# Επίπεδο 2: Αισθητήρες

## Temp_and_Photo_Resistor

Διαβάζει ταυτόχρονα δύο αισθητήρες και τυπώνει τις τιμές τους στο Serial Monitor:

| Αισθητήρας | Pin | Έξοδος |
|---|---|---|
| Θερμοκρασίας LM35 | A0 | Θερμοκρασία σε °C (κάθε 3 δευτερόλεπτα) |
| Φωτοαντίσταση | A2 | Τιμή φωτεινότητας 0–1023 |

**Έννοιες:** μετατροπή τιμής ADC σε τάση (1 μονάδα ≈ 4.88 mV στα 5 V), ο LM35 δίνει 10 mV ανά °C, εμπειρική βαθμονόμηση αισθητήρα.

Το ίδιο κύκλωμα χρησιμοποιείται στο [επίπεδο 3](../03-IoT-Cloud), όπου οι μετρήσεις στέλνονται στο cloud.

**Πηγές**
- [LM35 interfacing with Arduino Uno – ElectronicWings](https://www.electronicwings.com/arduino/lm35-interfacing-with-arduino-uno)
- [How to use a photoresistor – Arduino Project Hub](https://projecthub.arduino.cc/tropicalbean/how-to-use-a-photoresistor-1143fd)
