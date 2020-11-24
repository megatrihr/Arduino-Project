void val_channel(){

  ch1 = pulseIn (chA,HIGH); //Membaca nilai channel 2
  map_ch1 = map(ch1,1083,1905,-2000,2000);
  cons_ch1 = constrain(map_ch1, -2000, 2000);
  
  ch2 = pulseIn (chB,HIGH); //Membaca nilai channel 2
  map_ch2 = map(ch2,1083,1905,-2000,2000);
  cons_ch2 = constrain(map_ch2, -2000, 2000);
  
  ch3 = pulseIn (chC,HIGH); //Membaca nilai channel 3
  map_ch3 = map(ch3,1083,1905,-2000,2000);
  cons_ch3 = constrain(map_ch3, -2000, 2000);
   
  ch4 = pulseIn (chD,HIGH); //Membaca nilai channel 4
  map_ch4 = map(ch4,1083,1905,-2000,2000);
  cons_ch4 = constrain(map_ch4, -2000, 2000);

  prev_ch1 = 0;
  prev_ch2 = 0;
  prev_ch3 = 0;
  prev_ch4 = 0;

  value_ch2_ch4_kiri = 0;
  value_ch2_ch4_kanan = 0;

  value_ch3_ch4_kiri = 0;
  value_ch3_ch4_kanan = 0;

  prev_ch1 = value_ch1;
  prev_ch2 = value_ch2;
  prev_ch3 = value_ch3;
  prev_ch4 = value_ch4;

  value_ch1 = cons_ch1;
  value_ch2 = cons_ch2;
  value_ch3 = cons_ch3;
  value_ch4 = cons_ch4;

    val_ch2();

  if(value_ch2>=0){
    digitalWrite(relay3_1, LOW);
    digitalWrite(relay3_2, LOW);
    digitalWrite(relay4_1, LOW);
    digitalWrite(relay4_2, LOW);
    
    if((value_ch2-prev_ch2)==-50 || (value_ch2-prev_ch2)==-100 || (value_ch2-prev_ch2)==-150){
    value_ch2 = prev_ch2;
    }
    esc_horizontal_kiri.writeMicroseconds(value_ch2);
    esc_horizontal_kanan.writeMicroseconds(value_ch2);
  }
  
   else if(value_ch2<-1100){
    digitalWrite(relay3_1, HIGH);
    digitalWrite(relay3_2, HIGH);
    digitalWrite(relay4_1, HIGH);
    digitalWrite(relay4_2, HIGH);

    if((prev_ch2-value_ch2)==-50 || (prev_ch2-value_ch2)==-100 || (prev_ch2-value_ch2)==-150){
    value_ch2 = prev_ch2;
    }
    esc_horizontal_kiri.writeMicroseconds(-1*value_ch2);
    esc_horizontal_kanan.writeMicroseconds(-1*value_ch2);
  }
  
   else if(value_ch2==-500 || value_ch2==-1100){
    value_ch2 = 0;
  }
    
    val_ch3();
    
  if(value_ch3>=0){
    digitalWrite(relay2_1, LOW);
    digitalWrite(relay2_2, LOW);
    
    if((value_ch3-prev_ch3)==-50 || (value_ch3-prev_ch3)==-100 || (value_ch3-prev_ch3)==-150){
    value_ch3 = prev_ch3;
    }

pwmLeft = (0.588*value_ch3) - pid;
pwmRight = (0.588*value_ch3) + pid;

//Right
if(pwmRight < 1000)
{
  pwmRight= 1000;
}
if(pwmRight > 2000)
{
  pwmRight=2000;
}
//Left
if(pwmLeft < 1000)
{
  pwmLeft= 1000;
}
if(pwmLeft > 2000)
{
  pwmLeft=2000;
}

    esc_vertikal_kiri.writeMicroseconds(pwmLeft);
    esc_vertikal_kanan.writeMicroseconds(pwmRight);
  }
   
   else if(value_ch3<-1100){
    digitalWrite(relay2_1, HIGH);
    digitalWrite(relay2_2, HIGH);

    if((prev_ch3-value_ch3)==-50 || (prev_ch3-value_ch3)==-100 || (prev_ch3-value_ch3)==-150){
    value_ch3 = prev_ch3;
    }
    esc_vertikal_kiri.writeMicroseconds(-1*value_ch3);
    esc_vertikal_kanan.writeMicroseconds(-1*value_ch3);
  }
   
   else if(value_ch3==-500 || value_ch3==-1100){
    value_ch3 = 0;
  }

    val_ch4();
    
  if(value_ch4>110){
    if(value_ch2>=0){
      if((value_ch4-prev_ch4)==-5 || (value_ch4-prev_ch4)==-10 || (value_ch4-prev_ch4)==-15){
      value_ch4 = prev_ch4;
      }
      value_ch2_ch4_kiri = value_ch2 + value_ch4;
      value_ch2_ch4_kanan = value_ch2;
      esc_horizontal_kiri.writeMicroseconds(value_ch2_ch4_kiri);
      esc_horizontal_kanan.writeMicroseconds(value_ch2_ch4_kanan);
    }

    else if(value_ch2<-1100){
      if((value_ch4-prev_ch4)==-5 || (value_ch4-prev_ch4)==-10 || (value_ch4-prev_ch4)==-15){
      value_ch4 = prev_ch4;
      }
      value_ch2_ch4_kiri = (-1*value_ch2) + value_ch4;
      value_ch2_ch4_kanan = (-1*value_ch2);
      esc_horizontal_kiri.writeMicroseconds(value_ch2_ch4_kiri);
      esc_horizontal_kanan.writeMicroseconds(value_ch2_ch4_kanan);
    }

//    if(value_ch3>=0){
//      if((value_ch4-prev_ch4)==-5 || (value_ch4-prev_ch4)==-10 || (value_ch4-prev_ch4)==-15){
//      value_ch4 = prev_ch4;
//      }
//      value_ch3_ch4_kiri = value_ch3;
//      value_ch3_ch4_kanan = value_ch3 + value_ch4;
//      esc_vertikal_kiri.writeMicroseconds(value_ch3_ch4_kiri);
//      esc_vertikal_kanan.writeMicroseconds(value_ch3_ch4_kanan);
//    }
//
//    else if(value_ch3<-1100){
//      if((value_ch4-prev_ch4)==-5 || (value_ch4-prev_ch4)==-10 || (value_ch4-prev_ch4)==-15){
//      value_ch4 = prev_ch4;
//      }
//      value_ch3_ch4_kiri = (-1*value_ch3);
//      value_ch3_ch4_kanan = (-1*value_ch3) + value_ch4;
//      esc_vertikal_kiri.writeMicroseconds(value_ch3_ch4_kiri);
//      esc_vertikal_kanan.writeMicroseconds(value_ch3_ch4_kanan);
//    }

    if(value_ch2==0 && value_ch3>=0 || value_ch2==0 && value_ch3<-1100){
      if((value_ch4-prev_ch4)==-5 || (value_ch4-prev_ch4)==-10 || (value_ch4-prev_ch4)==-15){
      value_ch4 = prev_ch4;
      }
      digitalWrite(relay3_1, HIGH);
      digitalWrite(relay3_2, HIGH);
      digitalWrite(relay4_1, LOW);
      digitalWrite(relay4_2, LOW);
      esc_horizontal_kiri.writeMicroseconds(8*value_ch4);
      esc_horizontal_kanan.writeMicroseconds(8*value_ch4);
    }

  }
  
  else if(value_ch4<-110){
    if(value_ch2>=0){
      if((prev_ch4-value_ch4)==-5 || (prev_ch4-value_ch4)==-10 || (prev_ch4-value_ch4)==-15){
      value_ch4 = prev_ch4;
      }    
      value_ch2_ch4_kiri = value_ch2;
      value_ch2_ch4_kanan = value_ch2 - value_ch4;
      esc_horizontal_kiri.writeMicroseconds(value_ch2_ch4_kiri);
      esc_horizontal_kanan.writeMicroseconds(value_ch2_ch4_kanan);
    }

    else if(value_ch2<-1100){
      if((prev_ch4-value_ch4)==-5 || (prev_ch4-value_ch4)==-10 || (prev_ch4-value_ch4)==-15){
      value_ch4 = prev_ch4;
      }
      value_ch2_ch4_kiri = (-1*value_ch2);
      value_ch2_ch4_kanan = (-1*value_ch2) - value_ch4;
      esc_horizontal_kiri.writeMicroseconds(value_ch2_ch4_kiri);
      esc_horizontal_kanan.writeMicroseconds(value_ch2_ch4_kanan);
    }

//    if(value_ch3>=0){
//      if((prev_ch4-value_ch4)==-5 || (prev_ch4-value_ch4)==-10 || (prev_ch4-value_ch4)==-15){
//      value_ch4 = prev_ch4;
//      }
//      value_ch3_ch4_kiri = value_ch3 - value_ch4;
//      value_ch3_ch4_kanan = value_ch3;
//      esc_vertikal_kiri.writeMicroseconds(value_ch3_ch4_kiri);
//      esc_vertikal_kanan.writeMicroseconds(value_ch3_ch4_kanan);
//    }
//
//    else if(value_ch3<-1100){
//      if((prev_ch4-value_ch4)==-5 || (prev_ch4-value_ch4)==-10 || (prev_ch4-value_ch4)==-15){
//      value_ch4 = prev_ch4;
//      }
//      value_ch3_ch4_kiri = (-1*value_ch3) - value_ch4;
//      value_ch3_ch4_kanan = (-1*value_ch3);
//      esc_vertikal_kiri.writeMicroseconds(value_ch3_ch4_kiri);
//      esc_vertikal_kanan.writeMicroseconds(value_ch3_ch4_kanan);
//    }

    if(value_ch2==0 && value_ch3>=0 || value_ch2==0 && value_ch3<-1100){
      if((prev_ch4-value_ch4)==-5 || (prev_ch4-value_ch4)==-10 || (prev_ch4-value_ch4)==-15){
      value_ch4 = prev_ch4;
      }
      digitalWrite(relay3_1, LOW);
      digitalWrite(relay3_2, LOW);
      digitalWrite(relay4_1, HIGH);
      digitalWrite(relay4_2, HIGH);
      esc_horizontal_kiri.writeMicroseconds(-8*value_ch4);
      esc_horizontal_kanan.writeMicroseconds(-8*value_ch4);
    }

  }
   
   else if(value_ch4==-50 || value_ch4==-110){
    value_ch4 = 0;
  }

      val_ch1();
    
  if(value_ch1>=0){
    
    if((value_ch1-prev_ch1)==-5 || (value_ch1-prev_ch1)==-10 || (value_ch1-prev_ch1)==-15){
    value_ch1 = prev_ch1;
    }

  }
   
   else if(value_ch1<-110){

    if((prev_ch1-value_ch1)==-5 || (prev_ch1-value_ch1)==-10 || (prev_ch1-value_ch1)==-15){
    value_ch1 = prev_ch1;
    }

  }
   
   else if(value_ch1==-50 || value_ch1==-110){
    value_ch1 = 0;
  }

  if(value_ch1==-200 || value_ch2==0 && value_ch3==-2000 && value_ch4==0){
    digitalWrite(relay_sw, LOW);
  }
  else if(value_ch1==200 && value_ch2==0 && value_ch3==0 && value_ch4==0){
    digitalWrite(relay_sw, HIGH);
    esc_vertikal_kiri.writeMicroseconds(1000);
    esc_vertikal_kanan.writeMicroseconds(1000);
    esc_horizontal_kiri.writeMicroseconds(1000);
    esc_horizontal_kanan.writeMicroseconds(1000);
  }
  else if(value_ch1==200 && value_ch2==0 && value_ch3==0 && value_ch4==-200){
    digitalWrite(relay_sw, HIGH);
    esc_cal();
  }

//  Serial.print ("Ch1:");
//  Serial.print (value_ch1);
//  Serial.print ("     |     ");
//
//  Serial.print ("Ch2:");
//  Serial.print (value_ch2);
//  Serial.print ("     |     ");
//  
//  Serial.print ("Ch3:");  //Display teks
//  Serial.print (value_ch3);
//  Serial.print ("     |     ");
//
//  Serial.print ("Ch4:");  //Display teks
//  Serial.print (8*value_ch4);
//  Serial.print ("     |     ");
// 
//  Serial.print ("Ch2_Ch4_Kiri:");
//  Serial.print (value_ch2_ch4_kiri);
//  Serial.print ("     |     ");
//
//  Serial.print ("Ch2_Ch4_Kanan:");
//  Serial.print (value_ch2_ch4_kanan);
//  Serial.print ("     |     ");
//
//  Serial.print ("Ch3_Ch4_Kiri:");
//  Serial.print (value_ch3_ch4_kiri);
//  Serial.print ("     |     ");
//
//  Serial.print ("Ch3_Ch4_Kanan:");
//  Serial.print (value_ch3_ch4_kanan);
//  Serial.print ("     |     ");
//  
//  Serial.print ('\n');
  
}
