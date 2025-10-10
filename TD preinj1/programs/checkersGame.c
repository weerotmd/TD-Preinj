#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int askUserInput() {
  int a;
  printf("Enter a value:");
  int answer = scanf("%d", &a);
  if (answer<=0) {
    printf("-------------------%d-------------------\n", answer);
    return 0;
  }
  return a;
}
int arrayToZero(int tab[], int size) {
  for (size_t i = 0; i < size; i++) {
    tab[i] = 0;
  }
}
int fillArray(int tab[], int size) {
  srand( time(NULL) );
  for (size_t i = 0; i < size; i++) {
    int randint = rand()%5;
    tab[i] = randint;
  }
}
int fillArray2D(int row, int col, char tab[row][col]) {
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      //srand( time(NULL) + i + j );
      //int randint = rand()%5;
      tab[i][j] = '_';
    }
  }
}
int evenArray(int tab[], int size) {
  int a = 0;
  for (size_t i = 0; i < size; i++) {
    if (tab[i]%2==0) a++;
  }
  return a;
}
int absolute(int a) {
  return a < 0 ? -a : a;
}
int search(int tab[], int size, int value) {
  for (size_t i = 0; i < size; i++) {
    if (tab[i] == value) {
      return i;
    }
  }
  return -1;
}
void printTable2D(int row, int col, char tab[row][col]) {
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      if (i != 3 && i != 4 && i != 5 && i != 6) {
        if ((i%2==0 && j%2==0) || (i%2==1 && j%2==1)) {
          if(i<=2) printf("\033[32m");
          if(i>=7) printf("\033[31m");
        }
      }
      printf("%c ", tab[i][j]);
      printf("\033[0m");
    }
    printf("\n");
  }
}
void invertArray(int tab[], int size) {
  for (size_t i = 0; i < size/2; i++) {
    int buffer = tab[size-1-i];
    tab[size-1-i] = tab[i];
    tab[i] = buffer;
  }
}
void removeZeros(int tab[], int size) {
  int nonZeroNumbers = 0;
  int lastIndex = 0;
  for (size_t i = 0; i < size; i++) {
    if (tab[i] != 0) {
      nonZeroNumbers++;
    }
  }
  int tabWithoutZeros[nonZeroNumbers];
  for (size_t i = 0; i < size; i++) {
    if (tab[i] != 0) {
      tabWithoutZeros[lastIndex] = tab[i];
      lastIndex++;
    }
  }
  for (size_t i = 0; i < size; i++) {
    if (i<nonZeroNumbers) {
      tab[i] = tabWithoutZeros[i];
    }else {
      tab[i] = 0;
    }
  }
}
void makeCheckersGame(char tab[10][10]) {
  for (size_t x = 0; x < 10; x++) {
    for (size_t y = 0; y < 10; y++) {
      if (x != 3 && x != 4 && x != 5 && x != 6) {
        if ((x%2==0 && y%2==0) || (x%2==1 && y%2==1)) {
          tab[x][y] = 'X';
        }
      }
    }
  }
}

int main() {
  const int row = 10;
  const int col = 10;
  char t[row][col];
  fillArray2D(row, col, t);
  makeCheckersGame(t);
  printTable2D(row, col, t);
  return 0;
}
