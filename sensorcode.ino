#define P0 4
#define P1 5
#define P2 6
#define P3 7
#define sensorOut 8

int frequency = 0;

void setup() {
  pinMode(P0, OUTPUT);
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(P0,HIGH);
  digitalWrite(P1,LOW);
  
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(P2,LOW);
  digitalWrite(P3,LOW);
  frequency = pulseIn(sensorOut, LOW);
  
  Serial.print("Red color emitted = ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);

  
  digitalWrite(P2,HIGH);
  digitalWrite(P3,HIGH);
  frequency = pulseIn(sensorOut, LOW);
 
  Serial.print("Green color emitted = ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);

  
  digitalWrite(P2,LOW);
  digitalWrite(P3,HIGH);
 
  frequency = pulseIn(sensorOut, LOW);
  
  Serial.print("Blue color emitted = ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(100);
}
