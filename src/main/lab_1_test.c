#include "lab_1_test.h"

static uint32_t checksum;

uint8_t initTest(const char *lastName)
{
    checksum = Lab1_Test_ini((char *)lastName);
    return get_variant();
}

uint32_t getChecksum(void)
{
    return checksum;
}
