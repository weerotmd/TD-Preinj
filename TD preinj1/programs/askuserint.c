#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

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

int askUserInt(int min, int max){
  int answer = 0;
  do {
    printf("Enter a value between %d and %d\n", min, max);
    scanf("%d", &answer);
  } while(answer<min||answer>max);
  return answer;
}

int main() {
  int min, max = 0;
  do {
    min = askUserInput();
  } while (min <= 0);
  do {
    printf("Enter a max greater than min (%d)\n", min);
    max = askUserInput();
  } while(max<=min);
  printf("%d is between %d and %d\n", askUserInt(min, max), min, max);
  return 0;
}
