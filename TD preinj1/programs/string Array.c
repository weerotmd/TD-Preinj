#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

void printNames(char **names, int n) {
  printf("Name list:\n");
  for (size_t i = 0; i < n; i++) {
    printf("-%s\n", *(names+i));
  }
}

int main() {
  char **names = NULL;
  int n = 0;
  printf("How many names?\n");
  scanf("%d", &n);
  names=malloc(n*sizeof(char*));
  for (size_t i = 0; i < n; i++) {
    char *name;
    int nameLen;
    printf("How long is name %d?\n", i);
    scanf("%d", &nameLen);

    name=malloc((nameLen+1)*sizeof(char));
    if(name==NULL){
      printf("Error");
      exit(1);
    }

    printf("Enter name %d: ", i);
    scanf("%s", name);
    if (*(name) >= 'a' && *(name) <= 'z') {
      *(name) -= 32;
    }
    if(names==NULL){
      printf("Error");
      exit(1);
    }
    *(names+i) = name;
  }
  printNames(names, n);
  free(names);
  return 0;
}
