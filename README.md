# 42Berlin_push-swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
![image](https://github.com/user-attachments/assets/062be69c-fed2-49fe-8bb0-aaeafae262b5)

push_swap is a 42 school algorithmic project where the objective is to sort a stack of integers using only a limited set of operations and the fewest number of moves possible.

📦 Project Overview

Given a stack A of integers (unsorted), the program must sort it in ascending order using an auxiliary stack B and only the following operations:

sa, sb, ss: swap top two elements

pa, pb: push from one stack to the other

ra, rb, rr: rotate (top to bottom)

rra, rrb, rrr: reverse rotate (bottom to top)

The goal is to minimize the number of operations.

🧠 Algorithm Used

This implementation is based on the Radix sort strategy. Radix sort is a non-comparative sorting algorithm that sorts numbers by processing individual bits.

It starts with the least significant bit (LSB) and moves toward the most significant bit (MSB).

For each bit position, it separates numbers into two groups: those with a 0 bit and those with a 1 bit at that position.

In push_swap, you use two stacks: a (source) and b (auxiliary).

While checking each bit, you pb (push to b) if the bit is 0, and ra (rotate a) if the bit is 1.

After one full pass, you pa (push back to a) all elements from b.

This process is repeated for each bit (number of passes depends on the maximum bit length of the numbers).

The key idea is: sorting by bits ensures the order is preserved from lower bits to higher bits.

This method works well with normalized indexes (e.g., mapping values 0 to n-1).

It guarantees sorting in O(n * log n) steps using only allowed operations.

🧩 File Structure

.
.
├── Makefile                  # Compiles the project; includes rules: all, clean, fclean, re
├── push_swap_test.sh         # Optional testing script (unofficial)
├── pro_checker               # Optional performance checker
├── checker_Mac               # 42-provided checker binary for macOS
├── checker_linux             # 42-provided checker binary for Linux
├── includes/
│   ├── libft/                # Your full libft implementation
│   └── push_swap.h           # Central header with struct definitions and all function prototypes
├── sources/
│   ├── main.c                # Entry point: handles program start and flow control
│   ├── memory.c              # Handles memory cleanup (e.g. cleanup_and_exit, free_split)
│   ├── ops.c                 # Core push_swap operations: push, swap, rotate, reverse_rotate
│   ├── sorts.c               # Contains sorting logic: sort_3, sort_4_5, radix_sort
│   └── utils.c               # Utility functions: string-to-int conversion, token counting, etc.


🛠 Compilation

make

✅ Usage Example

./push_swap 3 2 5 1 4

Output:

pb
pb
sa
pa
pa
ra
ra

🧪 Debugging Tools

Use print_el_data() to inspect move cost for elements.

Add -DDEBUG flag in compilation to activate debug prints.

📈 Tips for Optimization

Avoid pushing elements to B randomly.

Always analyze move cost from both A and B simultaneously.

Exploit combined operations (rr, rrr) when directions match.

👨‍💻 Author

rwrobles@student.42.fr
