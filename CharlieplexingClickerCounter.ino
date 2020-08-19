/* Arduino Clicker Counter Using Charlieplexing 
 * 
 * The Arduino Clicker Counter consists of an Arduino Uno board connected to a breadboard 
 * with seven LED diodes arranged in the pattern of a seven-segment display and one button. 
 * 
 * The display initially displays the number zero, and each time the button is pressed, the 
 * counter advances by one number. Once the counter reaches nine and is clicked again, 
 * the display rolls over back to zero. 
 * 
 * Charlieplexing is used to decrease the number of pins needed on the Arduino from
 *  7 to 4 by changing pin modes as well as high/low statuses of each pin. It allows 
 *  current to flow in the correct and unique direction for each LED. 
 *
 *  Written by Claire Feddema on July 13 2020
 */


// Declarations 

// Pin taking button imput
int buttonPin = 13;

//Pins connected indirectly to display LEDs using charlieplexing
int c1 = 5;
int c2 = 4;
int c3 = 3;
int c4 = 2;

//Delay variables in milliseconds
int delayTime = 100;
int d = 2;


//Variables to keep track of the button's status (pressed or not) currently and 
// previously to compare (in order to know when it goes from pressed to unpressed, 
// which counts as a single button press) 
int buttonNew;
int buttonOld = 1; 

int count = 0; 

//Runs once when the Arduino is powered up
//Begins console 
void setup() {
Serial.begin(9600);
}

// Runs as long as the Arduino stays plugged in 
void loop() {


// Reads the state of the button and sets buttonNew to 1 when unpressed or 0 when pressed 
// then checks when the button goes from pressed to unpressed, and adds to the count of button presses
// Delays by the set delayTime and prints the count to the console
buttonNew = digitalRead(buttonPin);
  if(buttonOld == 0 && buttonNew == 1){
    count ++;
    delay(delayTime);
    Serial.println(count); 
  }

//Calls the correct functions for each individual LED of the display 
// in quick succession to turn on the correct LEDs and display the numbers
// 0 through 9 based on the value of the count variable 
  
// Short delays are needed between function calls to prevent LEDs that are supposed to
// be off from turning on, not sure why, may have something to do with signals mixing 
if(count == 0) {
  led1 ();
  delay(d);
  led2 ();
  delay(d);
  led3 ();
  delay(d);
  led5 ();
  delay(d);
  led6 ();
  delay(d);
  led7 ();
  delay(d);
}
if(count == 1) {
  led3 ();
  delay(d);
  led6 (); 
  delay(d);
}
if(count == 2) {
  led1 ();
  delay(d);
  led3 ();
  delay(d);
  led4 ();
  delay(d);
  led5 ();
  delay(d);
  led7 (); 
  delay(d); 
}
if(count == 3) {
  led1 ();
  delay(d);
  led3 ();
  delay(d);
  led4 ();
  delay(d);
  led6 ();
  delay(d);
  led7 (); 
  delay(d); 
}
if(count == 4) {
  led2 ();
  delay(d);
  led3 ();
  delay(d);
  led4 ();
  delay(d);
  led6 (); 
  delay(d);
}
if(count == 5) {
  led1 ();
  delay(d);
  led2 ();
  delay(d);
  led4 ();
  delay(d);
  led6 ();
  delay(d);
  led7 (); 
  delay(d); 
}
if(count == 6) {
  led1 ();
  delay(d);
  led2 ();
  delay(d);
  led4 ();
  delay(d);
  led5 ();
  delay(d);
  led6 ();
  delay(d);
  led7 (); 
  delay(d); 
}
if(count == 7) {
  led1 ();
  delay(d);
  led3 ();
  delay(d);
  led6 (); 
  delay(d);
}
if(count == 8) {
  led1 ();
  delay(d);
  led2 ();
  delay(d);
  led3 ();
  delay(d);
  led4 ();
  delay(d);
  led5 ();
  delay(d);
  led6 ();
  delay(d);
  led7 (); 
  delay(d); 
}
if(count == 9) {
  led1 ();
  delay(d);
  led2 ();
  delay(d);
  led3 ();
  delay(d);
  led4 ();
  delay(d);
  led6 (); 
  delay(d);
}
// Rolls the display back to 0 to fit in a single digit display 
if(count == 10) {
  count = 0;
}
  
// Sets the previous value of the button status to the new value to be compared in 
// the next loop iteration  
buttonOld = buttonNew;
}


// Changes both pin modes and statuses of each pin to turn on each
// of the 7 seperate LEDs on the  display
void led1 () {
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, INPUT);
  pinMode(c4, INPUT);
  digitalWrite(c1, HIGH);
  digitalWrite(c2, LOW);
}
void led2 () {
  pinMode(c1, INPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, INPUT);
  digitalWrite(c2, HIGH);
  digitalWrite(c3, LOW);  
}
void led3 () {
  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  digitalWrite(c3, HIGH);
  digitalWrite(c4, LOW);
}
void led4 () {
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, INPUT);
  pinMode(c4, INPUT);
  digitalWrite(c1, LOW);
  digitalWrite(c2, HIGH);
}
void led5 () {
  pinMode(c1, INPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, INPUT);
  digitalWrite(c2, LOW);
  digitalWrite(c3, HIGH);
}
void led6 () {
  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  digitalWrite(c3, LOW);
  digitalWrite(c4, HIGH);
}
void led7 () {
  pinMode(c1, OUTPUT);
  pinMode(c2, INPUT);
  pinMode(c3, INPUT);
  pinMode(c4, OUTPUT);
  digitalWrite(c1, HIGH);
  digitalWrite(c4, LOW);
}
