*This project has been created as part of 42 curriculum by achafai, sarrbene.*

# PUSH SWAP

## Table of Contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)

## Description

push_swap is a program that sorts integers using a set of operations and 2 stacks implemented in C.

The program takes numeric arguments and outputs the sequence of operations needed to sort them.

The program has 4 modes, ADAPTIVE, SIMPLE, MEDIUM and COMPLEX. 
They refer to the algorithms used to sort the numbers, selection sort, chunck-based sort and radix sort.
The ADAPTIVE mode calculates the disorder and dicides with algorithm to use.

 In case there are less than 6 input there's a specific sorting way used to meet a special requirement in the evaluation.

### Goal

The project's aim is to:

Write a C program called push_swap which calculates and displays on the
standard output the smallest program, made of Push swap language operations, that sorts the integers received as arguments.

language operations:
~~~
|Code |             |Instruction	      |                   Action
|     |             |                     |
|`sa` |             | swap a	          |     Swaps the top two elements of stack 
|     |             |                     |
|`sb` |	            | swap b	          |     Swaps the top two elements of stack b
|     |             |                     |
|`ss` |	            | swap a + swap b	  |     Performs both sa and sb
|     |             |                     |
|`pa` |             | push a	          |     Moves the top element of stack b to the top of stack a
|     |             |                     |
|`pb` |	            | push b	          |     Moves the top element of stack a to the top of stack b
|     |             |                     |
|`ra` |             | rotate a	          |     Shifts all elements of stack a up by one (first becomes last)
|     |             |                     |
|`rb` |             | rotate b	          |     Shifts all elements of stack b up by one (first becomes last)
|     |             |                     |
|`rr` |	            | rotate a + rotate b |	    Performs both ra and rb
|     |             |                     |
|`rra`|	            | reverse rotate a    |     Shifts all elements of stack a down by one (last becomes first)
|     |             |                     |
|`rrb`|	            | reverse rotate b    |     Shifts all elements of stack b down by one (last becomes first)
|     |             |                     |
|`rrr`|	            | reverse rotate a + b|	    Performs both rra and rrb 
~~~






## Instruction set

Download the repo and go to folder,
first run make
~~~
~ make
~~~
you can clean after that by runing, or just run the programm
~~~
make clean
~~~
to run the program you
~~~
./push_swap ...
~~~ 
the numbers can be passed as one string separated by space or as a list of numbers.
You can specify the mode to be used by passing ADAPTIVE, SIMPLE, MEDIUM, COMPLEX as flags.

ex:
~~~
./push_swap --simple
~~~
You can see some statistics by using bench flag.
~~~
./push_swap --bench
~~~
NOTE:


### Project Structure
~~~
	├── Makefile
    ├── push_swap.h
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
~~~

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

