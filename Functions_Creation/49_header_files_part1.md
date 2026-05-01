Exercise: ft_boolean.h  

Description:  
Create a header file that defines a custom boolean type and related macros for clarity and convenience.  
This header provides macros for `TRUE`, `FALSE`, and checks if a number is even, along with message constants.
 
Explanation:  
- `#ifndef FT_BOOLEAN_H` / `#define FT_BOOLEAN_H` / `#endif`  
  → These form the *include guard* to prevent multiple inclusions of the same header file.  

- `#include <unistd.h>`  
  → Allows using the `write()` function if needed in your boolean programs.  

- `typedef int t_bool;`  
  → Defines `t_bool` as an alias for `int`. This gives a clear type name for boolean values.  

- `#define TRUE 1` / `#define FALSE 0`  
  → Defines constants to represent true and false values for readability.  

- `#define EVEN(nbr) (nbr % 2 == 0)`  
  → A macro that returns true if `nbr` is even, otherwise false.  

- `#define EVEN_MSG` / `#define ODD_MSG`  
  → Message macros that can be printed depending on whether the argument count is even or odd.  

---

💡 Solution
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>

typedef int	t_bool;

# define TRUE 1
# define FALSE 0
# define SUCCESS 0

# define EVEN(nbr) (nbr % 2 == 0)

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

#endif
