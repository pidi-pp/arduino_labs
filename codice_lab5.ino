#include "DHT.h" // dichiariamo la libraria del dht
#define DHTPIN 2 // pin digitale collegato al dht
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define echoPin 4 //pin digitale collegato all'echopin
// echoPin = 4;
#define trigPin 3 // stesso qua man nel pin 3

long duration; //variabile per la durata

int distance; // variabile per la distanza

void setup() {
    Serial.begin(9600);
      Serial.println(F("DHTxx test!")); // messaggio di prova iniziale per il dht
        dht.begin();

    pinMode(trigPin, OUTPUT); //dichiariammo il trigpin come output
    pinMode(echoPin, INPUT); // dichiariamo l'echopin come input
    Serial.begin(9600)
     } 
void loop() {
  delay(1000);

    float h = dht.readHumidity(); // serve per leggere l'umidità 
    float t = dht.readTemperature(); // serve per leggere la temperatura

      if (isnan(h) || isnan(t)) {
        Serial.println(F("Failed to read from DHT sensor!")); // messaggio in caso qualcosa vada storto nella lettura del sensore 
        return;
        }

  float hic = dht.computeHeatIndex(t, h, false); // setta l'heat index

  Serial.print(h); // stampa l'umidità
  Serial.print(", "); // stampa una virgola tra i due valori 
  Serial.print(t); // stampa la temperatura 

  digitalWrite(trigPin, LOW); // azzera tutte le cariche sul trigpin
  delayMicroseconds(2); // aspetta 2 microsecondi
  digitalWrite(trigPin, HIGH); // setta il trigpin come high 
  delayMicroseconds(10); // aspetta 10 microsecondi
  digitalWrite(trigPin, LOW); // setta il trigpin come low
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // calcola la distanza
  
  Serial.print(", "); // stampa uan virgola tra la temperatura e il prossimo valore
  Serial.print(distance); // dice di prendere il valore della distanza
  Serial.println(" cm"); // stampa cm
}
