void setup_gyro() {
  //set up the MPU6050
  Wire.beginTransmission(0x68); //start communicating with mpu6050
  Wire.write(0x6B);             //we want to write in 0x6B register which is powermanagement register
  Wire.write(0x00);             //write 0x00 to that register
  Wire.endTransmission();       //end the transmission

  Wire.beginTransmission(0x68); //start communicating with mpu6050
  Wire.write(0x1B);             //we want to write in 0x1B which is gyro configaration register
  Wire.write(0x08);             //set the gyro for 500 deg pre sec full scale
  Wire.endTransmission();       //end the transmission

  Wire.beginTransmission(0x68); //start communicating with mpu6050
  Wire.write(0x1C);             //we want to write in 0x1C register which is Accelerometer Configuration register
  Wire.write(0x10);             //set the accelerometer with +-8g
  Wire.endTransmission();       //end the transmission

  Wire.beginTransmission(0x68); //start communicating with mpu6050
  Wire.write(0x1A);             //we want to write in 0x1A which is used to gyro and accelerometer synchronizing
  Wire.write(0x03);             //write 0x03 in that register
  Wire.endTransmission();       // end the transmission
  
}
