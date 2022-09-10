#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct Circle Circle;

struct Circle {
  double radius;

  void (*info) (const Circle* const circle);
  double (*area) (const Circle* const circle);
  void (*clear) (Circle* circle);
};

// constructor
void CircleInit(Circle* const circle, const double _radius);

// destructor
void CircleClear(Circle* const circle);

// operators
void CircleInfo(const Circle* const circle);
double CircleGetArea(const Circle* const circle);

#endif