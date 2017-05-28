/**************************************************************/
/*                                                            */
/*                                                            */
/* linkedList.h                                               */
/*                                                            */
/* Defines operations for using a singly linked list in C     */
/*                                                            */
/* By David Skudra                                            */                      /*                                                            */
/*                                                            */
/**************************************************************/

// Defines the node structure used to create a linked list
// Manually create the first node (head of list) and use methods
// from that point on.
typedef struct node {
	int         item;
	struct node *next;
} node_t;

void linkedList_AddFront (
  int newval, 
  node_t **llist);
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: Adds an int 'newval' to the front of  */
/* a singly linked list in O(1) time.                         */
/*                                                            */
/* Params:                                                    */
/*    newval - int to be added to the front of linked list    */
/*    llist  - linked list to be added to                     */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/

int linkedList_RmvFront (
  node_t **llist);
/**************************************************************/
/*                                                            */
/* linkedList_RmvFront: Removes an int from the front of a    */
/* singly linked list in O(1) time.                           */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to be removed from                 */
/*                                                            */
/* Returns: The value deleted                                 */
/*                                                            */
/**************************************************************/

void linkedList_AddBack (
  int newval,
  node_t *llist);
/**************************************************************/
/*                                                            */
/* linkedList_AddBack: Adds an int 'newval' to the back of a  */
/* singly linked list in O(n) time.                           */
/*                                                            */
/* Params:                                                    */
/*    newval - int to be added to the back of linked list     */
/*    llist  - linked list to be added to                     */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/

int linkedList_RmvBack (
  node_t *llist);
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: Removes an int from theback of a      */
/* singly linked list in O(n) time.                           */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to be removed from                 */
/*                                                            */
/* Returns: The value deleted                                 */
/*                                                            */
/**************************************************************/

int linkedList_Length (
  node_t *llist);
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: Returns the length of a singly linked */
/* list in O(n) time.                                         */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to take the length of              */
/*                                                            */
/* Returns: The length of the linked list                     */
/*                                                            */
/**************************************************************/

void linkedList_Print (
  node_t *llist);
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: Outputs the contents of a singly      */
/* linked list in O(n) time, or "List Empty!" if the given    */
/* list is currently empty.                                   */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to print                           */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
