/*
 * @Author: zhangqi zq9278@gmail.com
 * @Date: 2024-06-14 13:20:03
 * @LastEditors: zhangqi zq9278@gmail.com
 * @LastEditTime: 2024-06-14 15:40:27
 * @FilePath: \MediLiquid_Collector\HardWare\Src\usart_free_dma.c
 * @Description:
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
extern int a;
#include "usart_free_dma.h"

int ring_buffer_put(ring_buffer_t *buffer, uart_data *data)
{
    if ((buffer->head + 1) % buffer->size == buffer->tail)
    {
        // 缓冲区已满
        return -1;
    }
    buffer->data[buffer->head] = *data;
    buffer->head = (buffer->head + 1) % buffer->size;
    return 0;
}

int ring_buffer_get(ring_buffer_t *buffer, uart_data *data)
{
    if (buffer->head == buffer->tail)
    {
        // 缓冲区为空
        return -1;
    }
    *data = buffer->data[buffer->tail];
    buffer->tail = (buffer->tail + 1) % buffer->size;
    return 0;
}

void processData(PCTRL_MSG msg)
{
    uint16_t cmd_head = ((msg->cmd_head_high) << 8) | (msg->cmd_head_low); // 将两个8位值合并成一个16位值
    uint16_t cmd_type = ((msg->cmd_type_high) << 8) | (msg->cmd_type_low); // 将两个8位值合并成一个16位值
    // uint16_t data = ((msg->data_high) << 8) | (msg->data_low);			   // 指令类型
    float data = msg->data;
     HAL_GPIO_WritePin(BEE_GPIO_Port, BEE_Pin, GPIO_PIN_SET);
    switch (cmd_type)
    { 
       

    case 0x1100: // 电磁铁
        HAL_GPIO_WritePin(MAGNET_GPIO_Port, MAGNET_Pin, GPIO_PIN_SET);
        break;
    case 0x1000:
        HAL_GPIO_WritePin(MAGNET_GPIO_Port, MAGNET_Pin, GPIO_PIN_RESET);
        break;
    case 0x2100: // 开始
        HAL_GPIO_WritePin(SV_TAP_WATER_GPIO_Port, SV_TAP_WATER_Pin, GPIO_PIN_SET);
        break;
    case 0x2000:
        HAL_GPIO_WritePin(SV_TAP_WATER_GPIO_Port, SV_TAP_WATER_Pin, GPIO_PIN_RESET);
        break;
    case 0x3100:
        HAL_GPIO_WritePin(SV_MAIN_PUSH_GPIO_Port, SV_MAIN_PUSH_Pin, GPIO_PIN_SET);
        break;
    case 0x3000:
        HAL_GPIO_WritePin(SV_MAIN_PUSH_GPIO_Port, SV_MAIN_PUSH_Pin, GPIO_PIN_RESET);
        break;
    case 0x4100:
        HAL_GPIO_WritePin(SV_DETERGENT_GPIO_Port, SV_DETERGENT_Pin, GPIO_PIN_SET);
        break;
    case 0x4000:
        HAL_GPIO_WritePin(SV_DETERGENT_GPIO_Port, SV_DETERGENT_Pin, GPIO_PIN_RESET);
        break;
    case 0x5100:
        HAL_GPIO_WritePin(SV_AIR_SOURCE_GPIO_Port, SV_AIR_SOURCE_Pin, GPIO_PIN_SET);
        break;
    case 0x5000:
        HAL_GPIO_WritePin(SV_AIR_SOURCE_GPIO_Port, SV_AIR_SOURCE_Pin, GPIO_PIN_RESET);
        break;

    case 0x6100:
        HAL_GPIO_WritePin(AIR_MOTOR_GPIO_Port, AIR_MOTOR_Pin, GPIO_PIN_SET);
        break;
    case 0x6000:
        HAL_GPIO_WritePin(AIR_MOTOR_GPIO_Port, AIR_MOTOR_Pin, GPIO_PIN_RESET);
        break;

    case 0x7100:
        HAL_GPIO_WritePin(WATER_MOTOR_GPIO_Port, WATER_MOTOR_Pin, GPIO_PIN_SET);
        break;

    case 0x7000:
        HAL_GPIO_WritePin(WATER_MOTOR_GPIO_Port, WATER_MOTOR_Pin, GPIO_PIN_RESET);
        break;

    default:
        break;
    }
    HAL_Delay(200);
    HAL_GPIO_WritePin(BEE_GPIO_Port, BEE_Pin, GPIO_PIN_RESET);
}