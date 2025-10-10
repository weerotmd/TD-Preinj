#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


int main() {
  int seconds, minutes, hours, counter;
  char c;
  do
  {
    printf("Enter the amount of seconds: ");
    scanf("%d", &seconds);
  }while (seconds < 1);

  minutes=seconds/60;
  hours=minutes/60;
  seconds %= 60;
  //printf("%d:%d:%d\n", hours, minutes, seconds);

  while (hours > 0 || minutes > 0 || seconds > 0) {
    printf("%d:", hours);
    printf("%d:", minutes);
    printf("%d\n", seconds);
    if (seconds > 0) {
      seconds--;
    }else if (minutes > 0) {
      minutes--;
      seconds = 59;
    }else if (hours > 0) {
      hours--;
      minutes = 59;
      seconds = 59;
    }
    sleep(1);
  }
  printf("00:00:00\n");
  printf("BOOM!\n");

  return 0;
}
