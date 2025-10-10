#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int max2(int a, int b) {
  if (a>b) {
    return a;
  }
  return b;
}


int max4(int a, int b, int c, int d) {
  int max = max2(a,b);
  max = max2(max,c);
  max = max2(max,d);
  return max;
}


int main() {
  int a,b,c,d = 0;
  printf("Entrez un nombre a:");
  scanf("%d", &a);
  printf("Entrez un nombre b:");
  scanf("%d", &b);
  printf("Entrez un nombre c:");
  scanf("%d", &c);
  printf("Entrez un nombre d:");
  scanf("%d", &d);
  printf("max: %d\n", max4(a,b,c,d));

  return 0;
}
