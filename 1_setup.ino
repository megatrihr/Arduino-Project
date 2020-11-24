void setup() {
  Serial.begin(115200); //Komunikasi serial
  
  pinMode(chA,INPUT);
  pinMode(chB,INPUT);
  pinMode(chC,INPUT);
  pinMode(chD,INPUT);

  pinMode(relay2_1, OUTPUT); //Set output ke relay
  pinMode(relay2_2, OUTPUT);
  pinMode(relay3_1, OUTPUT);
  pinMode(relay3_2, OUTPUT);
  pinMode(relay4_1, OUTPUT);
  pinMode(relay4_2, OUTPUT);

  pinMode(relay_sw, OUTPUT);
  
  digitalWrite(relay2_1, LOW); //Kondisi semua relay dalam keadaan low atau NC
  digitalWrite(relay2_2, LOW);
  digitalWrite(relay3_1, LOW);
  digitalWrite(relay3_2, LOW);
  digitalWrite(relay4_1, LOW);
  digitalWrite(relay4_2, LOW);

  digitalWrite(relay_sw, LOW);

  esc_vertikal_kiri.attach(4);
  esc_vertikal_kanan.attach(6);
  esc_horizontal_kiri.attach(5);
  esc_horizontal_kanan.attach(7);

  MPU6050_set();

  delay(1000);
}
