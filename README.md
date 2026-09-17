*This project has been created as part of the 42 curriculum by sakonukl.*

# Libft

## Description

Libft is the first project of the 42 Common Core: a personal C library that
reimplements a large subset of the standard C library's string, memory, and
number-handling functions under an `ft_` prefix, and extends it with
additional utility functions (substring extraction, string joining and
trimming, splitting, integer-to-string conversion, and per-character
mapping/iteration) plus a singly linked list module (`t_list`) with its own
set of creation, traversal, transformation, and cleanup functions.

The goal isn't to produce a drop-in replacement for `libc` — it's to build,
from scratch, a working understanding of how these primitives actually
behave: their edge cases, their memory-ownership rules, and the failure
modes (NULL input, integer overflow, allocation failure) that the real
functions either guard against or explicitly leave undefined. Every function
in this library is built to never crash unexpectedly and to leak no memory,
per the project's Common Core requirements.

## Instructions

### Compilation

```bash
make            # builds libft.a
make clean      # removes object files
make fclean     # removes object files and libft.a
make re         # fclean + all
```

This produces `libft.a` at the root of the repository, built with
`-Wall -Wextra -Werror` via `cc`, and archived with `ar`.

### Using the library

Include the header and link against the archive when compiling a project
that uses it:

```bash
cc -Wall -Wextra -Werror your_program.c libft.a -I. -o your_program
```

Or, in another project's own Makefile, copy this `libft` directory in and
compile the library first, then link `libft.a` alongside your other
object files.

## Library overview

### Part 1 — libc reimplementations

Character classification (`ft_isalpha`, `ft_isdigit`, `ft_isalnum`,
`ft_isascii`, `ft_isprint`), string length (`ft_strlen`), memory operations
(`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`,
`ft_memcmp`), string operations (`ft_strchr`, `ft_strrchr`, `ft_strncmp`,
`ft_strnstr`, `ft_strlcpy`, `ft_strlcat`), case conversion (`ft_toupper`,
`ft_tolower`), and conversion (`ft_atoi`, `ft_calloc`, `ft_strdup`) — each
matching the prototype and behavior of its libc counterpart.

### Part 2 — additional functions

- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split` — allocate and return
  new strings derived from an existing one, with malloc-failure and
  out-of-range input handled by clamping rather than crashing.
- `ft_itoa` — converts an `int` to a newly allocated string, including
  `INT_MIN`, by working in a wider integer type internally.
- `ft_strmapi`, `ft_striteri` — apply a caller-supplied, index-aware
  function to every character of a string, either building a new string
  (`strmapi`) or mutating in place (`striteri`).
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` — write a
  character, string, string+newline, or integer to a given file descriptor.

### Part 3 — linked lists (`t_list`)

A generic singly linked list (`void *content`, `struct s_list *next`) with:
creation (`ft_lstnew`), insertion (`ft_lstadd_front`, `ft_lstadd_back`),
traversal (`ft_lstsize`, `ft_lstlast`), single- and whole-list deletion
(`ft_lstdelone`, `ft_lstclear`), side-effecting iteration (`ft_lstiter`),
and list-transforming mapping with failure-safe cleanup (`ft_lstmap`). Since
`content` is `void *`, the caller supplies their own content-freeing
function (`del`) so the list stays reusable for any data type.

## Resources

- `man` pages for each libc function being reimplemented (`man strlcpy`,
  `man strlcat`, `man memcpy`, etc.) — the primary reference for exact
  prototypes, parameter semantics, and documented edge-case behavior.
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) — background
  reading on C strings, memory, and pointers.
- The 42 Norm (current PDF, via the intranet) — for declaration/assignment
  separation and general formatting rules.

### AI usage disclosure


- **This README** was drafted with AI assistance, based on the actual
  implementation history of this project, and reviewed and edited by me
  before submission.

Per the project's own
AI-usage guidance, the intent throughout was to use it as a tool for
building understanding rather than as a substitute for it.
