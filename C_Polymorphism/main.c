#include <stdio.h>
#include <stdlib.h>

#include "Shape.h"
#include "Circle.h"
#include "Square.h"

int main() {
  Circle* circle = (Circle*) malloc(sizeof(Circle));
  CircleInit(circle, 3.349);

  Square* square = (Square*) malloc(sizeof(Square));
  SquareInit(square, 6);

  Shape* shape[2];
  shape[0] = (Shape*)circle;
  shape[1] = (Shape*)square;

  for (int i = 0; i < sizeof(shape) / sizeof(&shape); i++) {
    Shape* node = shape[i];
    node->info();
    printf("Area is %lf\n", node->area(node));
    node->clear(node);
    printf("OK\n");
  }

  return 0;
}