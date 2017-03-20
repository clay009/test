#include "stm32f10x.h"
#include "motor_step.h"

/*
//excitation setting //default state at start-up/reset
M3	M2	M1	MODE_exciation
L		L		L		2 PHASE
L		L		H		1-2PHASE
L		H		L		W1-2
L		H		H		2W1-2
H		L		L		4W1-2
H		L		H		8W1-2
H		H		L		16W1-2
H		H		H		32W1-2
*/

void STEP_M_set_excitation(int mode){
	switch(mode){
		case 0:
			STEP_M3_L();
			STEP_M2_L();
			STEP_M1_L();
			break;
		case 1:
			STEP_M3_L();
			STEP_M2_L();
			STEP_M1_H();
			break;
		case 2:
			STEP_M3_L();
			STEP_M2_H();
			STEP_M1_L();
			break;
		case 3:
			STEP_M3_L();
			STEP_M2_H();
			STEP_M1_H();
			break;
		case 4:
			STEP_M3_H();
			STEP_M2_L();
			STEP_M1_L();
			break;
		case 5:
			STEP_M3_H();
			STEP_M2_L();
			STEP_M1_H();
			break;
		case 6:
			STEP_M3_H();
			STEP_M2_H();
			STEP_M1_L();
			break;
		case 7:
			STEP_M3_H();
			STEP_M2_H();
			STEP_M1_H();
			break;
		default:
		break;
	}
}

/*	CLK pin step signal iputt allows advancing excitation step 
VCC == H 
CLK rasing edge : excitation step feed
CLK failing	edge:	excitation step hold
*/
void STEP_M_CLK_toggle(void){
	//GPIO_PORT[Led]->ODR ^= GPIO_PIN[Led];		//取反输出寄存器数据
	//GPIOA->ODR ^= GPIO_Pin_12;
	CLK_PORT->ODR ^= CLK_PIN;
}

/* CW/CCW 
L: CW  FORWORD  excitation: 1->2->3->4
H: CCCW BACKWOARD	excation: 6->5->4
at clk rasing edge
*/
void STEP_MOT_set_clockwise(bool wise){
	if(wise){
		STEP_CW_H();
	}
	else{
		STEP_CW_L();
	}
}

/*
When the ENABLE pin is set Low, the output is forced OFF and goes to high impedance. However, the internal logic
circuits are operating, so the excitation position proceeds when the CLK is input. Therefore, when ENABLE pin is
returned to High, the output level conforms to the excitation position proceeded by the CLK input.
*/

/*
FDT 
>3.5v	SLOW DECAY
1.1V~3.1V OR OPEN : MIXED DECAY
<0.8V	FAST DECAY
*/
void STEP_M_IO_init(){
	GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB| RCC_APB2Periph_GPIOC| RCC_APB2Periph_GPIOD, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = EN_PIN;//STEP_EN PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(EN_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = CW_PIN;//STEP_CW PA11 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(CW_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = CLK_PIN;//STEP_CLK PA12 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(CLK_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = FDT_PIN;//M1_FDT PC9
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(FDT_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = M1_PIN;////M1_M1 	PC10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(M1_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = M2_PIN;////M1_M2 	PC11
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(M2_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = M3_PIN;////M1_M3 	PC12
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(M3_PORT, &GPIO_InitStructure);


}

void STEP_M_init(void){
	STEP_M_IO_init();
}

