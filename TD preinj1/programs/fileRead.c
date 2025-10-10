#include "main.h"
unsigned long getTimeMilliSec(){
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return (1000 * tv.tv_sec) + (tv.tv_usec / 1000);
}

int getData(char *fileName) {
  FILE *data = NULL;
  data = fopen(fileName, "r+");
  if (data == NULL) {
    printf("Error: %s\n", strerror(errno));
    return errno;
  }
  char dataLine[80];
  int endOfFile = 0;
  while (dataLine != "Test" && !endOfFile) {
    if (fgetc(data) == EOF) {
      endOfFile = 1;
    }
    fseek(data, -1, 1);
    fgets(dataLine, 79, data);
  }

  fclose(data);
}

int main(int argc, char const *argv[]) {
  unsigned long start = getTimeMilliSec();

  getData("data.json");

  printf("Time: %dms\n", getTimeMilliSec()-start);
  return 0;
}
