#include <stdio.h>
#include <stdint.h>

uint16_t convert(uint32_t in888)
{
    uint8_t r,g,b;
    uint16_t out565;
    r = (uint8_t)(in888 >> 19 ) & 0x1f; // shift by 3 to convert 8b to 5b and additionaly by 16 to place bits ot 3-rd byte in first byte position
    g = (uint8_t)(in888 >> 10 ) & 0x3f; // shift by 2 to convert 8b to 6b and additionaly by 8 to place bits of 2-nd byte in first byte position
    b = (uint8_t)(in888 >> 3) & 0x1f;   // shift by 3 to convert 8b to 5b. Byte is on own position
//    printf("rgb888=0x%x; r=0x%x; g=0x%x, b=0x%x\n",in888, r,g,b);
    out565 = r << 11 | g << 5 | b;
//    printf("out 0x%x\n", out565);
    return out565;
}

int main()
{
    uint32_t RGB888 = 0x55aacc;
    uint16_t RGB565;

    printf("Initial value of RGB888 is:   0x%x\n", RGB888);
    RGB565 = convert(RGB888);
    printf("Converted value of RGB565 is: 0x%x\n", RGB565);
    return 0;
}
