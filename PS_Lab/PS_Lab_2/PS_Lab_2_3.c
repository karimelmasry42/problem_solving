#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() { 
    int vi, vf;
    float time, a, time_to_halt;
    vi = 200;
    vf = 150;
    time = 1.0/60;
    a = (vi - vf)/time;
    time_to_halt = (vi - vf)/a;
    printf("acceleration = %f mph^2, time to halt = %f h", a, time_to_halt);
    return 0; }