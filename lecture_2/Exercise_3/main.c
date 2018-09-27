#include <stdio.h>

int main()
{
    float h; // heigth
    float w; // weight
    printf("Specify heigth, m:\n");
    scanf("%f",&h);
    printf("Specify weight, m:\n");
    scanf("%f",&w);
    printf("you have specified rectangule with parameters:\n");
    printf("Height %f m;\n", h);
    printf("Weight %f m;\n", w);
    //convert to inches as values in m not needed enymore
    h = h * 100 / 2.54;
    w = w * 100 / 2.54;
    
    float p = 2 * (h + w);
    printf("Perimeter is %f inches\n", p);
    float a = h * w;
    printf("Area is %f square inches\n", a);
    
    return 0;
}
