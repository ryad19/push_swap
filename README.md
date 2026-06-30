*This project has been created as part of 42 curriculum by achafai, sarrbene.*

# push_swap - C function to sort integers.

## Table of Contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)

## Description

push_swap is a program that sorts integers using a set of constrained operations implemented in C.
The program takes numeric arguments and outputs the sequence of operations needed to sort them.

### Goal

The project aims to:

. Sort a stack of integers using only a limited set of operations on two stacks.
. Find an efficient sorting algorithm that minimizes the number of operations.
. Strengthen problem-solving skills, algorithm design, and data structure implementation in C.
. Improve proficiency in low-level programming, memory management, and clean, maintainable code.

### Project Structure
~~~
	├── Makefile
   .├── push_swap.h
    ├── main.c
    ├── sort_simple.c
	├── sort_medium.c
	├── sort_complex.c
	├── op_push.c
	├── op_swap.c
	├── op_rotate.c
	├── op_rev_rotate.c
	├── utils_memory.c
	├── utils_math.c
	├── stack_utils.c
	├── parsing.c
	├── libft
	├── printf
	├── README.md






## Instruction set

If an instruction cannot be executed, the non-applicable part is ignored.

|Code |                 |Instruction	      |                   Action
|     |                 |                     |
|`sa` |                 | swap a	          |       Swaps the top two elements of stack 
|     |                 |                     |
|`sb` |	                | swap b	          |       Swaps the top two elements of stack b
|     |                 |                     |
|`ss` |	                | swap a + swap b	  |       Performs both sa and sb
|     |                 |                     |
|`pa` |                 | push a	          |       Moves the top element of stack b to the top of stack a
|     |                 |                     |
|`pb` |	                | push b	          |       Moves the top element of stack a to the top of stack b
|     |                 |                     |
|`ra` |                 | rotate a	          |       Shifts all elements of stack a up by one (first become|s last)
|     |                 |                     |
|`rb` |                 | rotate b	          |       Shifts all elements of stack b up by one (first becomes last)
|     |                 |                     |
|`rr` |	                | rotate a + rotate b |	      Performs both ra and rb
|     |                 |                     |
|`rra`|	                | reverse rotate a	  |       Shifts all elements of stack a down by one (last becomes first)
|     |                 |                     |
|`rrb`|	                | reverse rotate b	  |       Shifts all elements of stack b down by one (last becomes first)
|     |                 |                     |
|`rrr`|	                | reverse rotate a + b|	      Performs both rra and rrb 




## Resources


### Algorithm & push_swap specific:

- overview of classic sorting algorithms                   (https://www.geeksforgeeks.org/sorting-algorithms/)

- Max Chunks To Make Sorted                                (https://www.youtube.com/watch?v=nXnamovQlG8)



### Data Structures & Algorithms:

- algorithm visualization (very helpful for stacks)        (https://visualgo.net/en)

- Data structures and algorithms insertion sort          (https://www.youtube.com/watch?v=8mJ-OhcfpYg)


### C / Low-level programming

-“Beej’s Guide to C” (very practical)                    (https://beej.us/guide/bgc/)
- interactive C learning platform                        (https://www.learn-c.org/)

