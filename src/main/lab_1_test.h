#pragma once

#include "stm32f4xx.h"
#include "stdio.h"

uint32_t Lab1_Test_ini(char *name);
uint8_t get_variant(void);

uint8_t initTest(const char *lastName);
uint32_t getChecksum(void);
