typedef struct Square Square;

struct Square {
  int length;

  void (*info) (const Square* const square);
  double (*area) (const Square* const square);
  void (*clear) (Square* square);
};

// constructor
void SquareInit(Square* const square, const int _length);

// destructor
void SquareClear(Square* const square);

// operators
void SquareInfo(const Square* const square);
double SquareGetArea(const Square* const square);