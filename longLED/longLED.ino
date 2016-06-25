int ledRED = 11; 
int ledBLUE = 12; 
int ledYELLOW = 13; 

void setup() {
  // put your setup code here, to run once:
 
  pinMode(ledRED,OUTPUT);
  pinMode(ledBLUE, OUTPUT); 
  pinMode(ledYELLOW, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledRED,HIGH);
  digitalWrite(ledBLUE, HIGH); 
  digitalWrite(ledYELLOW, HIGH); 
  delay(1000);
  digitalWrite(ledRED,LOW);
  digitalWrite(ledBLUE, LOW);
  digitalWrite(ledYELLOW, LOW);
  delay(1000);
}

