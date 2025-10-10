#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


int main() {
  int n = 0;
  printf("Enter a number: ");
  int scanAnswer = scanf(" %d", &n);
  int i = n-1;
  while (i>1 && (n%i)!=0) {
    i--;
  }
  if (n%i==0 && i!=1) {
    printf("Not prime: %d/%d=%d\n", n, i, n/i);
  }else {
    printf("Prime\n");
  }
  printf("\n\n");
  return 0;
}
