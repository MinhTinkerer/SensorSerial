/* 
 * File:   newmain.c
 * Author: Aldo Axel Alcántar Aguirre
 *
 * Created on 28 de marzo de 2013, 03:07 PM
 *
 * Este programa lee el valor desde un sensor analógico de temperatura
 * MCP9700A y lo transmite a través de la UART del PIC16F877A.
 */

//Este es un comentario que solo sirve para ver diff..
#include <16f877a.h>
#device adc = 8
#fuses NOWDT,XT
#use delay (clock = 4000000)
#use rs232(uart1, baud=9600)//RS-232, definimos UART y velocidad.
#use fast_io(b)//Optimizamos E/S del PORTB

void main ()
{
   int valor;
   float temp;

   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_tris_b(0xFE);   //Pin RB0 como salida, el resto como entrada.

   for(;;){
      set_adc_channel(0);
      delay_us(20);
      valor = read_adc();
      temp = (valor*100);
      putc(temp);

      output_low(PIN_B0);   //Apaga el LED.
      delay_ms(500);        //Espera 500ms.
      output_high(PIN_B0);  //Enciende el LED.
      delay_ms(500);
   }
}

