#include <stdio.h>
#include <string.h>

char source[] = "proba";
char dest[12] = "abracadabra";
/**
  * @brief  copy one string to another.
  * @param  dest - pointer to destination string. source - pointer to source string. n- number of symbols to be copied for safety reasone!!! 
  * @retval nothing
  */
void CopyStr(char * dest, char * source,int n) 
{
    strncpy(dest,source,n);
    dest[n]='\0'; /*0 terminator correctly close the string*/
}


int main()
{

    CopyStr(&dest, &source,sizeof(source)-1);
    printf("%s\n",dest); 
    return 0;
    
}

