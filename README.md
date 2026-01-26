*This project has been created as part of the 42 curriculum by soahrich.*

# Description

Push_swap is a sorting algorithm project designed for the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations (push, swap, rotate, reverse rotate) with the minimum number of moves. The project focuses on algorithmic efficiency, data structure manipulation, and code style compliance.

# Instructions

## Compilation

To compile the project, run:

```sh
make
```

## Usage

After compilation, execute the program with a list of integers:

```sh
./push_swap 3 2 1
```

You can also provide numbers as quoted strings:

```sh
./push_swap "3 2 1"
```

# Resources

- [Sorting Algorithms](https://visualgo.net/en)
- [Norminette Documentation](https://github.com/42School/norminette)
- [push swap visualizer](https://push-swap42-visualizer.vercel.app/)

## AI Usage

AI (GPT) was used for:
- Code style corrections and norminette compliance
- Refactoring functions for line and variable limits
- Improving algorithm efficiency and edge case handling

## Features
- Handles all valid integer inputs
- Detects and reports errors (duplicates, invalid input)
- Efficient sorting for small and large stacks
- Modular code structure

## Technical Choices
- Written in C
- Uses linked lists for stack representation
- Follows 42 Norminette style guide

## Example

```sh
./push_swap 4 67 3 87 23
```
