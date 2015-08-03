/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdbool.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    A_B_Start();
    C_D_Start();
    E_F_Start();
    G_A_Start();
    OutMux_Start();
    Pot_Vals_Start();
    ADC_Start();
    Tremolo_Start();
    Amp_Start();
    
    uint8 InputReg;
    int16 Pot_A_val;
    int16 Pot_B_val;
    
    Amp_SetGain(Amp_GAIN_01);
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        

        Pot_Vals_Select(0);
        CyDelay(25);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        Pot_A_val = ADC_GetResult16();


        
        Pot_Vals_Select(1);
        CyDelay(25);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        Pot_B_val = ADC_GetResult16();
        
        
        InputReg = Status_Reg_Read();
        
        
        switch(InputReg){
            
         case 1:
            
            Control_Reg_Write(0); //0000
            OutMux_Select(0);    
            
         break;
            
         case 2:
            
            Control_Reg_Write(1); //0001
            OutMux_Select(0);   
            
         break;
            
         case 4:
            
            Control_Reg_Write(1); //0001
            OutMux_Select(1);            
            
         break;
            
         case 8:
            
            Control_Reg_Write(2); //0010
            OutMux_Select(1);
             
         break;
            
         case 16:
            
        Control_Reg_Write(2); //0010
        OutMux_Select(2);            
            
         break;
            
         case 32:
            
        Control_Reg_Write(4); //0100
        OutMux_Select(2);            
            
         break;
            
         case 64:
            
        Control_Reg_Write(4); //0100
        OutMux_Select(3);                       
            
         break;
            
         case 128:
            
        Control_Reg_Write(8); //1000
        OutMux_Select(3);                 
            
         break;
            
         default:
            
            OutMux_DisconnectAll();
            
         break;
            
        }
        
        Pot_A_val = Pot_A_val*20/1024;
        Pot_B_val = Pot_B_val*3/1024;
                
        if(Pot_A_val > 1){
            
            CyDelay(Pot_A_val*5);
            Tremolo_Select(1);
            CyDelay(Pot_A_val*5);
            Tremolo_Select(0);
            
        }else{
            
            Tremolo_Select(0);
            
        }
        
        switch(Pot_B_val){
            
         case 0: 
            Amp_SetGain(Amp_GAIN_01);
            break;
            
         case 1:
            Amp_SetGain(Amp_GAIN_02);
            break;
            
         case 2: 
            Amp_SetGain(Amp_GAIN_04);
            break;
            
         default:
            Amp_SetGain(Amp_GAIN_01);
            break;
                       
        }
        
    }
    
}

/* [] END OF FILE */
