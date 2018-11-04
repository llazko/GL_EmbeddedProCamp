/**
  * @Brief: Create FIFO library based on Arrays
  */
#include <stdio.h>
#define depth 5

int fifo[depth];
int rdptr;
int wrptr;
int len; /* fifo status: 0 - empty; depth - full; (0 < len <= depth) - num of occupied cells */ 

/**
  * @brief  Status check.
  * @param  None
  * @retval >=0 - num of occupied cells; -1 - error
  * 
  */
int Status()
{
    if ( (len >=0) && (len <= depth))
    {
        return len;
    }
    if ( (len < 0) || (len > depth))
    {
        return -1; /*Overrun of underrun happened*/
    }
}
/**
  * @brief  Put value to FIFO.
  * @param  val - value to be put
  * @retval none
  * 
  * Check status before Put.
  */
int Put(int val)
{
	int st;
	st = Status();
	if ((st == -1) || st == depth)
	{
		printf("PUT Error \n");
		return -1;
	}

    fifo[wrptr] = val;
    if (wrptr != depth - 1)
    {
        wrptr++;
    }
    else
    {
        wrptr = 0;
    }
        len++;
}

/**
  * @brief  Get value from FIFO.
  * @param  none
  * @retval val
  * 
  * Check status before get
  */
int Get()
{
    int val = fifo[rdptr];
	int st;
	st = Status();

	if ((st == -1) || st == 0)
	{
		printf("GET Error \n");
		return -1;
	}

    if (rdptr != depth - 1)
    {
        rdptr++;
    }
    else
    {
        rdptr = 0;
    }
        len--;
    return val;
}

/**
  * @brief  Read value from FIFO without changing pointers.
  * @param  None
  * @retval value
  * 
  * check status before reading
  */
int Read()
{
    return fifo[rdptr];    
}


int main()
{

    int val;
    /*Init the FIFO*/
    rdptr = 0;
    wrptr = 0;
    len = 0;

    printf("rdptr %d; wrptr %d; len %d; status %d\n",rdptr, wrptr,len,Status());

    val = 10; printf("Write val: %d\n",val); Put(val);
    val = 15; printf("Write val: %d\n",val); Put(val);
    printf("read val: %d\n",Get());
    printf("read val: %d\n",Get());
    val = 20; printf("Write val: %d\n",val); Put(val);
    val = 25; printf("Write val: %d\n",val); Put(val);
    val = 30; printf("Write val: %d\n",val); Put(val);
    val = 35; printf("Write val: %d\n",val); Put(val);
    val = 40; printf("Write val: %d\n",val); Put(val);
    printf("read val: %d\n",Get());
    printf("read val: %d\n",Get());
    printf("read val: %d\n",Get());
    val = 45; printf("Write val: %d\n",val); Put(val);
    printf("read val: %d\n",Get());
    printf("read val: %d\n",Get());
    printf("read val: %d\n",Get());
    printf("rdptr %d; wrptr %d; len %d; status %d\n",rdptr, wrptr,len,Status());

    printf("Provoke underrun\n"); val=Get();   
    printf("rdptr %d; wrptr %d; len %d; status %d\n",rdptr, wrptr,len,Status());

    printf("Provoke overfolw\n");
    rdptr = 0;
    wrptr = 0;
    len = 0;
    Put(55);
    Put(60);
    Put(65);
    Put(70);
    Put(75);
    Put(80);
    printf("rdptr %d; wrptr %d; len %d; status %d\n",rdptr, wrptr,len,Status());

}

