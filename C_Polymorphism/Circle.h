typedef struct Circle Circle;

struct Circle {
  double radius;

  void (*info) (void);
  double (*area) (const Circle* const circle);
  void (*clear) (Circle* circle);
};

// constructor
void CircleInit(Circle* const circle, const double _radius);

// destructor
void CircleClear(Circle* const circle);

// operators
void CircleInfo(void);
double CircleGetArea(const Circle* const circle);