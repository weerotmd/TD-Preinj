#include "main.h"
int fillArray(int tab[], int size) {
  for (size_t i = 0; i < size; i++) {
    srand( time(NULL)+i );
    int randint = rand()%500;
    tab[i] = randint;
  }
}
void printArray(int tab[], int size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d | ", tab[i]);
  }
  printf("\n");
}
int tabTri(int tab[], int i) {
  if (i == 0) {
    return 1;
  } else if (tab[i-1] < tab[i]) {
    tabTri(tab, i-1);
  } else {
    return 0;
  }
}
unsigned long getTimeMilliSec(){
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return (1000 * tv.tv_sec) + (tv.tv_usec / 1000);
}

int main(int argc, char const *argv[]) {
  unsigned long start = getTimeMilliSec();
  int tab[100];
  fillArray(tab, 100);
  printArray(tab, 100);
  unsigned long end = getTimeMilliSec();
  printf("Sorted: %d\n", tabTri(tab, 100));
  printf("Time: %d\n", start-end);
  return 0;
}
