# 42Berlin_push-swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
![image](https://github.com/user-attachments/assets/062be69c-fed2-49fe-8bb0-aaeafae262b5)

push_swap is a 42 school algorithmic project where the objective is to sort a stack of integers using only a limited set of operations and the fewest number of moves possible.

## ✅ Project Status

![Status](https://img.shields.io/badge/status-working-brightgreen?style=flat-square)
![Norminette](https://img.shields.io/badge/norminette-passed-blue?style=flat-square)

## 📦 Project Overview

Given a stack A of integers (unsorted), the program must sort it in ascending order using an auxiliary stack B and only the following operations:

sa, sb, ss: swap top two elements

pa, pb: push from one stack to the other

ra, rb, rr: rotate (top to bottom)

rra, rrb, rrr: reverse rotate (bottom to top)

The goal is to minimize the number of operations.

## 🧠 Algorithm Used

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


## ⚙️ How to Use

### 🔧 Compilation

```bash
make
```

### ▶️ Run

```bash
./push_swap [list of integers]
```

Example:

```bash
./push_swap 3 2 1
```

### ✅ Validate with checker

```bash
./push_swap 3 2 1 | ./checker_Mac 3 2 1
```

> If the result is sorted and valid, you'll get: `OK`

---

## 🧪 Testing

You can test with the provided script:

```bash
chmod +x push_swap_test.sh
./push_swap_test.sh
```

Or manually with:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

Count number of operations:

```bash
./push_swap $ARG | wc -l
```

---

## 🧩 File Structure

```txt
.
├── Makefile                  # Compiles the project; rules: all, clean, fclean, re
├── push_swap_test.sh         # Optional test runner script
├── pro_checker               # Optional performance checker
├── checker_Mac               # Official checker for macOS
├── checker_linux             # Official checker for Linux
├── includes/
│   ├── libft/                # Your full libft implementation
│   └── push_swap.h           # Header with struct + all function prototypes
├── sources/
│   ├── main.c                # Entry point of the program
│   ├── memory.c              # Memory cleanup: cleanup_and_exit, free_split
│   ├── ops.c                 # Stack operations: op_push, op_swap, etc.
│   ├── sorts.c               # Sorting logic: sort_3, sort_4_5, radix_sort
│   └── utils.c               # Helpers: ps_atol, count_tokens, is_valid_number
```

---

## 💡 Algorithms Implemented

- `sort_3`: hardcoded sorting logic for exactly 3 numbers
- `sort_4_5`: optimized sorting using push + reinsertion
- `radix_sort`: non-comparative sorting algorithm for larger sets

---

## 🔒 Error Handling

- Invalid characters
- Integer overflow or underflow
- Duplicate values
- Multiple or misplaced `+` / `-` signs

Output:

```
Error
```

(Printed to standard error)

---

## 📚 Allowed Functions

- `read`, `write`, `malloc`, `free`, `exit`
- Your own `libft` functions

---
## 🔍 File Descriptions

- **`Makefile`**  
  Builds the project with rules: `all`, `clean`, `fclean`, `re`, and avoids relinking.

- **`includes/push_swap.h`**  
  Main header file containing:
  - `t_stack` struct definition
  - Prototypes for all functions used across the project

- **`sources/main.c`**  
  Initializes the program, parses arguments, prepares stacks, and calls sorting logic.

- **`sources/ops.c`**  
  Contains all allowed operations: `sa`, `pb`, `ra`, `rrb`, etc.

- **`sources/sorts.c`**  
  Includes high-level sort logic such as:
  - `sort_3`, `sort_4_5` for small input
  - `radix_sort` for large input

- **`sources/memory.c`**  
  Memory utilities such as:
  - `cleanup_and_exit`
  - `free_split`

- **`sources/utils.c`**  
  Utility functions:
  - `ps_atol`, `is_valid_number`, `count_split_tokens`, etc.

- **`libft/`**  
  Your custom standard library. Must follow 42's Libft rules.

---

🧪 Debugging Tools

Use print_el_data() to inspect move cost for elements.

Add -DDEBUG flag in compilation to activate debug prints.

📈 Tips for Optimization

Avoid pushing elements to B randomly.

Always analyze move cost from both A and B simultaneously.

Exploit combined operations (rr, rrr) when directions match.


## 🧠 Author

👩‍💻 Ren W.  
Project for [42 School](https://42.fr)

