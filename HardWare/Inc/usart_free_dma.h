/*
 * @Author: zhangqi zq9278@gmail.com
 * @Date: 2024-06-14 13:20:57
 * @LastEditors: zhangqi zq9278@gmail.com
 * @LastEditTime: 2024-06-14 14:06:49
 * @FilePath: \MediLiquid_Collector\HardWare\Inc\usart_free_dma.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */

#include "main.h"
#ifndef __USART_FREE_DMA_H
#define __USART_FREE_DMA_H

#define RX_BUFFER_SIZE 204
#define UART_QUEUE_SIZE 10
#define UART_MSG_SIZE 100

typedef struct {
    uint8_t buffer[UART_MSG_SIZE];   // ?????‘????°????????????????
    uint16_t length;  // ??°???é??????
} uart_data;
typedef struct 
{
    uint8_t cmd_head_high; // 帧头
    uint8_t cmd_head_low; // 帧头
    uint8_t cmd_type_high; // 命令类型(UPDATE_CONTROL)
    uint8_t cmd_type_low; // 命令类型(UPDATE_CONTROL)
    float data;

} CTRL_MSG, *PCTRL_MSG;


typedef struct {
    uart_data data[UART_QUEUE_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t size;
} ring_buffer_t;

void processData(PCTRL_MSG msg);
int ring_buffer_put(ring_buffer_t *buffer, uart_data *data);
int ring_buffer_get(ring_buffer_t *buffer, uart_data *data);
#endif /* __USART_FREE_DMA_H */