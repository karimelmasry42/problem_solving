#include <stdio.h>
// #include <conio.h>
int main()
{
    float x, y, z;
    scanf("%f %f %f", &x, &y, &z);
    if (x > y)
    {
        if (x > z)
        {
            printf("%f", x);
        }
        else
        {
            printf("%f", z);
        }
    }
    else if (y > z)
    {
        printf("%f", y);
    }
    else
    {
        printf("%f", z);
    }
    // getch();
    return 0;
}