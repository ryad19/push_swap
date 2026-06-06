*This project has been created as part of the 42 curriculum by achafai*.

# libft

## Description
Libft is a project where you code a set of functions in C, some of them are reimplementation of some functions from libc, some of them will be used to manipulate lists and much more.

The project's aim is to understand how these functions work, learn to use them and use them for the next project.

### Library Overview

The library includes implementations of functions from several categories.

#### Character Functions

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

---

#### Memory Functions

- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

---

#### String Functions

- `ft_strlen`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strnstr`
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_strmapi`
- `ft_striteri`

---

#### Conversion Functions

- `ft_atoi`
- `ft_itoa`

---

#### File Descriptor Functions

- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

---

#### Linked List Functions

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstadd_back`
- `ft_lstlast`
- `ft_lstsize`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

---


## Instructions
The folder contains a Makefile file that can be used to build the library:

**To create object files needed to build the lib:**

```bash
make all
```


**To delete .o files use:** 

```bash
make clean
```

**To delete the .o files and the lib:**

```bash
make fclean
```
 

**this one is the same as running make fclean and make all after it:**
 ```bash
 make re
 ``` 
 


## Resources
linux man page

stackoverflow website

gemini (to understand some concepts and the role of some functions if I don't get from the description file, also to understand Makefile.)
