////a1r12c0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomInteger()
{
  // printf("%d",rand()%10);//gives random number between 0 and 10, 10 not included.
  int upper, lower, random = rand();
  scanf("%d", &upper);
  scanf("%d", &lower);

  printf("\n RandomInteger is %d\n", random % (upper - lower + 1) + lower);
}

void RandomDouble()
{
    double upper=9.9, lower=0.9, result;

    scanf("%lf", &upper);
    scanf("%lf", &lower);
    int randomNumber = rand();
    result = ((double)randomNumber / RAND_MAX) * (upper-lower) + lower;
    printf("%d %d %f", randomNumber, RAND_MAX, result);
}

int main()
{
  srand(time(NULL));

  RandomInteger();
  RandomDouble();
}
