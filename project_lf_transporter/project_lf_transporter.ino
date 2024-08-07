
const int joystickPinX = A0;  // Pin analog untuk sumbu X
const int joystickPinY = A1;  // Pin analog untuk sumbu Y

int L1 = 3 , L2 = 4 , PWM = 7, R1 = 5 , R2 = 6 ;
void setup() {
  pinMode(PWM , OUTPUT);
  pinMode(L1 , OUTPUT);
  pinMode(L2 , OUTPUT);
  pinMode(R1 , OUTPUT);
  pinMode(R2 , OUTPUT);
  
  Serial.begin(9600);   // Inisialisasi komunikasi serial dengan komputer
  analogWrite(PWM , 200);  
}

void loop() {
  // Baca data dari Bluetooth
   int xValue = analogRead(joystickPinX);  // Baca nilai sumbu X
  int yValue = analogRead(joystickPinY);  // Baca nilai sumbu Y

  // Tambahkan nilai threshold
  int threshold = 15;
  
  // Penentuan arah berdasarkan nilai x dan y
  if (xValue < (450 - threshold) && yValue < (450 - threshold)) {
    Serial.println("Arah: Mundur Kiri");
    mundurkiri();
  } else if (xValue > (450 + threshold) && yValue < (450 - threshold)) {
    Serial.println("Arah: Mundur Kanan");
    mundurkanan();
  } else if (xValue < (450 - threshold) && yValue > (450 + threshold)) {
    Serial.println("Arah: Maju Kiri");
    majukiri();
  } else if (xValue > (450 + threshold) && yValue > (450 + threshold)) {
    Serial.println("Arah: Maju Kanan");
    majukanan();
  } else if (xValue < (450 - threshold) && yValue >= (450 - threshold) && yValue <= (450 + threshold)) {
    Serial.println("Arah: Kiri");
    kiri();
  } else if (xValue > (450 + threshold) && yValue >= (450 - threshold) && yValue <= (450 + threshold)) {
    Serial.println("Arah: Kanan");
    kanan();
  } else if (xValue >= (450 - threshold) && xValue <= (450 + threshold) && yValue >= (450 - threshold) && yValue <= (450 + threshold)) {
    Serial.println("Arah: Berhenti");
    berhenti();
  } else if (yValue > (450 + threshold)) {
    Serial.println("Arah: Maju");
    maju();
  } else {
    Serial.println("Arah: Mundur");
    mundur();
  }

  delay(100);  // Delay untuk stabilitas pembacaan nilai
    
  
        
  

 
}

void berhenti(){
  digitalWrite(L1 , LOW);
  digitalWrite(L2 , LOW);
  digitalWrite(R1 , LOW);
  digitalWrite(R2 , LOW);

}

void mundur (){

  digitalWrite(L1 , HIGH);
  digitalWrite(L2 , LOW);
  digitalWrite(R1 , HIGH);
  digitalWrite(R2 , LOW);

}

void maju (){
  digitalWrite(L1 , LOW);
  digitalWrite(L2 , HIGH);
  digitalWrite(R1 , LOW);
  digitalWrite(R2 , HIGH);
}

void kiri (){
  digitalWrite(L1 , HIGH);
  digitalWrite(L2 , LOW);
  digitalWrite(R1 , LOW);
  digitalWrite(R2 , HIGH);
}

void kanan (){
  digitalWrite(L1 , LOW);
  digitalWrite(L2 , HIGH);
  digitalWrite(R1 , HIGH);
  digitalWrite(R2 , LOW);
}

void mundurkanan (){
  digitalWrite(L1 , HIGH);
  digitalWrite(L2 , LOW);
  digitalWrite(R1 , HIGH);
  digitalWrite(R2 , LOW);
}

void mundurkiri (){
  digitalWrite(L1 , HIGH);
  digitalWrite(L2 , LOW);
  digitalWrite(R1 , HIGH);
  digitalWrite(R2 , LOW);
}

void majukanan (){
  digitalWrite(L1 , LOW);
  digitalWrite(L2 , HIGH);
  digitalWrite(R1 , LOW);
  digitalWrite(R2 , HIGH);
}

void majukiri (){
  digitalWrite(L1 , LOW);
  digitalWrite(L2 , HIGH);
  digitalWrite(R1 , LOW);
  digitalWrite(R2 , HIGH);
}