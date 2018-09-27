/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Date: 2018-26-09
 */

 
int main(void){
   return 0;
}
 
//    #include "sapi.h"         /* <= sAPI header */
//    
//    /* Callbacks - Declaraciones */
//    
//    void uartUsbReceiveCallback( void *unused );
//    void uartUsbSendCallback( void *unused );
//    
//    void uart232ReceiveCallback( void *unused );
//    void uart232SendCallback( void *unused );
//    
//    /* Callbacks de CDC UART - Declaraciones */
//    //void cdcUartReceiveCallback( void *unused );
//    //void cdcUartSendCallback( void *unused );
//    
//    /* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
//    int main(void){
//    
//       /* ------------- INICIALIZACIONES ------------- */
//    
//       /* Inicializar la placa */
//       boardConfig();
//    
//       /* Inicializar la UART_USB junto con las interrupciones de Tx y Rx */
//       uartConfig(UART_USB, 115200);   
//       // Seteo un callback al evento de recepción y habilito su interrupcion
//       uartRxInterruptCallbackSet(UART_USB, uartUsbReceiveCallback);
//       uartRxInterruptSet(UART_USB, true);
//       // Seteo un callback al evento de transmisor libre y habilito su interrupcion
//       uartTxInterruptCallbackSet(UART_USB, uartUsbSendCallback);
//       uartTxInterruptSet(UART_USB, true);
//       // Habilito todas las interrupciones de UART_USB
//       uartInterruptsSet(UART_USB, true);
//       
//       /* Inicializar la UART_232 */
//       uartConfig(UART_232, 115200);
//       // Seteo un callback al evento de recepción y habilito su interrupcion
//       uartRxInterruptCallbackSet(UART_232, uart232ReceiveCallback);
//       uartRxInterruptSet(UART_232, true);
//       // Seteo un callback al evento de transmisor libre y habilito su interrupcion
//       uartTxInterruptCallbackSet(UART_232, uart232SendCallback);
//       uartTxInterruptSet(UART_232, true);
//       // Habilito todas las interrupciones de UART_232
//       uartInterruptsSet(UART_232, true);
//       
//       // Mando para identificar cual es cual y para arrancar la secuencia (si no
//       // hasta que no se mande un byte desde cada terminal no funciona)
//       uartWriteByte(UART_USB, 'u');
//       uartWriteByte(UART_232, '2');
//       
//       
//    
//    //   /* Inicializar la CDC UART junto con las interrupciones de Tx y Rx */
//    //   usbDeviceInit(USB_CDC_UART);
//    //   // Seteo un callback al evento de recepción y habilito su interrupcion
//    //   usbDeviceCdcUartRxInterruptCallbackSet(uartUSBReceiveCallback);
//    //   usbDeviceCdcUartRxInterruptSet(true);
//    //   // Seteo un callback al evento de transmisor libre y habilito su interrupcion
//    //   usbDeviceCdcUartTxInterruptCallbackSet(uartUSBSendCallback);
//    //   usbDeviceCdcUartTxInterruptSet(true);
//    //   // Habilito todas las interrupciones de CDC UART
//    //   usbDeviceCdcUartInterruptSet(true);
//    
//    
//    
//       /* ------------- REPETIR POR SIEMPRE ------------- */
//    
//       while(1) {
//          /* Sleep until next Interrupt happens */
//          sleepUntilNextInterrupt();
//       }
//    
//       /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
//          por ningun S.O. */
//       return 0 ;
//    }
//    
//    /* Callbacks - Implementaciones */
//    
//    uint8_t dataToSendToUart232 = 0;
//    bool_t dataToSendToUart232Pending = FALSE;
//    
//    // Recibo de la PC en la UART_USB
//    void uartUsbReceiveCallback( void *unused )
//    {
//       dataToSendToUart232 = uartRxRead(UART_USB);
//       dataToSendToUart232Pending = TRUE;
//    }
//    // Envio a la PC desde la UART_232
//    void uart232SendCallback( void *unused )
//    {
//       if(dataToSendToUart232Pending){
//          uartTxWrite(UART_232, dataToSendToUart232);
//          dataToSendToUart232 = 0;
//          dataToSendToUart232Pending = FALSE;
//       }
//    }
//    
//    uint8_t dataToSendToUartUsb = 0;
//    bool_t dataToSendToUartUsbPending = FALSE;
//    
//    // Recibo de la PC en la UART_232
//    void uart232ReceiveCallback( void *unused )
//    {
//       dataToSendToUartUsb = uartRxRead(UART_232);
//       dataToSendToUartUsbPending = TRUE;
//    }
//    // Envio a la PC desde la UART_USB
//    void uartUsbSendCallback( void *unused )
//    {
//       if(dataToSendToUartUsbPending){
//          uartTxWrite(UART_USB, dataToSendToUartUsb);
//          dataToSendToUartUsb = 0;
//          dataToSendToUartUsbPending = FALSE;
//       }
//    }
//    
//    
//    
//    //uint8_t dataFromUartUsb = 0;
//    //bool_t dataFromUartUsbPending = FALSE;
//    //
//    ///* Callbacks de CDC UART - Implementaciones*/
//    //
//    //void cdcUartReceiveCallback( void *unused )
//    //{
//    //   dataFromUartUsb = cdcUartRxRead(UART_USB);
//    //   dataFromUartUsbPending = TRUE;
//    //}
//    //
//    //void cdcUartSendCallback( void *unused )
//    //{
//    //   if(dataFromUartUsbPending){
//    //      cdcUartTxWrite(dataFromUartUsb);
//    //      dataFromUartUsb = 0;
//    //      dataFromUartUsbPending = FALSE;
//    //   }
//    //}
//    