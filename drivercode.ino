
int ma1 = 6;
int ma2 = 7;
int mb1 = 8;
int mb2 = 9;

void setup() {

int enA = 10;
int enB = 11;
pinMode(ma1,OUTPUT);
pinMode(ma2,OUTPUT);
pinMode(mb1,OUTPUT);
pinMode(mb2,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);

digitalWrite(ma1,LOW);
digitalWrite(ma2,LOW);
digitalWrite(mb1,LOW);
digitalWrite(mb2,LOW);
delay(5000);

analogWrite(enA,200);
analogWrite(enB,200);

straight();
delay(10000);

digitalWrite(ma1,LOW);
digitalWrite(ma2,LOW);
digitalWrite(mb1,HIGH);
digitalWrite(mb2,LOW);
delay(1000);
straight()
delay(10000);

digitalWrite(ma1,HIGH);
digitalWrite(ma2,LOW);
digitalWrite(mb1,LOW);
digitalWrite(mb2,LOW);
delay(1000);
straight()

analogWrite(enA,255);
analogWrite(enB,255);

straight();
delay(10000);

digitalWrite(ma1,LOW);
digitalWrite(ma2,LOW);
digitalWrite(mb1,HIGH);
digitalWrite(mb2,LOW);
delay(1000);
straight()
delay(10000);

digitalWrite(ma1,HIGH);
digitalWrite(ma2,LOW);
digitalWrite(mb1,LOW);
digitalWrite(mb2,LOW);
delay(1000);
straight()
}


void straight() {

  digitalWrite(ma1,HIGH);
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,HIGH);
  digitalWrite(mb2,LOW);
}

void loop() {
  
}
