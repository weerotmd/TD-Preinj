#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

typedef struct {
  double x;
  double y;
} Vector2;

Vector2 newVector2(double x, double y){
  Vector2 a;
  a.x = x;
  a.y = y;
  return a;
}
Vector2 toPolar(Vector2 *v){
  Vector2 w = *v;
  double x = w.x;
  w.x = sqrt(pow(x,2)+pow(w.y,2));
  w.y = (x == 0 ? -1 : atan2(w.y,x));
  *v = w;
  return *v;
}
Vector2 toCartesian(Vector2 *v){
  Vector2 w = *v;
  double r = w.x;
  w.x = r*cos(w.y);
  w.y = r*sin(w.y);
  *v = w;
  return *v;
}

int main() {
  Vector2 v = newVector2(5, 5);
  toPolar(&v);
  printf("%f %f\n", v.x, v.y);
  toCartesian(&v);
  printf("%f %f\n", v.x, v.y);
  return 0;
}
