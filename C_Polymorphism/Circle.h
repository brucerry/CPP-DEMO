typedef struct Circle Circle;

struct Circle {
  double radius;

  void (*info) (void);
  double (*area) (const Circle* const circle);
  void (*clear) (Circle* circle);
};

void CircleInit(Circle* circle, const double _radius);
void CircleInfo(void);
double CircleGetArea(const Circle* const circle);
void CircleClear(Circle* circle);