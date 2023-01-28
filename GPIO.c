#include "lib/include.h"

#ifndef GPIO_H_
#define GPIO_H_
extern void Configurar_GPIO(void)
{
    //Paso 1 Enceder el periferico Run Clock Gate Control GPIO
                    //     C
    SYSCTL->RCGCGPIO |= (1<<2);//habilita los puertos
    while((SYSCTL->PRGPIO&0x20)==0){};
    //borra el bit correspondiente en el registro (0 disabled, 1 enable)
    GPIOC_AHB->PUR =  (1<<6) | (1<<7);
    //Paso 3  configurar GPIOAFSELF para habilitar pines como alternativos 
    GPIOC_AHB->AFSEL |= 0x00;
    GPIOC_AHB->PCTL |= 0x00;
    GPIOC_AHB->AMSEL|= 0x00;
    //paso 4 establecer el campo EDMn en el registro GPIOPC pagina 753
    GPIOC_AHB->PCTL|= 0x00;
    //paso 5 habilitar pines como digitales 
    GPIOC_AHB->DEN |= (1<<6)|(1<<7);
    //configurar evento de interrupcion PORTJ
    GPIOC_AHB->IM |= (0<<1) | (0<<0); //Limpiar los bits
    GPIOC_AHB->IS |= (0<<1) | (0<<0);
    GPIOC_AHB->IBE |= (0<<1) | (0<<0);
    GPIOC_AHB->IEV |= (1<<1) | (1<<0);
    GPIOC_AHB->RIS |= (0<<1) | (0<<0);
    GPIOC_AHB->IM |= (1<<1) | (1<<0);
    // numero de interrupcion PORTJ = 51
    // n=12 ----> [4n+3] [4n+2] [4n+1] [4n] ---> [4n+3]
 //   NVIC_PRI12_R = (NVIC_PRI12_R&0X00FFFFFF) | 0X80000000; //Jerarquia 4
 //   NVIC_EN1_R = 0X00080000;
}

extern void Prender_LED(void)
{
    static int i=0;
    GPIOF_AHB->DATA = i;
    i = i + 1;
}

extern void GPIOJ_INT_ISR(void)
{
    if (GPIOJ_AHB->RIS == (1<<0))//J0  el cero representara que se presiono el boton 0 y en pycharm se contara los ceros enviados
    {
        GPIOF_AHB->DATA = (0<<4);
      //  tarar(20,128);  //numero de datos, a que ganancia
    }
    if (GPIOJ_AHB->RIS == (1<<1))//J1 el uno representara que se presiono el boton 1
    {

        GPIOF_AHB->DATA = (0<<0);

        GPIOF_AHB->DATA = (1<<0);
   
    }
    GPIOJ_AHB->ICR |=(1<<0)|(1<<1);
}
extern void Delay(void)
{
    unsigned long volatile time; 
    time=16000000; 
    while(time)
    {
        time--; 
    }
}
#endif /* INCLUDE_H_ */