#include "mbed.h"
//declaring functions from mbed.h
AnalogIn analog_value(A0);
 
DigitalOut led(LED1);
PwmOut mypwm(PWM_OUT);

int main() {
    //declaring the required variables
    float meas_r;
    float meas_v;
    
    printf("\nAnalogIn example\n"); 
    
    while(1) {
        meas_r = analog_value.read(); // Converts and read the analog input value (value from 0.0 to 1.0)
        meas_v = meas_r * 3300; // Change the value to be in the 0 to 3300 range
        mypwm.period_ms(3300); //declares pulse period to be 3300
        mypwm.pulsewidth_ms(meas_v); //sets parameter pulse width to be meas_v
        printf("measure = %f = %0.f mV\n",meas_r,meas_v); //prints the values of meas_r and meas_v
        
        
        if (meas_v > 1000) { // If the value is greater than 1V then switch the LED on
          led = 1;
        }
        else {
          led = 0;
        }
        wait(0.1); // 200 ms
    }
}
