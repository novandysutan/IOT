const int hijau = 5; //esp32 pin hijau
const int kuning = 18; //esp32 pin kuning
const int merah = 19; //esp32 pin merah

const long interval = 3000;
long kuningBlink = 0;

unsigned long previousMillis = 0;

const long durance[] = {4, 1, 4}; // second dalam state

enum status {HIJAU, KUNING, MERAH};
status statusLED = HIJAU;


void setup() {
  // put your setup code here, to run once:
  pinMode(hijau, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(merah, OUTPUT);

}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= durance[statusLED] * 1000) {
    previousMillis = currentMillis;
    switch (statusLED) {
      case HIJAU:
        digitalWrite(hijau, HIGH);
        digitalWrite(kuning, LOW);
        kuningBlink = 0;
        digitalWrite(merah, LOW);
        statusLED = KUNING; //case yang dilanjutkan
        break;
      case KUNING:
        digitalWrite(hijau, LOW);
        digitalWrite(kuning, HIGH);
        kuningBlink = 1;
        digitalWrite(merah, LOW);
        statusLED = HIJAU;//case yang dilanjutkan
        break;
      case MERAH:
        digitalWrite(hijau, LOW);
        digitalWrite(kuning, LOW);
        kuningBlink = 0;
        digitalWrite(merah, HIGH);
        statusLED = HIJAU;//kembali ke case awal
        break;
    }

  }
  if (kuningBlink && (currentMillis - previousMillis >= interval)) {

    previousMillis = currentMillis;

    digitalWrite(kuning, !digitalRead(kuning));

  }
}
