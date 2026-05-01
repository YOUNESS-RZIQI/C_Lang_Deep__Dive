README.md
=========

_This project has been created as part of the 42 curriculum by `yrziqi`._

Description
-----------

**Push\_swap** is a highly efficient sorting project that challenges the developer to sort a random stack of integers using a limited set of stack instructions. The primary goal is to achieve the sorted state with the **minimum number of operations**.

The project involves two stacks, **A** and **B**. The program starts with a random list of integers in Stack A and must output the sequence of instructions (like sa, pb, ra, rra) required to sort them. This implementation uses a **Doubly Linked List** for memory-efficient stack manipulation and utilizes the **Butterfly Algorithm** (Range-based sorting) to handle large datasets (100 and 500 numbers) effectively.

Instructions
------------

### Compilation

The project includes a Makefile that compiles all source files with the -Wall -Wextra -Werror flags. To compile, run:

Bash

`   make   `

### Execution

To run the program, provide a list of integers as arguments:

Bash

`   ./push_swap 4 67 3 1 23   `

You can also pass the numbers as a single quoted string:

Bash

`   ./push_swap "4 67 3 1 23"   `

### Usage Example

To verify the move count for a specific set of numbers:

Bash

`   ARG="4 67 3 1 23"; ./push_swap $ARG | wc -l   `

Resources
---------

### Documentation & Articles

*   **42 Project Subject:** The official project guidelines.
    
*   **Butterfly Algorithm Concepts:** Research on range-based sorting for stack-based constraints.
    
*   **Doubly Linked Lists:** Standard C documentation for data structure management.
    

### AI Usage Disclosure

In this project, Artificial Intelligence (Gemini) was used as a **secondary educational resource**.

*   **Role of AI:** The AI acted as a "teacher" or a "mentor." It did not write the final source code. Instead, it was used to clarify complex edge cases when I got stuck and to provide conceptual questions that helped me brainstorm my own solutions.
    
*   **Tasks:** AI was used for explaining the logic behind the Butterfly Algorithm and for helping debug specific logic errors in the sort\_five and pull\_back\_to\_stack\_a functions. All code implementation, data structure design (DLL), and parsing logic were written manually by me to ensure deep understanding and compliance with 42 standards.