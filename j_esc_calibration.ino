void esc_cal(){
  
  esc_val_cal = 2000;
  
  esc_vertikal_kiri.writeMicroseconds(esc_val_cal);
  esc_vertikal_kanan.writeMicroseconds(esc_val_cal);
  esc_horizontal_kiri.writeMicroseconds(esc_val_cal);
  esc_horizontal_kanan.writeMicroseconds(esc_val_cal);

  delay(4000);

  esc_val_cal = 0;

  esc_vertikal_kiri.writeMicroseconds(esc_val_cal);
  esc_vertikal_kanan.writeMicroseconds(esc_val_cal);
  esc_horizontal_kiri.writeMicroseconds(esc_val_cal);
  esc_horizontal_kanan.writeMicroseconds(esc_val_cal);

  delay(7000);

  esc_val_cal = 1000;
  
  esc_vertikal_kiri.writeMicroseconds(esc_val_cal);
  esc_vertikal_kanan.writeMicroseconds(esc_val_cal);
  esc_horizontal_kiri.writeMicroseconds(esc_val_cal);
  esc_horizontal_kanan.writeMicroseconds(esc_val_cal);

  delay(3000);

}
