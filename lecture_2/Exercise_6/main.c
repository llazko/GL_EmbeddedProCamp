#include <stdio.h>

int main()
{
    int n = 500; // the given range.
    int i, d;
    float f;      // the result.
	printf("Specify the value of divider:\n");
	scanf("%d", &d);
        for(i=1; i<=n; ++i)
        {
            f = (float) i / d; // float convertion is needed to produce correct division result
			printf("%d divided by %d = %f\n", i, d, f);
        }
    
    return 0;
}
