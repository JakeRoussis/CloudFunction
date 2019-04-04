// Declare variables
int led = D5;
int pir = D4;
int counter = 0;

void myHandler(const char *event, const char *data); // forward declaration


void setup() {
    // Initialize
	pinMode(led,OUTPUT);
	pinMode(pir, INPUT); 
	
	Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}


void loop() {
    // Check if there is a wave!
	if (digitalRead(pir) == HIGH && counter < 10) {
			Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave", PUBLIC);
			counter ++;
	}
	// Difficult to check sampling with motion sensor. Instead a counter will be used to
	// make use of the pat command
	if (counter >= 10)
	{
		Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat", PUBLIC);
		counter = 0;
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
	} else if (strcmp(data, "pat")==0) {
		digitalWrite(led, HIGH);
		delay(2000);
		digitalWrite(led, LOW);
		delay(500);
		digitalWrite(led, HIGH);
		delay(2000);
		digitalWrite(led, LOW);
	}
}
