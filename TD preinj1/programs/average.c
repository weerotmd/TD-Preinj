#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
   double input = -1;
   int index = 0;
   char c;
   int size;
   printf("Enter the amount of numbers: ");
   scanf(" %d", &size);
   //double grades[3] = {-1, -1, -1};
   double* grades = malloc(size * sizeof(double));
   for (size_t i = 0; i < size; i++) {
     grades[i] = -1;
   }
   int length = sizeof(grades) / sizeof(grades[0]);
   while (index <= size-1) {
    printf("Enter a number: ");
    char c;
    int scanAnswer = scanf(" %lf%c", &input, &c);
    int test = scanAnswer != 2 || c != '\n';
    if(test || index >= size-1) {
      if (!test) {
        grades[index] = input;
      }
      /*printf("Values: \n");
      for (size_t i = 0; i < size; i++) {
        printf("Index %d: %lf\n", i, grades[i]);
      }*/
      int lowest = 0;
      int greatest = 0;
      for (size_t i = 0; i < size; i++) {
        if (grades[i] >= 0) {
          if (grades[i] < grades[lowest]) {
            lowest = i;
          }
        }
        if (grades[i] >= 0) {
          if (grades[i] > grades[greatest]) {
            greatest = i;
          }
        }
      }
      if (lowest == greatest) {
        lowest = -1;
        greatest = -1;
      }
      double avg = 0;
      int nullValues = 0;
      //printf("Size: %d\n", size-1);
      for (size_t i = 0; i <= size; i++) {
        //printf("Index %d:// ", i);
        if (i != lowest && grades[i] >= 0) {
          //printf("avg: %lf, grade: %lf\n", avg, grades[i]);
          avg += grades[i];
        }
        else if (grades[i] < 0) {
          //printf("Size-1 on index: %d\n", i);
          nullValues += 1;
        }
      }
      /*printf("avg: %lf\n", avg);
      printf("Lowest: %d\n", lowest);
      printf("Greatest: %d\n", greatest);
      printf("Null values: %d\n", nullValues);
      printf("Size: %d\n", size);*/
      if (size > 1) avg /= (size - nullValues - (lowest != -1));

      printf("Average: %lf\n", avg);

      printf("-----------------------");

      if (index < 2) return 0;
    }
    else {
      grades[index] = input;
    }
    index += 1;
  }

   return 0;
}
