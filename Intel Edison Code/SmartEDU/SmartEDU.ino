//SmartEDU project - Intel IoT Roadshow 
/* Here we declare the variables we`re going to use throughout the code. We named them 
so that they reflect their function in our project, but we also added some explanation after each of them just in case */
int ledPhotocell = 13;    //this LED is our automated response to situations where the lights go off
int ledThermo = 12;       //this LED represents our response to changes in the environment`s temperature
int photocellPin = 0;     // The photocell pin is connected here
int thermoPin = 1;     // the Thermo pin is connected here
int photocellReading;     // this variable will receive the value we gather in photocellPin
int thermoReading;     // this variable will receive the value we gather in thermoPin


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledPhotocell, OUTPUT);
  pinMode(ledThermo, OUTPUT);
  Serial.begin(9600);   
}

// the loop routine runs over and over again forever:
void loop() {
  photocellReading = analogRead(photocellPin);
  thermoReading = analogRead(thermoPin);
    
  Serial.print("Analog Photocell Reading = ");
  Serial.println(photocellReading);     // the raw analog reading
  Serial.print("Analog Thermo Reading = ");
  Serial.println(thermoReading);     // the raw analog reading
  
/*here we define what the classroom would do if the temperature went too high or the lighting is not the ideal. We use a LED to represent, but in real life
we would take other actions, such as activating the air conditioning system and contacting the cloud to adapt the classroom`s systems
to that group of students*/
  
  if(thermoReading>170){
     digitalWrite(ledThermo, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else{
     digitalWrite(ledThermo, LOW);    // turn the LED off by making the voltage LOW
  
  }
  
  if(photocellReading < 1010){
     digitalWrite(ledPhotocell, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else{
     digitalWrite(ledPhotocell, LOW);    // turn the LED off by making the voltage LOW
  
  }
  
  

}
