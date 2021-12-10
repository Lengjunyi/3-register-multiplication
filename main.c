/* Skeleton from Charlie. */

#include <stdio.h>

// curly brace macros used
// so DO NOT USE BRACELESS IF STATEMENTS

#define SHOW_STATES

#define GOTO(l) { printf(#l": "); goto l; }

#define ADD_(p, a) {                                                                            \
  p++;                                                                       \
  GOTO(a);                                                                    \
}
#define SUB_(p, a, b) {                                                         \
  if (p != 0) {                                                                \
    p--;                                                                       \
    GOTO(a);                                                                    \
  } else {                                                                     \
    GOTO(b);                                                                    \
  }                       \
}

#define PRINT printf("[%i, %i]\n", R0, R1)

#define ADD(p, a) {                                                                            \
  PRINT;                                                                     \
  ADD_(p, a);                                                                \
}

#define SUB(p, a, b) {                                                                            \
  PRINT;                                                                     \
  SUB_(p, a, b);                                                             \
}

#define HALT { PRINT; return 0; }

int main() {
  int R0 = 0, R1 = 2, R2 = 0, R3 = 0;

  // Sanity check
  L1: SUB(R1, L2, L3)
  L2: ADD(R0, L1)
  L3: HALT
}