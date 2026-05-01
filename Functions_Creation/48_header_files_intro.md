Exercise: ftt.h  

Description:  
Create a header file that contains function prototypes for basic utility functions.  
This header should be protected against multiple inclusions using include guards.  

File name:  
ftt.h  

💡 Explanation:  
- `#ifndef FTT_H`  
  → Means “if not defined”. It checks if the macro `FTT_H` has **not** been defined yet.  
  If it hasn’t, the following code will be included.  

- `#define FTT_H`  
  → Defines the macro `FTT_H`, marking that this header has already been included.  
  This prevents the compiler from including it multiple times in the same project,  
  which could otherwise cause duplicate declaration errors.  

- `#endif`  
  → Ends the conditional block that started with `#ifndef`.  
  Everything between `#ifndef` and `#endif` is included **only once**.

Together, these three lines are called an **include guard**.  
They ensure your header file is included just once by the compiler,  
even if multiple `.c` files include it.

---

💡 Solution
#ifndef FTT_H
# define FTT_H

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
