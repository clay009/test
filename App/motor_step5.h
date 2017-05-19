/*
* for STEP  5 phase motor header 
timer 1 for pwm 123 1n 2n 3n
timer 4 for pwm 5 6 5n 6n
timer 6 for step 
*/

#ifndef MOTOR_STEP5_H_
#define MOTOR_STEP5_H_ 

//STEP5_CLK PA6 ---need tim3 ch1 for pwm
#define CLK5_PORT	GPIOA
#define CLK5_PIN		GPIO_Pin_7//12->6
#define STEP5_CLK_H()	GPIO_SetBits(CLK5_PORT, CLK5_PIN)
#define STEP5_CLK_L()	GPIO_ResetBits(CLK5_PORT, CLK5_PIN)
#define STEP5_CLK_TOGGLE() CLK5_PORT->ODR ^= CLK5_PIN
#define TEST5_CLK()  GPIOA->ODR ^= GPIO_Pin_12


extern void STEP5_init(void);
	
#endif//MOTOR_STEP5_H_
