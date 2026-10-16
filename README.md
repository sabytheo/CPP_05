*This project has been created as part of the 42 curriculum by tsaby.*

# C++ Module 05

> Repetition and exceptions

## Description

Exceptions and custom exception classes, through a very bureaucratic office.

Part of the C++ piscine of the 42 curriculum: every exercise is written in **C++98** and compiled with `-Wall -Wextra -Werror -std=c++98`.

## Exercises

| Exercise | Name | What it does |
|---|---|---|
| [`ex00`](ex00/) | Mommy, when I grow up, I want to be a bureaucrat! | `Bureaucrat` with a grade from 1 to 150, throwing `GradeTooHighException` / `GradeTooLowException` when out of range. |
| [`ex01`](ex01/) | Form up, maggots! | `Form` with a grade required to sign it; `Bureaucrat::signForm()` reports success or the reason of the failure. |
| [`ex02`](ex02/) | No, you need form 28B, not 28C... | Abstract `AForm` and three concrete forms: `ShrubberyCreationForm` (writes ASCII trees to a file), `RobotomyRequestForm` (50% success) and `PresidentialPardonForm`. |
| [`ex03`](ex03/) | At least this beats coffee-making | `Intern::makeForm()` creates the right form from its name, without a chain of if/else. |

## Instructions

Each exercise is an independent program with its own `Makefile`:

```bash
cd ex00
make
```

| Exercise | Binary | Usage |
|---|---|---|
| `ex00` | `Mommy` | `./Mommy` |
| `ex01` | `Form` | `./Form` |
| `ex02` | `Form` | `./Form` |
| `ex03` | `Form` | `./Form` |

`make clean` removes the object files, `make fclean` also removes the binary and `make re` rebuilds from scratch.

## Resources

- [cppreference.com](https://en.cppreference.com/w/cpp) — language and standard library reference
- [cplusplus.com](https://cplusplus.com/reference/) — C++98 standard library reference
