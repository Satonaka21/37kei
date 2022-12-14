const int left = 13;
const int right = 12;
const int check = 8;
bool booted = false;

void setup() {
 Serial.begin(9600);
 pinMode(left,OUTPUT);
 pinMode(right,OUTPUT);
 pinMode(check,OUTPUT);
} 
void loop() {  
  if(Serial.available() > 0){
    booted = true;
  }
  if(booted){
    digitalWrite(check,HIGH);
    judge(); 
  }
}

int judge(){
  int val_left = analogRead(A0);
  int val_right = analogRead(A1);
//  Serial.print("左\t"); Serial.println("右");
  Serial.print(val_left); Serial.print("\t"); Serial.println(val_right);
if(val_left > 50){
  digitalWrite(left,HIGH);
}
else{
  digitalWrite(left,LOW);
}
if(val_right > 50){
  digitalWrite(right,HIGH);
}
else{
  digitalWrite(right,LOW);
}
if(val_left > 50 and val_right > 50){
  digitalWrite(left,LOW);
  digitalWrite(right,LOW);
}
  delay(100);
}
