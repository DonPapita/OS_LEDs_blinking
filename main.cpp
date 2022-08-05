/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Este programa permite parpadear los tres led integrados en las tarjetas de desarrollo FRDM
 * Ejemplo didactico para el curso Reto Medio del programa de fisica - Universidad EIA
 
 * Desarrollado a partir del ejemplo 
 * Por:     Juan Luis Palacio
 * agosto de 2022
 */

#include "mbed.h"


// Directivas de preprocesador para establecer el semiperodo de parpadeo de los LEDs
// La unidad "ms" es válida para la versión 6 de Mbed OS
#define BLINKING_R  1820ms        
#define BLINKING_G  2250ms
#define BLINKING_B  1230ms

//  ******  Creacion de los hilos de procesamiento  ****************************************************************************************
    //  Reserva de memoria para hilo de procesamiento
unsigned char G_buffer[1024];                                   //  1024 bytes - Buffer de memoria para el hilo del led verde
unsigned char B_buffer[1024];                                   //  1024 bytes - Buffer de memoria para el hilo del led verde
    //  Creacion de los hilos de procesamiento
Thread thread_ledG(osPriorityNormal, 1024, &G_buffer[0]);       //  Hilo del led verde (prioridad normal, tamano de bufer: 1024 bytes)       
Thread thread_ledB(osPriorityNormal, 1024, &B_buffer[0]);       //  Hilo del led azul (prioridad normal, tamano de bufer: 1024 bytes)
//  ****************************************************************************************************************************************

//  ******  Inicializacion de perifericos   ************************************************************************************************
    //  Salidas digitales para los leds integrados en las tarjetas de desarrollo Freedom Board (FRDM-KL25Z, FRDM-K64F)
DigitalOut ledR(LED1,1);                                        //  Led rojo (LED1), inicializa apagado (estado 1)
DigitalOut ledG(LED2,1);                                        //  Led verde (LED2), inicializa apagado (estado 1)
DigitalOut ledB(LED3,1);                                        //  Led azul (LED3), inicializa apagado (estado 1)
//  ****************************************************************************************************************************************

//  ******  Funciones a ejecutar en los hilos de procesamiento  ****************************************************************************
    //  Funcion parpadeo led verde
void blink_LedG() {
    while (true) {
        ThisThread::sleep_for(BLINKING_G);
        ledG = !ledG;
    }
}
    //  Funcion parpadeo led azul
void blink_LedB() {
    while (true) {
        ThisThread::sleep_for(BLINKING_B);
        ledB = !ledB;
    }
}
//  ****************************************************************************************************************************************

//  Hilo principal - Main
int main()
{
    // Inicia hilos de procesamiento
    thread_ledG.start(blink_LedG);                              //  Hilo del led verde - funcion blink_ledG()
    thread_ledB.start(blink_LedB);                              //  Hilo del led verde - funcion blink_ledG()

    //  Ciclo de parpadeo del led rojo
    while (true) {
        ThisThread::sleep_for(BLINKING_R);
        ledR = !ledR;
    }
}
