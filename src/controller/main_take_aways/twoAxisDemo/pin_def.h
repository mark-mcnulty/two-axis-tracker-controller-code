#ifndef pin_def_h
#define pin_def_h

// Az
#define END00 PA_8     // pwm0     // endstop00
#define END01 PC_6     // pwm1     // endstop01
#define ENCOD0 PC_7     // pwm2     // encoder0
#define DIR_REL01 PG_7     // pwm3         // dir_relay01
#define DIR_REL00 PJ_11    // pwm4         // dir_relay00


// El
#define ENCOD1 PK_1    // pwm5     // endstop10
// #define END11 PH_15    // pwm6     // endstop11
// #define ENCOD1 PJ_7    // pwm7     // encoder1
// #define DIR_REL11 PJ_10    // pwm8     // dir_relay11
// #define DIR_REL10 PH_6    // pwm9     // dir_relay10




#define D7 PI_0     // spi cs

#define D77 PA_0C   //ADC A0     
#define POWER1 PA_1C   //ADC A1     // power_relay1

#define DIR_REL10 PC_2C   //ADC A2     
#define DIR_REL11 PC_3C   //ADC A3
#define END10 PC_2    //ADC A4
#define END11 PC_3    //ADC A5
#define D21 PA_4    //ADC A6
#define D14 PA_9
#define POWER0 PA_6                   // power_relay0

#endif 