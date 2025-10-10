#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int fillArray2D(int row, int col, int tab[row][col]) {
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      tab[i][j] = 0;
    }
  }
}
void printTable2D(int row, int col, int tab[row][col]) {
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      if (tab[i][j] != 0) printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv){
  int n = atoi(argv[1]);
  int triangle[n+1][n+1];
  fillArray2D(n+1, n+1, triangle);
  for (size_t i = 0; i < n+1; i++) {
    for (size_t j = 0; j < n+1; j++) {
      if (j==0) {
        triangle[i][j] = 1;
      } else if (i != 0){
        triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
      }
    }
  }
  printTable2D(n+1, n+1, triangle);
  return 0;
}
