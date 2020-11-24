#include <Wire.h>
#include <Servo.h>

#define chA 11
#define chB 8
#define chC 9
#define chD 10

#define relay2_1 A2
#define relay2_2 A3
#define relay3_1 3
#define relay3_2 2
#define relay4_1 13
#define relay4_2 A1

#define relay_sw 12

Servo esc_vertikal_kiri;
Servo esc_vertikal_kanan;
Servo esc_horizontal_kiri;
Servo esc_horizontal_kanan;

int temp;
double gyro_cal[3], gravity, gyro[3], acc[3], angle[3], angular_rate[3];
int count;
boolean calibrated;

float elapsedtime, now, timeprev;

float pid, pwmLeft, pwmRight, error, previous_error;
float pid_p=0;
float pid_i=0;
float pid_d=0;
/////////////////PID CONSTANTS/////////////////
double kp=3.55;//3.55
double ki=0.005;//0.003
double kd=2.05;//2.05
///////////////////////////////////////////////

float desired_angle = 0;

int ch1;
int ch2;
int ch3;
int ch4;

int map_ch1;
int map_ch2;
int map_ch3;
int map_ch4;

int cons_ch1;
int cons_ch2;
int cons_ch3;
int cons_ch4;

int value_ch1;
int value_ch2;
int value_ch3;
int value_ch4;

int prev_ch1;
int prev_ch2;
int prev_ch3;
int prev_ch4;

int value_ch2_ch4_kiri;
int value_ch2_ch4_kanan;

int value_ch3_ch4_kiri;
int value_ch3_ch4_kanan;

int esc_val_cal;
