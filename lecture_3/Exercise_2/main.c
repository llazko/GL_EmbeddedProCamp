#include <stdio.h>

/**
  * @brief  This function finds the biggest element in the integer array.
  * @param  none
  * @retval error code
  */
int main()
{
    int arr[] = {-5,-10,-100,-235,-15,-6,-17};
    int *m,*p;
    
    int i;
    /*init max value as first element of array*/
    m = &arr[0]; 
    /*init first next number for comparison*/
    p = &arr[0] + 1;
    printf("size %d\n",sizeof(arr)/sizeof(int));
    for(i = 1; i < sizeof(arr)/sizeof(int); i++) /*i=1 becouse 1-st number is the max for beginning and loop should start form next element*/
    { 
        if(*m < *p)
        {
            m = p;
        }
        p++;
    }
printf("max is: %d\n", *m);    

return 0;
}
