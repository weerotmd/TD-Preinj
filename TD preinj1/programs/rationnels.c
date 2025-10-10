#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>


typedef struct {
  float num;
  float den;
} Rationel;

void displayRationel(Rationel a) {
  printf("%f/%f\n", a.num, a.den);
}
void addMult(Rationel *a, Rationel *b) {
  Rationel c;
  c.num = a->num;
  c.den = a->den;
  a->num=c.num*b->num;
  a->den=c.den*b->den;
  printf("Mult: %f %f\n", c.num*b->num, c.den*b->den);
  b->num=(c.num/c.den)+(b->num/b->den);
  b->den=1;
  printf("Add: %f %f\n", c.num/c.den, b->num/b->den);
}

int main(int argc, char const *argv[]) {
  Rationel a, b;
  a.num = 1;
  a.den = 2;
  b.num = 3;
  b.den = 4;
  addMult(&a, &b);
  printf("Produit: ");
  displayRationel(a);
  printf("Somme: ");
  displayRationel(b);
  return 0;
}
