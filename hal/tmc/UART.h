/*
 * UART.h
 *
 *  Created on: 23.01.2020
 *      Author: LK
 */

#ifndef HAL_TMC_UART_H_
#define HAL_TMC_UART_H_

#include "Connection.h"
#include "RXTX.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"

typedef struct {
	TMC_Connection con;
	UART_HandleTypeDef huart;
	DMA_HandleTypeDef hdma_rx;
	TMC_RXTX_Buffer buffer_rx;
	uint32_t cndtr;
} TMC_UART;

TMC_UART UART0;

void UART_Init(TMC_UART *interface);
void UART_deInit(TMC_UART *interface);
void UART_txRequest(TMC_UART *interface, uint8_t *data, uint16_t size, uint32_t timeout);
void UART_rxRequest(TMC_UART *interface, uint8_t *data, uint16_t size, uint32_t timeout);
void UART_txN(TMC_UART *interface, size_t size);
void UART_rxN(TMC_UART *interface, uint8_t *data, size_t size);
uint8_t UART_rx(TMC_UART *interface);
size_t UART_dataAvailable(TMC_UART *interface);
void UART_resetBuffers(TMC_UART *interface);

void UART0_Init(void);
void UART0_deInit(void);
void UART0_txRequest(uint8_t *data, uint16_t size, uint32_t timeout);
void UART0_rxRequest(uint8_t *data, uint16_t size, uint32_t timeout);
void UART0_txN(size_t size);
void UART0_rxN(uint8_t *data, size_t size);
uint8_t UART0_rx(void);
size_t UART0_dataAvailable(void);
void UART0_resetBuffers(void);

#endif /* HAL_TMC_UART_H_ */
