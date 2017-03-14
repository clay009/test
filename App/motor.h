
#ifndef MOTOR_H_
#define MOTOR_H_ 

#define  CH1_ON()   	GPIO_ResetBits(GPIOC, GPIO_Pin_6)
#define  CH1_OFF()   	GPIO_SetBits(GPIOC, GPIO_Pin_6)
#define  CH1N_ON()   	GPIO_ResetBits(GPIOA, GPIO_Pin_7)
#define  CH1N_OFF()   	GPIO_SetBits(GPIOA, GPIO_Pin_7)
#define  CH2_ON()   	GPIO_ResetBits(GPIOC, GPIO_Pin_7)
#define  CH2_OFF()   	GPIO_SetBits(GPIOC, GPIO_Pin_7)
#define  CH2N_ON()   	GPIO_ResetBits(GPIOB, GPIO_Pin_0)
#define  CH2N_OFF()   	GPIO_SetBits(GPIOB, GPIO_Pin_0)
#define  CH3_ON()   	GPIO_ResetBits(GPIOC, GPIO_Pin_8)
#define  CH3_OFF()   	GPIO_SetBits(GPIOC, GPIO_Pin_8)
#define  CH3N_ON()   	GPIO_ResetBits(GPIOB, GPIO_Pin_1)
#define  CH3N_OFF()   	GPIO_SetBits(GPIOB, GPIO_Pin_1)


void MOTOR_init(void);
void MOTOR_start(void);
void MOTOT_stop(void);

void MOTOR_run_step(void);
void MOTOR_set_direction(bool wise);

//void MOTOR_clockwise_run_one_step(void);
//void MOTOR_anti_clockwise_run_one_step(void);

#endif
