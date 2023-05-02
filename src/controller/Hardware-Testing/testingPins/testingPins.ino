#define PIN_N PJ_11    // pwm4  
#define PIN_OF PH_15    // pwm6 
#define PIN PH_15    // pwm5


#define END00 PA_8     // pwm0     // endstop00
#define END01 PC_6     // pwm1     // endstop01
#define ENCOD0 PC_7     // pwm2     // encoder0
#define D3 PG_7     // pwm3         // dir_relay01
#define D2 PJ_11    // pwm4         // dir_relay00
#define D1 PK_1     // pwm5
#define D0 PH_15    // pwm6

#define D7 PI_0     // spi cs // PWM 

#define D8  PC_3    
#define D9  PI_1
#define D10 PC_2
#define D11 PH_8
#define D12 PH_7
#define D13 PA_10
#define D14 PA_9

#define D21 PA_4    //ADC A6
#define D20 PC_3    //ADC A5
#define D19 PC_2    //ADC A4
#define D18 PC_3C   //ADC A3
#define DIR_REL01 PC_2C   //ADC A2     
#define DIR_REL00 PA_1C   //ADC A1    
#define POWER0 PA_0C   //ADC A0     // power_relay0
#define D14 PA_9


void setup(){
    pinMode(D21, INPUT);
    // digitalWrite(D21, HIGH);
    Serial.begin(9600);
}

void loop(){
  Serial.println(digitalRead(D21));
}
