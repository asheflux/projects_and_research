#include <stdio.h>
#define PI_CONSTANT 3.14

int main(void)
{
    float radius = 0.0;
    printf("Radius is: ");
    scanf("%f", &radius);  //conversion specifier
    // volume = 4/3 * pi * r^3
    float volume = (4.0f / 3.0f) * PI_CONSTANT * radius;
    printf("Volume: %f\n", volume);
    return 0;
}