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
  int R0 = 0, R1 = 4, R2 = 3;

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


  /* Step 3: "Pop" R0 back into R2, retain
  it in the form of 2 ^ n
    Example: (3 * 2 ^ 14) -> (3, 2 ^ 14) */

  L21: ADD(R2, L22) // Multiplicative identity

  // Dividing from R0
  L22: SUB(R0, L23, L24)
  L23: ADD(R1, L22)
  L24: SUB(R1, L25, L27)
  L25: SUB(R1, L26, L32)
  L26: ADD(R0, L24)

  // Multiplying into R1
  L27: SUB(R2, L28, L29)
  L28: ADD(R1, L27)
  L29: SUB(R1, L30, L22)
  L30: ADD(R2, L31)
  L31: ADD(R2, L29)

  // Restoring R0
  L32: SUB(R0, L33, L35)
  L33: ADD(R1, L32)
  L35: SUB(R1, L36, L38)
  L36: ADD(R0, L37)
  L37: ADD(R0, L35)
  L38: ADD(R0, L39) // The "1" from "2n+1"

  /* Could reduce L38 by reordering the next part (i think),
  but it's put here for better understanding. */


  /* Step 4: "Push" R0 into R2, as power of 3.
    Example: (3, 2 ^ 14) -> (0, 2 ^ 14 * 3 ^ 3) */
  L39: SUB(R0, L40, L46)
  L40: SUB(R2, L41, L42)
  L41: ADD(R1, L40)
  L42: SUB(R1, L43, L39)
  L43: ADD(R2, L44)
  L44: ADD(R2, L45)
  L45: ADD(R2, L42)

  /* After this step, the transforming task is done and we
  can now use R1 and R2 to simulate three registers. */


  /* Step 5: The real work.

  The original register machine program to perform this job is:

    L0: SUB(R1, L1, L6)
    L1: SUB(R2, L2, L4)
    L2: ADD(R0, L3)
    L3: ADD(R3, L1)
    L4: SUB(R3, L5, L0)
    L5: ADD(R2, L4)
    L6: HALT

    We have used powers of 2 and powers of 3 to represent R1 and R2,
    thus we now use powers of 5 to represent R3.

    Now, the adding operations are simulated with multiplication,
    and the subtracting operations are simulated with division.

    From now on, It's better to test with smaller numbers like 4 * 3
  
  */

  // L0
  L46: SUB(R2, L47, L49) // Success, then just move back to R2
  L47: SUB(R2, L48, L53) // Otherwise, failure and need to restore
  L48: ADD(R1, L46)

  L49: SUB(R1, L50, END)
  L50: ADD(R2, L49)

  L51: SUB(R1, L52, END)
  L52: ADD(R2, L53)
  L53: ADD(R2, L51)

  // L1
  L54: SUB(R2, L55, L58)
  L55: SUB(R2, L56, L63)
  L56: SUB(R2, L57, L62)
  L57: ADD(R1, L54)

  L58: SUB(R1, L58, END)
  L59: ADD(R2, L57)

  L60: SUB(R1, L61, END)
  L61: ADD(R2, L62)
  L62: ADD(R2, L63)
  L63: ADD(R2, L60)

  // L2
  L64: ADD(R0, END) // R0 not protected, no need of stack logic

  // L3
  L65: SUB(R2, L66, L67)
  L66: ADD(R2, L65)
  L67: SUB(R1, L68, END)
  L68: ADD(R2, L69)
  L69: ADD(R2, L70)
  L70: ADD(R2, L71)
  L71: ADD(R2, L72)
  L72: ADD(R2, L67)
  


  END: HALT
}