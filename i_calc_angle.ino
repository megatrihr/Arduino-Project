void calculate_angle() {

  /*
         1
      --------- = 0.0000611   ///// 65.5 is the value for the gyro for 500°/sec configure and rotate 1°/sec and 250 is refresh rate
      65.5*250
  */
  gyro[0] *= 0.0000611;   //we dont need the raw value again so we can change the original data
  gyro[1] *= 0.0000611;   //we dont need the raw value again so we can change the original data
  gyro[2] *= 0.0000611;   //we dont need the raw value again so we can change the original data

  angular_rate[0] = angular_rate[0] * 0.7 + gyro[0] * 0.3;
  angular_rate[1] = angular_rate[1] * 0.7 + gyro[1] * 0.3;
  angular_rate[2] = angular_rate[2] * 0.7 + gyro[2] * 0.3;

  gravity = sqrt(acc[0] * acc[0] + acc[1] * acc[1] + acc[2] * acc[2]);    //calculate the gravity
  acc[0] = asin(acc[0] / gravity) * 57.295779;                            //get pitch angle
  acc[1] = asin(acc[1] / gravity) * 57.295779;                            //get roll angle

  /*
         1
      --------- = 0.0000611   ///// 65.5 is the value for the gyro for 500°/sec configure and rotate 1°/sec and 250 is refresh rate
      65.5*250
  */
  angle[0] = 0.96 * (angle[0] + angular_rate[0]) + 0.04 * acc[0];   //take a larger portion of gyro data and smaller portion of accelerometer data to avoid drift
  angle[1] = 0.96 * (angle[1] + angular_rate[1]) + 0.04 * acc[1];   //take a larger portion of gyro data and smaller portion of accelerometer data to avoid drift
  angle[2] = angle[2] + angular_rate[2];       //yaw angle gyro based only it may drift


  /*    pi
     -------- = 0.0174532925      //arduino sin() takes radian // we convert rolto pitch and pitch to rol because MPU6050 may be yawed inclimbed
       180
  */
  angle[0] -= angle[1] * sin(angular_rate[2] * 0.0174532925);
  angle[1] += angle[0] * sin(angular_rate[2] * 0.0174532925);

}
