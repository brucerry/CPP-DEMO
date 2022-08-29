typedef struct Shape Shape;

struct Shape {
  char dummy[8];

  void (*info) (const Shape* const shape);
  double (*area) (const Shape* const shape);
  void (*clear) (const Shape* const shape);
};