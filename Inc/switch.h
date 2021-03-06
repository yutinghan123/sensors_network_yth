#ifndef __COMMAND_H
#define __COMMAND_H
#define K_ON(port, pin) HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET)
#define K_OFF(port, pin) HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET)
typedef enum
{
	ACT_OFF = 0,
	ACT_ON,
	ACT_STOP
}SwActType_t;
typedef enum
{
	SW_FAN = 0,
	SW_SUNSHADE,
	SW_TOPFILM,
	SW_SIDEFILM,
	SW_LIGHT
}CommandType_t;
typedef enum
{
	RES_OK = 0,
	RES_FAILED,
	RES_KEEP
}CommandResType_t;
typedef struct
{
	CommandType_t	type;				//类型
	SwActType_t	action;				//动作
	CommandResType_t result;	//命令执行结果
	SwActType_t status;				//状态
	BOOL_t				command_new;//新命令标志
	char *				cmdbuf;			//命令缓冲区
	uint8_t				cmdsize;		//命令缓冲区大小
	GPIO_TypeDef *k1_port;
	uint16_t			k1_pin;
	GPIO_TypeDef *k2_port;
	uint16_t			k2_pin;
}SW_Handle_t;//开关句柄
/*执行控制器命令*/
BOOL_t SW_Cmd_Exec(PtrQue_TypeDef * swq);
/*命令队列初始化*/
void SW_Que_Init(PtrQue_TypeDef * swq);
/*控制开关动作*/
void SW_Control(SW_Handle_t * sw);
CommandResType_t SW_OFF(SW_Handle_t * sw);
CommandResType_t SW_ON(SW_Handle_t * sw);
CommandResType_t SW_STOP(SW_Handle_t * sw);
#endif
