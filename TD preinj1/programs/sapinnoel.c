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
      /*if (i != 3 && i != 4 && i != 5 && i != 6) {
        if ((i%2==0 && j%2==0) || (i%2==1 && j%2==1)) {
          if(i<=2) printf("\033[38;2;r;g;bm");
          if(i>=7) printf("\033[31m");
        }
      }*/
      printf("%c", tab[i][j]);
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
int maxOfSapin(int n) {
  int a=1;
  for (size_t i = 0; i < n; i++) {
    if (a>=n) {
      return i;
    }
    a+=2;
  }
  return 0;
}
void printSapin(int n, char tab[n][n]) {
  for (size_t x = 0; x < n; x++) {
    for (size_t y = 0; y < n; y++) {
      /*if (i != 3 && i != 4 && i != 5 && i != 6) {
        if ((i%2==0 && j%2==0) || (i%2==1 && j%2==1)) {
          if(i<=2) printf("\033[38;2;r;g;bm");
          if(i>=7) printf("\033[31m");
        }
      }*/
      printf("\033[38;2;25;85;0m");
      if (x<=maxOfSapin(n)) {
        srand( time(NULL) + x*y + y/(x+1));
        int docolor = rand()%3;
        srand( time(NULL)+1 + x*y + y/(x+1));
        int r = rand()%255;
        srand( time(NULL)+2 + x*y + y/(x+1));
        int g = rand()%255;
        srand( time(NULL)+3 + x*y + y/(x+1));
        int b = rand()%255;
        if (docolor==0) {
          printf("\033[38;2;%d;%d;%dm\033[5m", r, g, b);
        }
      }else{
        printf("\033[38;2;85;65;0m");
      }
      printf("%c", tab[x][y]);
      printf("\033[0m");
    }
    printf("\n");
  }
}
void monBeauSapin(int n, char t[n][n]) {
  int a=1;
  for (size_t x = 0; x < n; x++) {
    if (x<=maxOfSapin(n)) {
      for (size_t y = 0; y < n; y++) {
        if (y>(n/2)-(a/2) && y<(n/2)+(a/2)) {
          t[x][y]='*';
        } else {
          t[x][y]=' ';
        }
      }
      a+=2;
    }else if(x<=maxOfSapin(n)+2){
      for (size_t y = 0; y < n; y++) {
        if (y>(n/2)-1 && y<(n/2)+1) {
          t[x][y]='@';
        } else {
          t[x][y]=' ';
        }
      }
    }
  }

}

int main() {
  const int n = 10;
  char t[n][n];
  monBeauSapin(n, t);
  printSapin(n, t);
  return 0;
}
