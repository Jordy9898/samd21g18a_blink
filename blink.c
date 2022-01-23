// 'C' source line config statements

// Config Source code for XC32 compiler.
// USER_WORD_0
#pragma config NVMCTRL_BOOTPROT = SIZE_0BYTES
#pragma config NVMCTRL_EEPROM_SIZE = SIZE_0BYTES
#pragma config BOD33USERLEVEL = 0x7 // Enter Hexadecimal value
#pragma config BOD33_EN = ENABLED
#pragma config BOD33_ACTION = RESET
#pragma config WDT_ENABLE = DISABLED
#pragma config WDT_ALWAYSON = DISABLED
#pragma config WDT_PER = CYC16384
#pragma config WDT_WINDOW_0 = SET

// USER_WORD_1
#pragma config WDT_WINDOW_1 = 0x5 // Enter Hexadecimal value
#pragma config WDT_EWOFFSET = CYC16384
#pragma config WDT_WEN = DISABLED
#pragma config BOD33_HYST = DISABLED
#pragma config NVMCTRL_REGION_LOCKS = 0xFFFF // Enter Hexadecimal value

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
void delay();
void main(void) {
    
    SYSCTRL_REGS->SYSCTRL_OSC8M=SYSCTRL_OSC8M_ENABLE(1);
    GCLK_REGS->GCLK_CLKCTRL = GCLK_CLKCTRL_GEN_GCLK0 | GCLK_CLKCTRL_CLKEN(1);
    GCLK_REGS->GCLK_GENCTRL = GCLK_GENCTRL_IDC(1) | GCLK_GENCTRL_GENEN(1) | GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_OSC8M_Val) | GCLK_GENCTRL_ID(0);
    PM_REGS->PM_APBBMASK=PM_APBBMASK_PORT(1);
    
    PORT_REGS->GROUP[0].PORT_DIRSET = PORT_PA17; 
    
    while(1){
        PORT_REGS->GROUP[0].PORT_OUT^=PORT_PA17;
        delay();
        
    }
    return;
}

void delay(){
    
  for (uint32_t i = 0; i < 50000; i++)
    {
        __asm("nop");
    }
}
