#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int askUserInput(){
  int a;
  printf("Enter a value:");
  int answer = scanf("%d", &a);
  if (answer<=0) {
    printf("-------------------%d-------------------\n", answer);
    return 0;
  }
  return a;
}

int throwDice(unsigned int seed) {
  srand(seed);
  return rand()%6 + 1;
}

int playerTurn() {
  int throws = 0;
  do {
    printf("Voulez-vous lancer 1 ou 2 dés?\n");
    scanf("%d", &throws);
  } while(throws != 1 && throws != 2);
  if (throws == 2) {
    int d1 = throwDice(time(NULL));
    int d2 = throwDice(time(NULL)+d1);
    printf("Random dice numbers: %d // %d\n", d1, d2);
    if (d1 == d2) {
      return -(d1 + d2);
    }
    return d1 + d2;
  } else if (throws == 1) {
    return throwDice(time(NULL));
  }
  return 0;
}

int main() {
  int p1 = 0;
  int p2 = 0;
  int turn = 0;
  do {
    printf("-------------Start of the turn of P%d-------------\n", turn%2+1);
    if (turn%2 == 0) {
      p1 += playerTurn();
    } else {
      p2 += playerTurn();
    }
    printf("P1: %d // P2: %d\n", p1, p2);
    printf("-------------End of turn of P%d-------------\n", turn%2+1);
    turn++;
  } while(p1 < 30 && p2 < 30);
  return 0;
}
