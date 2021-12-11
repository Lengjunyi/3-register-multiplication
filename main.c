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

#define PRINT printf("[%i, %i, %i]\n", R0, R1, R2)

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
  int R0 = 0, R1 = 6, R2 = 7;

  /* Step 1: Remove factors of 2 from R1 
    Example: (6, 7) -> (3, 14) */

  // Divide R1 by 2
  L1: SUB(R1, L2, L3)
  L2: ADD(R0, L1)
  L3: SUB(R0, L4, L6)  // R1 = 2n
  L4: SUB(R0, L5, L11) // R1 = 2n + 1
  L5: ADD(R1, L3)
  // Multiply R2 by 2
  L6: SUB(R2, L7, L8)
  L7: ADD(R0, L6)
  L8: SUB(R0, L9, L1)
  L9: ADD(R2, L10)
  L10: ADD(R2, L8)
  // Restore R1 into 2n + 1
  // Side note: Loop tiling can perhaps be applied here with the next part
  L11: SUB(R1, L12, L14)
  L12: ADD(R0, L13)
  L13: ADD(R0, L11)
  L14: ADD(R0, L15)
  /* Now R0 * R2 = m0 * n0, and R0 is odd.
  This is useful, and we use them as our new m and n. */


  /* Step 2: "Push" R2 onto R0, Transform it
  into the form m * 2 ^ n
    Example: (3, 14) -> (3 * 2 ^ 14, 0) */

  L15: SUB(R2, L16, L21)
  L16: SUB(R0, L17, L18)
  L17: ADD(R1, L16)
  L18: SUB(R1, L19, L15)
  L19: ADD(R0, L20)
  L20: ADD(R0, L18)

  L21: HALT
}