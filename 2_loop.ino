void loop() {
  
  timeprev = now;
  now = millis();
  elapsedtime = (now - timeprev)/1000;
  
    MPU6050_loop();

  error = angle[0] - desired_angle;
  
  pid_p = kp*error;

  if(-3 <error< 3){
  pid_i = pid_i+(ki*error);  
  }

  pid_d = kd*((error - previous_error)/elapsedtime);

  pid = pid_p + pid_i + pid_d;

  if(pid < -1000)
{
  pid = -1000;
}
else if(pid > 1000)
{
  pid = 1000;
}

    val_channel();

  previous_error = error;
  
//  Serial.print("pid = ");
//  Serial.println(pid);
}
