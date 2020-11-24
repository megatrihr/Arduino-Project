void MPU6050_set(){

  Wire.begin();           //Initiate the Wire library and join the I2C bus as a master
  /*set clockspeed 400KHz for fast access default is 100 KHz
     if you want to use default one just comment out line 27
  */
  Wire.setClock(400000);
  //wait for some time to get ready MPU6050
  delay(500);

  Serial.begin(115200); // start serial communication high baudrate to avoid delay in serial print and read

  setup_gyro();   // setup gyro

  //initialize the values
  gyro_cal[0] = gyro_cal[1] = gyro_cal[2] = 0;
  acc[0] = acc[1] = acc[2] = 0;
  angle[0] = angle[1] = angle[2] = 0;
  angular_rate[0] = angular_rate[1] = angular_rate[2] = 0;
  calibrated = false;

  double acc_temp[3] = {0.0, 0.0, 0.0}; // tempurary variable
  //calibrating the gyro
  //dont move the gyro during calibration
  for (int i = 0; i < 2000; i++) {
    read_gyro();
    //add a particular axis data to its corrosponding variable
    gyro_cal[0] += gyro[0];
    gyro_cal[1] += gyro[1];
    gyro_cal[2] += gyro[2];
    acc_temp[0] += acc[0];
    acc_temp[1] += acc[1];
    acc_temp[2] += acc[2];

    delayMicroseconds(4000);      //wait for some times say 4000 µs
  }

  calibrated = true;
  //devide the total value by 2000 to get the average value
  gyro_cal[0] /= 2000;
  gyro_cal[1] /= 2000;
  gyro_cal[2] /= 2000;
  
  //take the average of acc data
  acc[0] = acc_temp[0] / 2000;
  acc[1] = acc_temp[0] / 2000;
  acc[2] = acc_temp[0] / 2000;

  //get the gravity vector
  gravity = sqrt(acc[0] * acc[0] + acc[1] * acc[1] + acc[2] * acc[2]);
  angle[0] = asin(acc[0] / gravity) * 57.295779;    //set the initial pitch angle
  angle[1] = asin(acc[1] / gravity) * 57.295779;    //set the initial roll angle
  angle[2] = 0;  //set the initial yaw angle to 0

  while (!Serial);    //wait for serial port to ready
  count = 0;          //set the variable count to zero which used to print data in serial
}
