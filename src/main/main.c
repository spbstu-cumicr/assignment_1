#include "test/test.h"

#include <stdint.h>
#include <stdbool.h>

// Фамилия (UTF-8)
static const char *lastName = "Pankov";

int main(void)
{
    // Вариант
    volatile uint8_t variant = 0;
    
    // Контрольная сумма
    volatile uint32_t checksum = 0;
    
    // Структура со значениями частот
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);	
    
    // Инициализируем тестирующую прошивку
    testInit();
    
    // Запрашиваем вариант
    variant = testGetVariant(lastName);
    
    // Получаем контрольную сумму
    while (true)
    {
        checksum = testGetChecksum();
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
    while (true)
    {
         // это ассемблерная инструкция "отладчик, стой тут"
         // если вы попали сюда, значит вы ошиблись в параметрах вызова функции из SPL. 
         // Смотрите в call stack, чтобы найти ее
         __BKPT(0xAB);
    }
}

#endif
