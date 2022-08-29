typedef struct Square Square;

struct Square {
  int length;

  void (*info) (void);
  double (*area) (const Square* const square);
  void (*clear) (Square* square);
};

// constructor
void SquareInit(Square* const square, const int _length);

// destructor
void SquareClear(Square* const square);

// operators
void SquareInfo(void);
double SquareGetArea(const Square* const square);