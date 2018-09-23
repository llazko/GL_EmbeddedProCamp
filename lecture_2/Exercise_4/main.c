#include <stdio.h>

#define M_PI            3.14159265358979323846

int main()
{
    float r = 6; // radius, m.
    printf("It is given circle with r = %f m\n", r);
    float p = 2 * M_PI * r;
    printf("Perimeter of circle is %f m\n", p);
    float a = M_PI * r * r;
    printf("Area of circle is %f square m^2\n", a);
    
    return 0;
}
