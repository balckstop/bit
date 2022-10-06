#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t GetBitsFromUint32(uint32_t inputValue, uint8_t bitOffset, uint8_t bitLength) {
    uint32_t val = (inputValue >> bitOffset);
    if(bitLength>=32) {return val;}
    val = val & ((1<<bitLength) -1);
    return val;
}

uint32_t GetBitsFromUint32(const char* inputValue, uint8_t bitOffset, uint8_t bitLength) {

    uint32_t number = (uint32_t)strtol(inputValue, NULL, 0);
    uint32_t val = ( number >> bitOffset);
    if(bitLength>=32) {return val;}
    val = val & ((1<<bitLength) -1);
    return val;
}

int main()
{   
    uint32_t res = GetBitsFromUint32(0xABCDEF12,4,12);
    printf("0x%08X\n", res);
    uint32_t char_rest = GetBitsFromUint32("0xABCDEF12",4,12);
    printf("0x%08X\n", char_rest);
    return 0;
}
