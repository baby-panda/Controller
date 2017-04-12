#ifndef __VALVE_H
#define __VALVE_H

#include "stm32f1xx_hal.h"
#include "SEGGER_RTT.h"

#define BANK0 0X01
#define BANK1 0X02
#define BANK2 0X04

#define ON_OFF_MAX 4
#define FLASH_ADDR ((uint32_t)0x0801FC00)
//flash地址从0x08000000开始，使用第128个1KB的page存储电磁阀的参数

typedef uint16_t on_off[2]; //电磁阀开启关闭时刻count的一对设定值的结构
typedef struct valve_param_s
{
  on_off    on_offs[ON_OFF_MAX];
  uint16_t  high_duration;  //高压通路的持续时间
} valve_param_t;
typedef struct valve_s
{
  uint16_t  high_duration;  //高压通路的持续时间
} valve_t;

void valve_init(void);
void valve_channel_on(uint8_t channel);
void valve_channel_off(uint8_t channel, uint8_t Hi_Lo);

void valve_params_load(void);
void valve_params_store(void);
#endif /* __VALVE_H */