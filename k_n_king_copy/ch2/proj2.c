#include <stdio.h>
#define PI_CONSTANT 3.14

int main(void)
{
    float radius = 10.0;
    printf("Radius is: %.1f\n", radius);

    // volume = 4/3 * pi * r^3
    float volume = (4.0f / 3.0f) * PI_CONSTANT * radius;
    printf("Volume: %f\n", volume);
    return 0;
}