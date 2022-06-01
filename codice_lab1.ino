int led = 9; // il pin led a cui il pwm è attaccato
int brightness = 0; // la luminosità del led
int fadeAmount = 5; // la percentuale che sale ogni volta

void setup() {
   // dichiarando che il pin 9 è un output:
   pinMode(led, OUTPUT);
}

void loop() {
   // settiamo la luminosità:
   analogWrite(led, brightness);
   // cambia la luminosità per ogni loop:
   brightness = brightness + fadeAmount;
   // inverte la luminosità una volta raggionto il massimo (255):
   if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ;
   }
   // cambia luminosità ogni 30 millisecondi
   delay(300);
}
