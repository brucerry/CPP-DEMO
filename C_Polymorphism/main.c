#include <stdio.h>
#include <stdlib.h>

#include "Shape.h"
#include "Circle.h"

int main() {
  Circle* circle = (Circle*) malloc(sizeof(Circle));
  CircleInit(circle, 3.349);
  
  Shape* shape = (Shape*)circle;
  shape->info();
  printf("Area is %lf\n", shape->area(shape));
  shape->clear(shape);
  printf("OK\n");
}