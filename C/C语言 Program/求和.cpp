#include<stdio.h>
#include <math.h>
main()
{
  int b,c,z;
  float S, a;
  S = 0; z = -1;
  b = 1; c = 2; a = 1;
  while (fabs(a) > 0.001) {
    S += a;
    a = (float)z * b / c;
    z = - z;
    b ++;
    c *= 2;
    }
  printf("S = %10.3f",S);
  return 0;
}
