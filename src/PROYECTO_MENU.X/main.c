/// Hugo Mario Rodríguez Mendoza 2420191008
/// Juan Jose Ardila Castiblanco 2420191028

#include "mcc_generated_files/mcc.h"
#include "I2C_LCD.h"

char punto = '.';
int clear = 0;
char* nombres[] = {"0.Harold Murcia","1.Luz Patricia","2.Flor Angela","3.Luz Ster", "4.Mauricio Vargas", "5.Oscar Barrero", "6.Fito", "7.Jose Armando"};
int estadoBotones[] = {0,0,0,0};

void Inicio(void)
{
    I2C_Master_Init();
    LCD_Init(0x4E);
    LED0_SetHigh();
}

void pantallaCarga(void)
{
    LCD_Set_Cursor(1, 1);
    LCD_Write_String("Inicializando");
    
    for (int i = 14; i < 18; i++)
    {
        LCD_Set_Cursor(1, i);
        LCD_Write_Char(punto);
        __delay_ms(1000);
    }
}

void Menu(int entrada)
{
    while (1)
    {
        
        switch (entrada)
        {
            case 0:
            
                if (clear == 0)
                {
                    LCD_Clear();
                    clear = 1;
                }
            
                LCD_Set_Cursor(1, 1);
                LCD_Write_String("Listado de docentes");
                LCD_Set_Cursor(2, 1);
                LCD_Write_String("disponibles...");
                __delay_ms(5000);
                clear = 0;
            
                if (clear == 0)
                {
                    entrada = 1;
                }
            
            break;
        
            case 1:
        
                if (clear == 0)
                {
                    LCD_Clear();
                    clear = 1;
                }
            
                LCD_Set_Cursor(1, 1);
                LCD_Write_String(nombres[0]);
    
                LCD_Set_Cursor(2, 1);
                LCD_Write_String(nombres[1]);
            
                LCD_Set_Cursor(3, 1);
                LCD_Write_String(nombres[2]);
            
                LCD_Set_Cursor(4, 1);
                LCD_Write_String(nombres[3]);

                if(!BOTON2_GetValue())
                {
                    estadoBotones[0] = 1;
                    __delay_ms(250);
                    clear = 0;
                    entrada = 3;
                }
                if(!BOTON3_GetValue())
                {
                    estadoBotones[1] = 1;
                    __delay_ms(250);
                    clear = 0;
                    entrada = 3;
                }
                if(!BOTON4_GetValue())
                {
                    estadoBotones[2] = 1;
                    __delay_ms(250);
                    clear = 0;
                    entrada = 3;
                }
                if(!BOTON5_GetValue())
                {
                    estadoBotones[3] = 1;
                    __delay_ms(250);
                    clear = 0;
                    entrada = 3;
                }
            
            break;
                 
            case 3:
                
                if (clear == 0)
                {
                    LCD_Clear();
                    clear = 1;
                }
                
                LCD_Set_Cursor(1, 1);
                LCD_Write_String("LLamando al docente");
                
                if(estadoBotones[0] == 1)
                {
                    LCD_Set_Cursor(2, 1);
                    LCD_Write_String(nombres[0]);
                    
                    for (int i = 0; i < 10; i++)
                    {
                        LED1_Toggle();
                        __delay_ms(250);
                    }
                    estadoBotones[0] = 0;
                    entrada = 0;
                }
                if(estadoBotones[1] == 1)
                {
                    LCD_Set_Cursor(2, 1);
                    LCD_Write_String(nombres[1]);
                    
                    for (int i = 0; i < 10; i++)
                    {
                        LED2_Toggle();
                        __delay_ms(250);
                    }
                    estadoBotones[1] = 0;
                    entrada = 0;
                }
                if(estadoBotones[2] == 1)
                {
                    LCD_Set_Cursor(2, 1);
                    LCD_Write_String(nombres[2]);
                    
                    for (int i = 0; i < 10; i++)
                    {
                        LED3_Toggle();
                        __delay_ms(250);
                    }
                    estadoBotones[2] = 0;
                    entrada = 0;
                }
                if(estadoBotones[3] == 1)
                {
                    LCD_Set_Cursor(2, 1);
                    LCD_Write_String(nombres[3]);
                    
                    for (int i = 0; i < 10; i++)
                    {
                        LED4_Toggle();
                        __delay_ms(250);
                    }
                    estadoBotones[3] = 0;
                    entrada = 0;
                }
                
            break;
            
        }
    }
}
void main(void)
{

    SYSTEM_Initialize();
    Inicio();
    pantallaCarga();
    Menu(0);
}
