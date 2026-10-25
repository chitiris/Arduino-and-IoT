# Arduino and Internet of Things

> *Arduino scenarios for learners, from a first blinking LED in Tinkercad to sending sensor data to the cloud (ThingSpeak, Ubidots).*

Εκπαιδευτικό υλικό για **Arduino** και **Internet of Things (IoT)**, οργανωμένο ως πορεία μάθησης: ξεκινά από απλά κυκλώματα με LED και κουμπιά, περνά στην ανάγνωση αισθητήρων και καταλήγει σε συσκευές που στέλνουν μετρήσεις σε πλατφόρμες cloud μέσω Ethernet.

## Πορεία μάθησης

| Επίπεδο | Φάκελος | Τι μαθαίνεις | Υλικό |
|---|---|---|---|
| 1 | [`01-Beginners-Scenarios`](01-Beginners-Scenarios) | Ψηφιακές είσοδοι/έξοδοι, αναλογική ανάγνωση, λογική `if/else`, Serial Monitor | Tinkercad ή Arduino Uno + breadboard |
| 2 | [`02-Sensors`](02-Sensors) | Ανάγνωση αισθητήρα θερμοκρασίας (LM35) και φωτοαντίστασης, μετατροπή τιμών ADC σε μονάδες | Arduino Uno |
| 3 | [`03-IoT-Cloud`](03-IoT-Cloud) | Σύνδεση στο δίκτυο με Ethernet Shield, αποστολή μετρήσεων σε **ThingSpeak** και **Ubidots** | Arduino Uno + Ethernet Shield |

```
Arduino-and-IoT/
├── 01-Beginners-Scenarios/
│   ├── Button-Buzzer/                     # Κουμπί που ενεργοποιεί buzzer και LED
│   ├── PhotoResistor-and-Led/             # «Φωτάκι νυκτός» με φωτοαντίσταση
│   └── RGB-Led-With-Temperature-Sensor/   # Χρώμα RGB LED ανάλογα με τη θερμοκρασία
├── 02-Sensors/
│   └── Temp_and_Photo_Resistor/           # Θερμοκρασία + φωτεινότητα στο Serial Monitor
└── 03-IoT-Cloud/
    ├── Thingspeak-project/                # Θερμοκρασία → ThingSpeak
    └── first-ubidots-project/             # Θερμοκρασία + φωτεινότητα → Ubidots
```

## Τι χρειάζεσαι

**Λογισμικό**
- [Arduino IDE](https://www.arduino.cc/en/software) ή [Tinkercad Circuits](https://www.tinkercad.com/circuits) (για το επίπεδο 1)
- Για το επίπεδο 3, βιβλιοθήκες από το Library Manager του Arduino IDE ή από GitHub:
  - [Ethernet](https://github.com/arduino-libraries/Ethernet)
  - [ThingSpeak](https://github.com/mathworks/thingspeak-arduino)
  - [Ubidots Ethernet](https://github.com/ubidots/ubidots-arduino-ethernet)

**Υλικό**
- Arduino Uno, breadboard, καλώδια
- LED, RGB LED, αντιστάσεις, κουμπί, buzzer
- Αισθητήρας θερμοκρασίας LM35 (ή TMP36), φωτοαντίσταση
- Ethernet Shield (W5100/W5500) για το επίπεδο 3

## Πώς ανοίγεις ένα sketch

Κάθε sketch βρίσκεται σε δικό του φάκελο με το ίδιο όνομα, όπως απαιτεί το Arduino IDE. Άνοιξε το αρχείο `.ino`, επίλεξε **Tools → Board → Arduino Uno** και πάτησε **Upload**. Τα αποτελέσματα φαίνονται στο **Serial Monitor** (9600 baud).

Όλα τα sketch ελέγχθηκαν ότι γίνονται compile για Arduino Uno.

## Σημειώσεις

- **Κλειδιά και tokens.** Τα sketch του επιπέδου 3 έχουν θέσεις για Channel ID, Write API Key (ThingSpeak) και Token (Ubidots). Συμπλήρωσε τα δικά σου στοιχεία τοπικά και **μην τα ανεβάζεις ποτέ στο GitHub**.
- **Βαθμονόμηση θερμοκρασίας.** Μερικά sketch αφαιρούν μια σταθερά από τη θερμοκρασία (π.χ. `-49.71`, `-282`). Είναι εμπειρικές διορθώσεις για τον συγκεκριμένο αισθητήρα ή προσομοιωτή που χρησιμοποιήθηκε. Ο αισθητήρας θερμοκρασίας του Tinkercad, για παράδειγμα, είναι TMP36, ο οποίος έχει offset 500 mV, δηλαδή περίπου 50 °C. Με δικό σου αισθητήρα ίσως χρειαστεί διαφορετική τιμή.

## Ιστορικό

Το repository ενοποιεί δύο παλαιότερα:
- **Arduino-Beginners-Scenarios** (2022): σενάρια για αρχάριους, που αναπτύχθηκαν σε συνεργασία με τον καθηγητή **Άγγελο Μιχάλα** και έγιναν remix εκατοντάδες φορές από την κοινότητα του Tinkercad. Το αρχικό repository είναι πλέον archived.
- **Arduino-MScUoWM**: υποστηρικτικό υλικό του μαθήματος Arduino στο ΔΠΜΣ «Προηγμένες Τεχνολογίες Πληροφορικής και Υπηρεσίες».

## Άδεια

[MIT](LICENSE) © Christos Hitiris
