#include <stdio.h>
#include <stdlib.h>

#include "Square.h"

void SquareInit(Square* const square, const int _length) {
  square->length = _length;
  square->info = SquareInfo;
  square->area = SquareGetArea;
  square->clear = SquareClear;

  printf("Initialized Square.\n");
}

void SquareClear(Square* const square) {
  if (square) {
    free(square);
    printf("Cleared Square.\n");
  }
}

void SquareInfo(const Square* const square) {
  printf("This is Square, length is %d.\n", square->length);
}

double SquareGetArea(const Square* const square) {
  return square->length * square->length;
}