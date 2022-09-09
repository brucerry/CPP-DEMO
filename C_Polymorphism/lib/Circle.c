#include <stdio.h>
#include <stdlib.h>

#include "Circle.h"

void CircleInit(Circle* const circle, const double _radius) {
  circle->radius = _radius;
  circle->info = CircleInfo;
  circle->area = CircleGetArea;
  circle->clear = CircleClear;

  printf("Initialized Circle.\n");
}

void CircleClear(Circle* const circle) {
  if (circle) {
    free(circle);
    printf("Cleared Circle.\n");
  }
}

void CircleInfo(const Circle* const circle) {
  printf("This is Circle, radius is %lf.\n", circle->radius);
}

double CircleGetArea(const Circle* const circle) {
  return circle->radius * circle->radius * 3.1415926;
}