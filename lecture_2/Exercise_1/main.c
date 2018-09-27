#include <stdio.h>
#include <stdint.h>

/**
  * @brief  This function swaps bytes inside the uint16_t value.
  * @param  uint16_t input value
  * @retval uint16_t output value
  */
uint16_t swap16(uint16_t in)
{
	return  ((in & 0x00ff) << 8) | ((in>>8) & 0x00ff);
}

/**
  * @brief  This function swaps bytes inside the uint32_t value.
  * @param  uint32_t input value
  * @retval uint32_t output value
  */
uint32_t swap32(uint32_t in)
{
	return  ((in & 0x000000ff) << 24) | ((in & 0x0000ff00) <<  8) | \
	        ((in & 0x00ff0000) >>  8) | ((in & 0xff000000) >> 24);
}

/**
  * @brief  This function swaps bytes inside the uint64_t value using swap32() routine.
  * @param  uint64_t input value
  * @retval uint64_t output value
  */
uint64_t swap64(uint64_t in)
{
	return  ((uint64_t) swap32(in) << 32) | ((uint64_t) swap32((uint32_t)((in >> 32) & 0x00000000ffffffff))) ;
}

int main()
{
	uint16_t in16 = 0xc0fe;
	uint32_t in32 = 0xdeadbeaf;
	uint64_t in64 = 0x0123456789abcdef;
 
    printf("Initial value of uint16_t is: 0x%x\n", in16);
    printf("Swapped value of uint16_t is: 0x%x\n", swap16(in16));
    printf("\n");
    printf("Initial value of uint32_t is: 0x%x\n", in32);
    printf("Swapped value of uint32_t is: 0x%x\n", swap32(in32));
    printf("\n");
    printf("Initial value of uint64_t is: 0x%016llX\n", in64); //"0x%016llX" to printout uint64_t need to be revised in future revisions.
    printf("Swapped value of uint64_t is: 0x%016llX\n", swap64(in64));
    printf("\n");

    return 0;
}
