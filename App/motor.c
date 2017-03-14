/*
for AC sevor motor
*/
#include "stm32f10x.h"
#include "motor.h"

static char motor_phase = 1;
static bool motor_clockwise_direction = FALSE  ; // TRUE: clockwise, FALSE: anti clockwise

void MOTOR_IO_init(void){
	  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB| RCC_APB2Periph_GPIOC| RCC_APB2Periph_GPIOD, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//CH1 PC6
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//CH1N  PA7
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//CH2 PC7
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//CH2N  PB0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//CH3 PC8
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//CH3N  PB1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
}


void MOTOR_anti_clockwise_run_one_step(void){
	
	switch(motor_phase){
		case 0: //phase 1
			CH2_ON();
			CH2N_OFF();
			CH2_ON();
			CH2N_OFF();
			CH3_ON();
			CH3N_OFF();
			break;
		case 1: //phase 2
			CH2_ON();
			CH2N_OFF();
			CH1_ON();
			CH1N_OFF();
			CH3_OFF();
			CH3N_ON();
			break;
		case 2: //phase 3
			CH2_ON();
			CH2N_OFF();
			CH1_OFF();
			CH1N_ON();
			CH3_OFF();
			CH3N_ON();
			break;
		case 3: //phase 4
			CH2_OFF();
			CH2N_ON();
			CH1_OFF();
			CH1N_ON();
			CH3_OFF();
			CH3N_ON();
			break;
		case 4: //phase 5
			CH2_OFF();
			CH2N_ON();
			CH1_OFF();
			CH1N_ON();
			CH3_ON();
			CH3N_OFF();
			break;
		case 5: //phase 6
			CH2_OFF();
			CH2N_ON();
			CH1_ON();
			CH1N_OFF();
			CH3_ON();
			CH3N_OFF();
			break;
		default:
			motor_phase = 5; //error state do nothing
			break;
	};
	motor_phase=(motor_phase+1)%6;
}

void MOTOR_clockwise_run_one_step(void){
	
	switch(motor_phase){
		case 0: //phase 1
			CH1_ON();
			CH1N_OFF();
			CH2_ON();
			CH2N_OFF();
			CH3_ON();
			CH3N_OFF();
			break;
		case 1: //phase 2
			CH1_ON();
			CH1N_OFF();
			CH2_ON();
			CH2N_OFF();
			CH3_OFF();
			CH3N_ON();
			break;
		case 2: //phase 3
			CH1_ON();
			CH1N_OFF();
			CH2_OFF();
			CH2N_ON();
			CH3_OFF();
			CH3N_ON();
			break;
		case 3: //phase 4
			CH1_OFF();
			CH1N_ON();
			CH2_OFF();
			CH2N_ON();
			CH3_OFF();
			CH3N_ON();
			break;
		case 4: //phase 5
			CH1_OFF();
			CH1N_ON();
			CH2_OFF();
			CH2N_ON();
			CH3_ON();
			CH3N_OFF();
			break;
		case 5: //phase 6
			CH1_OFF();
			CH1N_ON();
			CH2_ON();
			CH2N_OFF();
			CH3_ON();
			CH3N_OFF();
			break;
		default:
			motor_phase = 5; //error state do nothing
			break;
	};
	motor_phase=(motor_phase+1)%6;
}

void MOTOR_run_step(void){
	if (motor_clockwise_direction)  
		MOTOR_clockwise_run_one_step();
	else 
		MOTOR_anti_clockwise_run_one_step();
}

void MOTOR_set_direction(bool wise){
	motor_clockwise_direction = wise;
}

TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
void TIM3_Configuration(int interval)
	{
		uint16_t peroid,scaler;
	/* TIM3 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
			
		
	if ((interval > 999)){ // > 100ms
			scaler = 7200;//ms
			peroid = interval / 100 ;
		}
		else if ((interval > 99)&&(interval < 1000)){ // 100ms~10ms
			scaler = 720; //100us
			peroid = interval /10;
		}
		else { //< 1000 us
			scaler = 72;//10us
			peroid = interval ;
		}
	
	/* ---------------------------------------------------------------
	TIM3CLK 即PCLK1=36MHz
	TIM3CLK = 36 MHz, Prescaler = 7200, TIM3 counter clock = 5K,即改变一次为5K,周期就为10K
	--------------------------------------------------------------- */
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = peroid; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =(scaler-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	/* Enables the Update event for TIM3 */
	//TIM_UpdateDisableConfig(TIM3,ENABLE); 	//使能 TIM3 更新事件 
	
	/* TIM IT enable */
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM3, //TIM2
		TIM_IT_Update  |  //TIM 中断源
		TIM_IT_Trigger,   //TIM 触发中断源 
		ENABLE  //使能
		);
	
	/* TIM3 enable counter */
	//TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
	}


void MOTOT_stop(void){
	//motor_phase = 0; not change
	TIM_Cmd(TIM3, DISABLE);
	CH1_OFF();
	CH1N_OFF();
	CH2_OFF();
	CH2N_OFF();
	CH3_OFF();
	CH3N_OFF();
}
void MOTOR_start(void){
	TIM_Cmd(TIM3, ENABLE);
}

void MOTOR_set_step_interval(int us){
	TIM3_Configuration(us);
}

void MOTOR_init(void){
	MOTOR_IO_init();
	MOTOT_stop();
	//TIM3_Configuration();
}



