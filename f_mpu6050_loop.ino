void MPU6050_loop() {

  read_gyro();
  calculate_angle();

  count++;
  if (count == 1) {         //print data in serial every 0.1s
//    Serial.print("yprt = ");
//    Serial.print(angle[2]); Serial.print(", ");
    Serial.println(angle[0]);
//    Serial.print(angle[1]); Serial.print(", ");
//    Serial.print(temp/340.00+36.53); Serial.print(" || ");
    count = 0;
  }

}
