> *This project was created as part of the **42 curriculum** by **achafai** and **sarrbene**.*

---

# push_swap

A C program that sorts integers using two stacks and a restricted set of operations, outputting the shortest possible sequence of moves.

---

## Table of Contents

- [Description](#description)
- [Project Structure](#project-structure)
- [Operations](#operations)
- [Usage](#usage)
- [Benchmark Mode](#benchmark-mode)
- [Resources](#resources)

---

## Description

**push_swap** takes a list of integers as input and prints the sequence of stack operations required to sort them in ascending order, minimizing the total number of moves.

For inputs of **five or fewer integers**, the program uses specialized hardcoded routines to meet the strict operation limits imposed by the project evaluation.

### Sorting Modes

The program implements four sorting modes:

| Mode | Algorithm | Triggered when |
|------|-----------|----------------|
| `SIMPLE` | Selection Sort | `--simple` flag, or ≤ 5 elements |
| `MEDIUM` | Chunk-based (Butterfly) Sort | `--medium` flag |
| `COMPLEX` | Bitwise Radix Sort | `--complex` flag |
| `ADAPTIVE` *(default)* | Auto-selects based on disorder level | no flag provided |

In `ADAPTIVE` mode, the disorder level of the input (proportion of out-of-order pairs) determines which algorithm runs:

- **< 20% disorder** → SIMPLE
- **20–50% disorder** → MEDIUM
- **≥ 50% disorder** → COMPLEX

---

## Project Structure

```
.
├── libft/             # Custom C standard library
├── printf/            # ft_printf implementation
├── srcs/              # Source files (parsing, algorithms, operations, utils)
│   ├── main.c
│   ├── parsing.c
│   ├── stack_utils.c
│   ├── utils_math.c
│   ├── utils_memory.c
│   ├── algorithm_simple.c
│   ├── sort_medium.c
│   ├── sort_complex.c
│   └── op_*.c
├── push_swap.h        # Header — structs, enums, prototypes
└── Makefile
```

---

## Operations

| Operation | Action |
|-----------|--------|
| `sa` | Swap the top two elements of Stack A |
| `sb` | Swap the top two elements of Stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element of Stack B onto Stack A |
| `pb` | Push the top element of Stack A onto Stack B |
| `ra` | Rotate Stack A up — first element becomes last |
| `rb` | Rotate Stack B up — first element becomes last |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate Stack A — last element becomes first |
| `rrb` | Reverse rotate Stack B — last element becomes first |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Usage

### Build

```bash
make
```

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # rebuild from scratch
```

### Run

Pass integers as separate arguments or as a single quoted string:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

An optional strategy flag can be passed before the numbers:

```bash
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
```

### Verify Output

Pipe the output into the 42 checker to confirm the sort is valid:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

A correct sort prints:

```
OK
```

---

## Benchmark Mode

Add `--bench` to print sorting diagnostics to stderr after the run:

```bash
./push_swap --bench 5 1 4 2 3
```

Sample output:

```
[bench] disorder: 80.00%
[bench] Strategy: ADAPTIVE / O(n log n)
[bench] total_ops: 12
[bench] sa: 0, sb: 0, ss: 0, pa: 5, pb: 5
[bench] ra: 1, rb: 1, rr: 0, rra: 0, rrb: 0, rrr: 0
```

`--bench` can be combined with a strategy flag:

```bash
./push_swap --bench --complex 4 67 3 87 23
```

---

## Resources

### AI Assistance

Generative AI was used as a learning companion throughout this project to:

- Understand chunk-based and bitwise radix sorting algorithms
- Explore C concepts such as enumerations and bitwise operators
- Design the project architecture and data structures
- Develop automated Bash scripts for testing and benchmarking

### References

**Algorithms**
- Overview of classic sorting algorithms
- *Max Chunks To Make Sorted* (YouTube)

**Data Structures & C**
- Algorithm visualization tools
- *Data Structures and Algorithms: Insertion Sort* (YouTube)
- Beej's Guide to C
- Interactive C learning platforms