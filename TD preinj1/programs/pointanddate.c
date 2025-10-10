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
  //sqrt(pow(4, 2))
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

typedef struct {
  double x;
  double y;
} Point;

Point newPoint(double x, double y){
  Point a;
  a.x = x;
  a.y = y;
  return a;
}
Point addPoints(Point a, Point b){
  return newPoint(a.x + b.x, a.y + b.y);
}
double distance(Point a, Point b){
  return sqrt(pow(b.x-a.x, 2)+pow(b.y-a.y, 2));
}
int isSquare(Point a, Point b, Point c, Point d){
  return (sqrt(pow(distance(a, c) - distance(b, d),2)) <= 0.0001 && a.x == b.x && b.y == c.y && d.x == c.x && d.y == a.y);
}
int areAligned(Point a, Point b, Point c){
  //printf("%lf - %lf && %lf/%lf\n", (b.y-a.y), (b.x-a.x), ((b.y-a.y)/(b.x-a.x)), ((c.y-a.y)/(c.x-a.x)));
  if (b.x == a.x && c.x == a.x) {
    return 1;
  } else if (b.x == a.x || c.x == a.x) {
    return 0;
  }
  return ((b.y-a.y)/(b.x-a.x))-((c.y-a.y)/(c.x-a.x))<=0.0001;
}
void displayPoint(Point point){
  printf("%lf / %lf\n", point.x, point.y);
}

typedef struct {
  int day;
  int month;
  int year;
} Date;
Date newDate(int day, int month, int year){
  Date d;
  d.day = day;
  d.month = month;
  d.year = year;
  return d;
}
Date addDay(Date d, int n){
  if (n > 28) {
    printf("Please don't try to add so much days");
    return d;
  }
  int monthLen[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if (d.day+n>monthLen[d.month+1]) {
    d.day-=monthLen[d.month+1];
    d.month+=1;
    if (d.month>12) {
      d.month = 1;
      d.year +=1;
    }
  }
  return newDate(d.day+n, d.month, d.year);
}
Date subDay(Date d, int n){
  if (n > 28) {
    printf("Please don't try to remove so much days\n");
    return d;
  }
  int monthLen[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if (d.day-n<monthLen[d.month]) {
    d.day+=monthLen[d.month];
    d.month-=1;
    if (d.month<1) {
      d.month = 1;
      d.year -=1;
    }
  }
  return newDate(d.day-n, d.month, d.year);
}
typedef struct {
  int hours;
  int minutes;
  int seconds;
} Time;
Time newTime(float hours, float minutes, float seconds){
  Time t;
  t.hours = hours;
  t.minutes = minutes;
  t.seconds = seconds;
  return t;
}
Time addSecond(Time t, int n) {
  t.seconds += n;
  t.minutes += t.seconds/60;
  t.seconds %= 60;
  t.hours += t.minutes/60;
  t.minutes %= 60;
  printf("Seconds %d\n", t.seconds);
  printf("Minutes %d\n", t.minutes);
  printf("Hours %d\n", t.hours);
}
void displayDate(Date d){
  if (d.day < 10) {
    printf("0%d/", d.day);
  } else {
    printf("%d/", d.day);
  }
  if (d.month < 10) {
    printf("0%d/", d.month);
  } else {
    printf("%d/", d.month);
  }
  printf("%d\n", d.year);
}

int main() {
  displayDate(subDay(newDate(1,5,2077), 29));
  return 0;
}
