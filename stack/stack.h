/**************************************************************/
/*                                                            */
/*                                                            */
/* stack.h                                                    */
/*                                                            */
/* Defines operations for using a stack in C                  */
/*                                                            */
/* By David Skudra                                            */                      /*                                                            */
/*                                                            */
/**************************************************************/

#define NoMem      0x0000
#define EmptyStack 0xFFFF

// Defines the node structure used to create a stack
typedef struct node {
  int         item;
  struct node *next;
} node_t;

void stack_Push(
  int newval);
/**************************************************************/
/*                                                            */
/* stack_Push: Inserts a new item at the top of the stack in  */
/* O(1) time.                                                 */
/*                                                            */
/* Params:                                                    */
/*    newval - int to be added to the top of the stack        */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/

int stack_Pop();
/**************************************************************/
/*                                                            */
/* stack_Pop: Removes an item from the top of the stack in    */
/* O(1) time.                                                 */
/*                                                            */
/* Returns: The value popped off the top of the stack         */
/*                                                            */
/**************************************************************/

int stack_Peek();
/**************************************************************/
/*                                                            */
/* stack_Peek: Gives the item at the top of the stack in O(1) */
/* time without removing it from the stack.                   */
/*                                                            */
/* Returns: The value at the top of the stack                 */
/*                                                            */
/**************************************************************/

int stack_isEmpty();
/**************************************************************/
/*                                                            */
/* stack_Pop: Checks if the stack is empty or not in O(1)     */
/* time.                                                      */
/*                                                            */
/* Returns: Boolean indicating if the stack is empty or not   */
/*                                                            */
/**************************************************************/

void stack_Print();
/**************************************************************/
/*                                                            */
/* stack_Pop: Prints the stack in expected form; top element  */
/* of the stack is printed first, to the bottom element of    */
/* the stack printed last. Takes O(n) time.                   */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
