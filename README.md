School project

Introduction
The Push swap project is a very simple and a highly straightforward algorithm project:
data must be sorted.
You have at your disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks

---

The rules
* You have 2 stacks named a and b.
* At the beginning:
* The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
* The stack b is empty.
* The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

**sa (swap a):** 
>Swap the first 2 elements at the top of stack a. 
>Do nothing if there is only one or no elements.

**sb (swap b):** 
>Swap the first 2 elements at the top of stack b.
>Do nothing if there is only one or no elements.

**ss : ** 
>sa and sb at the same time.

**pa (push a): ** 
>Take the first element at the top of b and put it at the top of a.
>Do nothing if b is empty.

**pb (push b):** 
>Take the first element at the top of a and put it at the top of b.
>Do nothing if a is empty.

**ra (rotate a):**  
>Shift up all elements of stack a by 1.
>The first element becomes the last one.

**rb (rotate b): ** 
>Shift up all elements of stack b by 1.
>The first element becomes the last one.

**rr :** 
>ra and rb at the same time.

**rra (reverse rotate a):** 
>Shift down all elements of stack a by 1.
>The last element becomes the first one.

**rrb (reverse rotate b): ** 
>Shift down all elements of stack b by 1.
>The last element becomes the first one.

**rrr :** 
>rra and rrb at the same time.

---

Some odd choices may be explaned by the required norm, research 42norminette if interested, some of its rules are 
1. No global variables
2. Always declare variables at the beginning of the function
3. Don't assign values to variables on the same line as the declaration
4. Max 25 lines per function
5. Max 5 functions per file
6. Max 4 arguments per function
7. Max 80 colums per line (1 tab = 4 cols)
8. It's forbidden to use Do while, for, switch, etc
