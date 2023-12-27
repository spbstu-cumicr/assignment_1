#pragma once

#include "stm32f4xx.h"
#include "stdio.h"

uint32_t Lab1_Test_ini(char *name);
uint8_t get_variant(void);

static inline void testInit(void)
{
    
}

uint8_t testGetVariant(const char *lastName)
{
    Lab1_Test_ini((char *)lastName);
    return get_variant();
}

static inline uint32_t testGetChecksum(void)
{
    return Lab1_Test_ini("");
}
