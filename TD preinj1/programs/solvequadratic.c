#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>


typedef struct {
  float real;
  float imaginary;
} Complex;

int solve(float a, float b, float c, Complex *res1, Complex *res2) {
  float delta = pow(b, 2) - 4*a*c;
  printf("Delta: %f\n", delta);
  if (delta < 0) {
    res1->real = (-b)/(2*a);
    res2->real = (-b)/(2*a);
    res1->imaginary = (sqrtf(-delta))/(2*a);
    res2->imaginary = (-sqrtf(-delta))/(2*a);
    return 2;
  } else {
    res1->real = (-1*b+sqrtf(delta))/(2*a);
    res2->real = (-1*b-sqrtf(delta))/(2*a);
    res1->imaginary = 0;
    res2->imaginary = 0;
    if (res1->real == res2->real || a == 0) {
      return 1;
    }
    return 2;
  }
}

int main(int argc, char const *argv[]) {
  Complex res1, res2;
  int solutions = solve(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), &res1, &res2);
  printf("%d %f+i(%f) %f+i(%f)\n", solutions, res1.real, res1.imaginary, res2.real, res2.imaginary);
  return 0;
}
