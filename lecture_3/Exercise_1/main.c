#include <stdio.h>

/**
  * @brief  This function copying all digits from string str1 to output string str2.
  * @param  none
  * @retval none
  */
int main()
{
    char str1[] = "aa2ap0r6oba8";
    char str2[sizeof(str1)];
    char *p,*s;
    

printf("str1 is: %s\n", str1); 
    int i;
    s = &str1;
    p = &str2;
    for(i = 0; i < strlen(str1); i++)
    {
        if(isdigit(*s))
        {
            *p = *s;
            p++;
        }
        s++;
    }
printf("str2 is: %s\n", str2);    

return 0;
}
