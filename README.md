# 3-register-multiplication
An implementation of multiplication in register machine using three registers.

The kind of register machine here contains 3 kinds of instructions, namely incrementation, decrementation, and halt.

- Incrementation increments a register and jumps to another instruction.

- Decrementation decrements a register and jumps to one instruction on success, or, on failure, jumps to another instruction.

- Halt simply stops the program and maintains the state of the machine.

Traditionally, it takes four registers to complete the computation. Two of them represent multiplicators, one to store the result, and another one for scratching.

The original program is as follows:

    L0: SUB(R1, L1, L6)
    L1: SUB(R2, L2, L4)
    L2: ADD(R0, L3)
    L3: ADD(R3, L1)
    L4: SUB(R3, L5, L0)
    L5: ADD(R2, L4)
    L6: HALT

However, it is possible to simulate 3 registers using only 2, i.e. there exists bijections between 3-tuple and natural numbers, like `f(x,y,z) = 2^x * 3^y * 5^z`.

The current program isn't able to compute edge case of 0 * n. This can be addressed by adding check at the beginning.

As reference, the program takes 33162178 steps to calculate 6 * 7, and 2122456726 steps to calculate 12 * 5. But it's worth it for the fact it saves 25% of the registers.
