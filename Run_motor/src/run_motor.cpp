#include "Arduino.h"
#include "run_motor.h"

run_motor::run_motor(int s0,int s1,int s2,int z,int pwm_left , int pwm_right )
{
  selectPins[0] = s0;
  selectPins[1] = s1;
  selectPins[2] = s2;
  c_z = z;
  c_pwm_left = pwm_left;
  c_pwm_right = pwm_right;
}

run_motor::set()
{
  for (int i=0; i<3; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], LOW);
  }
  pinMode(c_z, OUTPUT);
  pinMode(c_pwm_left, OUTPUT);
  pinMode(c_pwm_right, OUTPUT);

}

run_motor::motor(int motor,int direction ,int speedd)
{
  void pin_select(int motor,int direction)
  {
    int pin;

      if (motor == m1 && direction == forward)
        pin = 0;
      else if (motor == m1 && direction == backward)
        pin = 1;
      else if (motor == m2 && direction == forward)
        pin = 2;
      else if (motor == m2 && direction == backward)
        pin = 3;
      else if (motor == m3 && direction == forward)
        pin = 4;
      else if (motor == m3 && direction == backward)
        pin = 5;
      else if (motor == m4 && direction == forward)
        pin = 6;
      else if (motor == m4 && direction == backward)
        pin = 7;

    //selectMuxPin(pin);
    void selectMuxPin(int pin)
    {
      if (pin > 7) return; // Exit if pin is out of scope
      for (int i=0; i<3; i++)
      {
        if (pin & (1<<i))
        digitalWrite(selectPins[i], HIGH);
        else
        digitalWrite(selectPins[i], LOW);
      }
    }
    analogWrite(c_z, motor_speed);
    delayMicroseconds(DELAY_TIME);


  }

  void pin_speed(int motor,int speedd)
  {
    if(motor == m1 || m3)
      analogWrite(c_pwm_left, speedd);
    else if (motor == m2 || m4)
      analogWrite(c_pwm_right,speedd);
  }
}
