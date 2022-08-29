typedef struct Shape Shape;

struct Shape {
  char dummy[8];

  void (*info) (void);
  double (*area) (const Shape* const shape);
  void (*clear) (Shape* shape);
};