#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

node_t *top = NULL;

void stack_Push(int newval) {
/**************************************************************/
/*                                                            */
/* stack_Push: See header description                         */
/*                                                            */
/* Params:                                                    */
/*    newval - int to be added to the top of the stack        */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
  node_t *newNode;

  if (top == NULL) {
    top = malloc(sizeof(node_t));
    top->item = newval;
    top->next = NULL;
  } else {
    newNode = malloc(sizeof(node_t));
    newNode->item = newval;
    newNode->next = top;
    top = newNode;
  }
}
  
int stack_Pop() {
/**************************************************************/
/*                                                            */
/* stack_Pop: See header description                          */
/*                                                            */
/* Returns: The value popped off the top of the stack         */
/*                                                            */
/**************************************************************/
  int retval;
  node_t* tmpNode;
  
  if (top == NULL) {
    return EmptyStack;
  } else {
    retval = top->item;
    tmpNode = top;
    top = top->next;
    free(top);
    return retval;
  }
}

int stack_Peek() {
/**************************************************************/
/*                                                            */
/* stack_Peek: See header description                         */
/*                                                            */
/* Returns: The value at the top of the stack                 */
/*                                                            */
/**************************************************************/
  if (top != NULL) {
    return top->item;
  } else {
    return EmptyStack;
  }
}

int stack_isEmpty() {
/**************************************************************/
/*                                                            */
/* stack_Pop: See header description                          */
/*                                                            */
/* Returns: Boolean indicating if the stack is empty or not   */
/*                                                            */
/**************************************************************/
  return top == NULL;
}

void stack_Print() {
/**************************************************************/
/*                                                            */
/* stack_Pop: See header description                          */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
  node_t *iterNode = top;
  while(iterNode != NULL) {
    printf("%d\n", iterNode->item);
    iterNode = iterNode->next;
  }
  printf("\n");
}

int main(void) {
  
  //Example usage
  stack_Push(1);
  stack_Push(2);
  stack_Push(3);
  stack_Push(4);
  stack_Push(5);
  stack_Print();
  assert(5 == stack_Peek());
  stack_Pop();
  assert(4 == stack_Peek());
  stack_Pop();
  stack_Print();
  stack_Pop();
  stack_Pop();
  stack_Pop();
  assert(stack_isEmpty());
  assert(EmptyStack == stack_Pop());
  stack_Print();

  return 0;
}
