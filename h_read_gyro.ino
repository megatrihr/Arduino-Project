void read_gyro() {

  Wire.beginTransmission(0x68);   //start communicating with MPU6050
  Wire.write(0x3B);               //start reading from 0x3B
  Wire.endTransmission();         //end the transmission
  Wire.requestFrom(0x68, 14);     //request 14 bytes
  while (Wire.available() < 14);  //wait until 14 bytes are received
  acc[0] = Wire.read() << 8 | Wire.read();    //read acc x data
  acc[1] = Wire.read() << 8 | Wire.read();    //read acc y data
  acc[2] = Wire.read() << 8 | Wire.read();    //read acc z data
  temp = Wire.read() << 8 | Wire.read();      //read temperature data [we don't use it here]
  gyro[1] = Wire.read() << 8 | Wire.read();   //read gyro pitch data
  gyro[0] = Wire.read() << 8 | Wire.read();   //read gyro roll data
  gyro[2] = Wire.read() << 8 | Wire.read();   //read gyro yaw data

  if (calibrated) {
    //substract the calibration value to get proper data
    gyro[0] -= gyro_cal[1];
    gyro[1] -= gyro_cal[0];
    gyro[2] -= gyro_cal[2];
  }
  
}

