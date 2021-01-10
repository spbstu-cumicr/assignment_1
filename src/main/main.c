#include "mcu_support_package/inc/stm32f4xx.h"
#include "lab_1_test.h"

#include <stdint.h>

// Фамилия
static const char *lastName = "Pankov";

int main(void)
{   
    // Вариант задания
    static uint8_t variant = 0;
    
    // Контрольная сумма
    static uint32_t checksum = 0;
    
    // Структура со значениями частот
    static RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);	
    
    // Инициализируем тестовую прошивку
    variant = initTest(lastName);
    
    while(1)
    {
        // Считаем контрольную сумму
        checksum = getChecksum();
    }
    
    return 0;
}

#ifdef USE_FULL_ASSERT

// эта функция вызывается, если assert_param обнаружил ошибку
void assert_failed(uint8_t *file, uint32_t line)
{ 
    /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    
    (void)file;
    (void)line;
    
    __disable_irq();
    while(1)
    {
         // это ассемблерная инструкция "отладчик, стой тут"
         // если вы попали сюда, значит вы ошиблись в параметрах вызова функции из SPL. 
         // Смотрите в call stack, чтобы найти ее
         __BKPT(0xAB);
    }
}

#endif
