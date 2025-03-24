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

This implementation is based on the Modified Greedy Algorithm, also known as the Turk strategy:

Phase 1: A → B

Calculate the cheapest element in A to move to B using n_moves().

Use rotation combinations (ra, rb, rr, etc.) to minimize the total moves.

Push the selected element from A to B.

Phase 2: B → A

Reinsert each element from B into the correct position in A using stack_back_to_a().

Final adjustment: rotate A until the smallest value is at the top with deliver_on_top_a().

🧩 File Structure

.
├── push_swap.h           # Project header with structs and function prototypes
├── main.c                # Entry point
├── algo.c                # Main algorithm logic (recursive sorting)
├── stacking_a.c          # Moves from B to A
├── stacking_b.c          # Moves from A to B and cost calculations
├── stacks_utils.c        # Utilities (a_min/max, b_min/max, print)
├── operations.c          # All push/swap/rotate implementations
├── parser.c              # Argument handling and input validation
└── libft/                # Standard library (as required by 42)

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
