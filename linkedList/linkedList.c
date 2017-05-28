#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"
#define NoMem    0x0000
#define NullList 0xFFFF

void linkedList_AddFront (int newval, node_t **llist)
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: See header description                */
/*                                                            */
/* Params:                                                    */
/*    newval - int to be added to the front of linked list    */
/*    llist  - linked list to be added to                     */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
{
	node_t* newNode;
	
	newNode = malloc(sizeof(node_t));
	newNode->item = newval;
	newNode->next = *llist;
	
	//Change what the head points to
	*llist = newNode;
}

int linkedList_RmvFront (node_t **llist)
/**************************************************************/
/*                                                            */
/* linkedList_RmvFront: See header description                */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to be removed from                 */
/*                                                            */
/* Returns: The value deleted                                 */
/*                                                            */
/**************************************************************/
{
	node_t  *newFront;
	int     removed;

	if (*llist == NULL) {
		return NullList;
	} else {
		newFront = (*llist)->next;
		removed = (*llist)->item;

		free(*llist);
		*llist = newFront;
		return removed;
	}
}

void linkedList_AddBack (int newval, node_t *llist)
/**************************************************************/
/*                                                            */
/* linkedList_AddBack: See header description                 */
/*                                                            */
/* Params:                                                    */
/*    newval - int to be added to the back of linked list     */
/*    llist  - linked list to be added to                     */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
{
	node_t *newNode;
	node_t *curNode;

	newNode = malloc(sizeof(node_t));
	newNode->item = newval;
	newNode->next = NULL;

	if (llist != NULL) {
		curNode = llist;
		while (curNode->next != NULL) {
			curNode = curNode->next;
		}
		curNode->next = newNode;
	} else {
		llist = newNode;
	}
}

int linkedList_RmvBack (node_t *llist)
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: See header description                */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to be removed from                 */
/*                                                            */
/* Returns: The value deleted                                 */
/*                                                            */
/**************************************************************/
{
	int    removed;
	node_t *curNode;

	if (llist == NULL) {
		return NullList;
	} else if (llist->next == NULL) {
    //Only one node in list
		removed = llist->item;
		free(llist);
		return removed;
	} else {
		curNode = llist;
		while (curNode->next->next != NULL) {
			curNode = curNode->next;
		}
		removed = curNode->next->item;
		free(curNode->next);
		curNode->next = NULL;
		return removed;
	}
}

int linkedList_Length (node_t *llist)
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: See header description                */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to take the length of              */
/*                                                            */
/* Returns: The length of the linked list                     */
/*                                                            */
/**************************************************************/
{
	int len = 0;
	
	while (llist != NULL) {
		len++;
		llist = llist->next;
	}

	return len;
}

void linkedList_Print (node_t *llist)
/**************************************************************/
/*                                                            */
/* linkedList_AddFront: See header description                */
/*                                                            */
/* Params:                                                    */
/*    llist  - linked list to print                           */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
{
	if (llist == NULL) {
		printf("List Empty!\n");
	} else {
		while (llist != NULL) {
			printf("%d ", llist->item);
			llist = llist->next;
		}
		printf("\n");
	}
}

int main(void) {
	node_t *head = NULL;

  //Create the initial node for the llist
	head = malloc(sizeof(node_t));
	if (head == NULL) {
		return NoMem;
	}
	head->item = 1;
	head->next = NULL;

  /* Use methods here */

  // Example usage
  linkedList_AddFront(2, &head);
  linkedList_AddFront(3, &head);
  linkedList_Print(head);
  assert(linkedList_Length(head) == 3);
  linkedList_RmvBack(head);
  linkedList_Print(head);
  linkedList_AddBack(1, head);
  linkedList_Print(head);
  assert(linkedList_Length(head) == 3);
  linkedList_RmvFront(&head);
  linkedList_RmvBack(head);
	linkedList_RmvFront(&head);
	assert(linkedList_Length(head) == 0);
	return 0;
}
