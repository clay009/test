/*
* for STEP motor header 
STK682 CONTROLER
*/

#ifndef MOTOR_STEP_H_
#define MOTOR_STEP_H_ 

//STEP_EN PA10	//out put enable
#define EN_PORT		GPIOA
#define EN_PIN		GPIO_Pin_10
#define STEP_EN_H()	GPIO_SetBits(EN_PORT, GPIO_Pin_10)
#define STEP_EN_L()	GPIO_ResetBits(EN_PORT, GPIO_Pin_10)

//STEP_CW PA11 //forward/reverse 
#define CW_PORT		GPIOA
#define CW_PIN		GPIO_Pin_11
#define STEP_CW_H()	GPIO_SetBits(CW_PORT, CW_PIN)
#define STEP_CW_L()	GPIO_ResetBits(CW_PORT, CW_PIN)

//STEP_CLK PA12
#define CLK_PORT	GPIOA
#define CLK_PIN		GPIO_Pin_12
#define STEP_CLK_H()	GPIO_SetBits(GPIOA, GPIO_Pin_12)
#define STEP_CLK_L()	GPIO_ResetBits(GPIOA, GPIO_Pin_12)

//M1_FDT PC9	//decay mode select
#define FDT_PORT	GPIOC
#define FDT_PIN		GPIO_Pin_9
#define STEP_FDT_H()	GPIO_SetBits(FDT_PORT, FDT_PIN)
#define STEP_FDT_L()	GPIO_ResetBits(FDT_PORT, FDT_PIN)

//M1_M1 	PC10 //excitation mode 	switching pin
#define M1_PORT		GPIOC
#define M1_PIN		GPIO_Pin_10
#define STEP_M1_H()	GPIO_SetBits(M1_PORT, M1_PIN)
#define STEP_M1_L()	GPIO_ResetBits(M1_PORT, M1_PIN)

//M1_M2		PC11
#define M2_PORT		GPIOC
#define M2_PIN		GPIO_Pin_11
#define STEP_M2_H()	GPIO_SetBits(M2_PORT, M2_PIN)
#define STEP_M2_L()	GPIO_ResetBits(M2_PORT, M2_PIN)

//M1_M3		PC12
#define M3_PORT		GPIOC
#define M3_PIN		GPIO_Pin_12
#define STEP_M3_H()	GPIO_SetBits(M3_PORT, M3_PIN)
#define STEP_M3_L()	GPIO_ResetBits(M3_PORT, M3_PIN)

void STEP_M_init(void);
#endif//MOTOR_STEP_H_
