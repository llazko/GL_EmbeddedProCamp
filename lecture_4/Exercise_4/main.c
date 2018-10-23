#include <stdio.h>

void foo1(void)
{
    printf("Its called, #1!!!\n");
}

void foo2(void)
{
    printf("Its called, #2!!!\n");
}

/**
  * @brief  call anouther function with its pointer.
  * @param  ptr 
  * @retval nothing
  */
void CallFn(void (*fun)(void)) 
{
    fun();
}


int main()
{

    CallFn(foo1);
    
    CallFn(foo2);
    
    
}

