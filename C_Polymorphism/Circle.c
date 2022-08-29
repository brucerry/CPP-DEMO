#include <stdio.h>
#include <stdlib.h>

#include "Circle.h"

void CircleInit(Circle* circle, const double _radius) {
  circle->radius = _radius;
  circle->info = CircleInfo;
  circle->area = CircleGetArea;
  circle->clear = CircleClear;

  printf("Initialized Circle.\n");
}

void CircleInfo(void) {
  printf("This is Circle.\n");
}

double CircleGetArea(const Circle* const circle) {
  return circle->radius * circle->radius * 3.1415926;
}

void CircleClear(Circle* circle) {
  if (circle) {
    free(circle);
    printf("Cleared Circle.\n");
  }
}