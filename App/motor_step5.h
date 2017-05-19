/*
* for STEP  5 phase motor header 
timer 1 for pwm a an b bn c cn
A: 	PA8  	IN
AN:	PB13	OUT
B:	PA9		IN
BN:	PB14	OUT
C:	PA10	IN
CN:	PB15	OUT
timer 4 for pwm d dn e en
D:	PB6		IN
DN:	PB7		OUT
E:	PB8		IN
EN:	PB9		OUT
timer 6 for step 
*/

#ifndef MOTOR_STEP5_H_
#define MOTOR_STEP5_H_ 

#define PHASE_A_H_ON 		TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable)
#define PHASE_A_H_OFF 		TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable)
#define PHASE_AN_L_ON 	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable)
#define PHASE_AN_L_OFF 	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable)

#define PHASE_B_H_ON 		TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable)
#define PHASE_B_H_OFF 		TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable)
#define PHASE_BN_L_ON 	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable)
#define PHASE_BN_L_OFF 	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable)

#define PHASE_C_H_ON 		TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable)
#define PHASE_C_H_OFF 		TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable)
#define PHASE_CN_L_ON 	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable)
#define PHASE_CN_L_OFF 	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable)

#define PHASE_D_H_ON 		TIM_CCxCmd(TIM4, TIM_Channel_1, TIM_CCx_Enable)
#define PHASE_D_H_OFF 		TIM_CCxCmd(TIM4, TIM_Channel_1, TIM_CCx_Disable)
#define PHASE_DN_L_ON 	TIM_CCxCmd(TIM4, TIM_Channel_2, TIM_CCx_Enable)
#define PHASE_DN_L_OFF 	TIM_CCxCmd(TIM4, TIM_Channel_2, TIM_CCx_Disable)

#define PHASE_E_H_ON 		TIM_CCxCmd(TIM4, TIM_Channel_3, TIM_CCx_Enable)
#define PHASE_E_H_OFF 		TIM_CCxCmd(TIM4, TIM_Channel_3, TIM_CCx_Disable)
#define PHASE_EN_L_ON 	TIM_CCxCmd(TIM4, TIM_Channel_4, TIM_CCx_Enable)
#define PHASE_EN_L_OFF 	TIM_CCxCmd(TIM4, TIM_Channel_4, TIM_CCx_Disable)

#define PHASE_A_IN_ON 		TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable)
#define PHASE_A_IN_OFF 		TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable)
#define PHASE_AN_OUT_ON 	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable)
#define PHASE_AN_OUT_OFF 	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable)

#define PHASE_B_IN_ON 		TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable)
#define PHASE_B_IN_OFF 		TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable)
#define PHASE_BN_OUT_ON 	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable)
#define PHASE_BN_OUT_OFF 	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable)

#define PHASE_C_IN_ON 		TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable)
#define PHASE_C_IN_OFF 		TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable)
#define PHASE_CN_OUT_ON 	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable)
#define PHASE_CN_OUT_OFF 	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable)

#define PHASE_D_IN_ON 		TIM_CCxCmd(TIM4, TIM_Channel_1, TIM_CCx_Enable)
#define PHASE_D_IN_OFF 		TIM_CCxCmd(TIM4, TIM_Channel_1, TIM_CCx_Disable)
#define PHASE_DN_OUT_ON 	TIM_CCxCmd(TIM4, TIM_Channel_2, TIM_CCx_Enable)
#define PHASE_DN_OUT_OFF 	TIM_CCxCmd(TIM4, TIM_Channel_2, TIM_CCx_Disable)

#define PHASE_E_IN_ON 		TIM_CCxCmd(TIM4, TIM_Channel_3, TIM_CCx_Enable)
#define PHASE_E_IN_OFF 		TIM_CCxCmd(TIM4, TIM_Channel_3, TIM_CCx_Disable)
#define PHASE_EN_OUT_ON 	TIM_CCxCmd(TIM4, TIM_Channel_4, TIM_CCx_Enable)
#define PHASE_EN_OUT_OFF 	TIM_CCxCmd(TIM4, TIM_Channel_4, TIM_CCx_Disable)


//test only
#define CLK5_PORT	GPIOA
#define CLK5_PIN		GPIO_Pin_7//12->6
#define STEP5_CLK_H()	GPIO_SetBits(CLK5_PORT, CLK5_PIN)
#define STEP5_CLK_L()	GPIO_ResetBits(CLK5_PORT, CLK5_PIN)
#define STEP5_CLK_TOGGLE() CLK5_PORT->ODR ^= CLK5_PIN
//#define TEST5_CLK()  GPIOA->ODR ^= GPIO_Pin_12


extern void STEP5_motor_init(void);
extern void STEP5_motor_phase_INT(void);
	
#endif//MOTOR_STEP5_H_
