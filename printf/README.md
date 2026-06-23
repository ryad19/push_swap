*This project has been created as part of the 42 curriculum by achafai.*

# Description

`ft_printf` is a recoding of the standard C `printf` function. The goal of this project is to learn how to handle a variable number of arguments in C using variadic functions.

I wrote several helper functions to handle the different conversion specifiers (`cspdiuxX%`). I have separated them into different files for better organization:

* **`ft_putnbr`**: Handles numbers. It is responsible for the `%i`, `%d`, `%u`, `%x`, and `%X` conversions.
* **`ft_putchar`**: Prints a single character and `%`. It also serves as the base writing function for the other helpers.
* **`ft_putstr`**: Handles strings (`%s`).
* **`ft_putptr`**: Handles memory addresses and pointers (`%p`).

# Instructions

There are no special requirements to run this project. 

The repository contains a `Makefile` with standard rules to compile the library:

* **To compile the library (`libftprintf.a`):**
    ```bash
    make all
    ```
* **To delete object (`.o`) files:**
    ```bash
    make clean
    ```
* **To delete object files and the compiled library:**
    ```bash
    make fclean
    ```
* **To completely recompile the project (runs `fclean` then `all`):**
    ```bash
    make re
    ```

# Resources

* **Gemini:** Used to break down specific concepts and structure this README file.
* **DevDocs:** [C Variadic Functions Documentation](https://devdocs.io/c-variadic-functions/)
* **YouTube:** [Understanding Variadic Functions](https://www.youtube.com/watch?v=oDC208zvsdg)