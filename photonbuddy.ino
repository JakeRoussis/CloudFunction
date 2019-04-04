// Declare variables
int led = D5;
int pir = D4;
bool motion = false;

void myHandler(const char *event, const char *data); // forward declaration


void setup() {
    // Initialize
	pinMode(led,OUTPUT);
	pinMode(pir, INPUT); 
	
	Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}


void loop() {
    // Check if there is a wave!
	if (digitalRead(pir) == HIGH) {
			Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave", PUBLIC);
	}
}


void myHandler(const char *event, const char *data)
{
    // Blink when computer waves back
	if (strcmp(data, "wave")==0) {
		digitalWrite(led, HIGH);
		delay(750);
		digitalWrite(led, LOW);
		delay(500);
		digitalWrite(led, HIGH);
		delay(750);
		digitalWrite(led, LOW);
	}
}
