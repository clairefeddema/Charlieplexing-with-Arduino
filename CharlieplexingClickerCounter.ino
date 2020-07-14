int buttonPin = 13;
int c1 = 12;
int c2 = 8;
int c3 = 7;
int c4 = 4;

int delayTime = 100;
int d = 2;

int buttonNew;
int buttonOld = 1; 

int count = 0; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonNew = digitalRead(buttonPin);
  if(buttonOld == 0 && buttonNew == 1){
    count ++;
    delay(delayTime);
    Serial.println(count); 
  }
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
if(count == 10) {
  count = 0;
}
  
  
buttonOld = buttonNew;
}




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
