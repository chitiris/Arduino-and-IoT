# Επίπεδο 3: IoT και Cloud

Το Arduino συνδέεται στο δίκτυο με **Ethernet Shield** (διεύθυνση μέσω DHCP) και στέλνει τις μετρήσεις του σε πλατφόρμα cloud, όπου εμφανίζονται σε γραφήματα και dashboards.

## Thingspeak-project

Διαβάζει τη θερμοκρασία από αισθητήρα **LM35** (pin A0) και τη στέλνει κάθε 20 δευτερόλεπτα στο **Field 1** ενός καναλιού [ThingSpeak](https://thingspeak.mathworks.com/).

**Ρύθμιση**
1. Φτιάξε κανάλι στο ThingSpeak και ενεργοποίησε το Field 1.
2. Στο sketch συμπλήρωσε το `myChannelNumber` (Channel ID) και το `myWriteAPIKey` (καρτέλα *API Keys*).

> Ο δωρεάν λογαριασμός δέχεται μία ενημέρωση ανά 15 δευτερόλεπτα, γι' αυτό το διάστημα αποστολής είναι 20 δευτερόλεπτα.

## first-ubidots-project

Διαβάζει θερμοκρασία (A0) και φωτεινότητα από φωτοαντίσταση (A2) και τις στέλνει κάθε 15 δευτερόλεπτα στις μεταβλητές `temperature` και `light` της πλατφόρμας [Ubidots](https://ubidots.com/).

**Ρύθμιση**
1. Από το λογαριασμό σου στο Ubidots πάρε ένα **Token** (*API Credentials*).
2. Στο sketch συμπλήρωσε το `TOKEN`. Οι μεταβλητές δημιουργούνται αυτόματα με την πρώτη αποστολή.

## Βιβλιοθήκες

| Βιβλιοθήκη | Για |
|---|---|
| `SPI`, [`Ethernet`](https://github.com/arduino-libraries/Ethernet) | Επικοινωνία με το Ethernet Shield |
| [`ThingSpeak`](https://github.com/mathworks/thingspeak-arduino) | Thingspeak-project |
| [`UbidotsEthernet`](https://github.com/ubidots/ubidots-arduino-ethernet) | first-ubidots-project |

> ⚠️ Μην ανεβάζεις ποτέ στο GitHub sketch με πραγματικό API Key ή Token. Κράτα τα στοιχεία σου μόνο στο τοπικό σου αντίγραφο.
