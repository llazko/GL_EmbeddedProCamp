#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

/**
  * @brief  This function adds node to tail.
  * @param  node_t * head is Pointer to current node. int val is value to initialize added node
  * @retval error code: 0 - success, else no free memory to allocate new node
  */
int ListAdd(node_t * head, int val)
{
    node_t * current = head;
    /* looking for tail*/
    while (current->next != NULL) 
    {
        current = current->next;
    }
    
    current->next = malloc(sizeof(node_t));
    if (current->next == NULL) 
    { 
        return -1; /*No free mem - exit with error indication*/
    }
    /* now we can add a new variable */
    current = current->next;
    current->next = NULL; // mark as tail
    current->val = val;

    return 0;
}


/**
  * @brief  Print out of whole list.
  * @param  node_t * head is Pointer to head of list.
  * @retval nothing
  */
void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) 
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}


/**
  * @brief  This function finds the element in list.
  * @param  node_t * head is Pointer to head node. int val is value to be found
  * @retval Pointer to node which contains the value. NULL if not found.
  */
node_t* ListIs(node_t * head, int val)
{
    node_t * current = head;
    /* Go through the list, including tail*/

    while (current != NULL) 
    {
        if(current->val == val)
        {
            return current; /*Return pointer to current node*/
        }
        current = current->next;
    }

    return NULL; /*Not found*/
}

/**
  * @brief  This function removes node.
  * @param  head is Pointer to pointer !!! to head node; node_del - pointer to node to be deleted.
  * @retval success code
  */
int ListRemove(node_t ** head, node_t * node_del)
{
    node_t * current = *head;
    node_t * prev;
    if(node_del == NULL) /*Check for NULL pointer*/
    {
        return -1;
    }
    while ((current != node_del) && (current != NULL)) 
    {
        prev = current;
        current = current->next;
    }
    
    if(current == node_del)
    {
        if(current != *head)
        {
            prev->next=current->next;
        }
        else
        {
            *head = (current)->next; /*Special case for changing pointer to head*/
        }
        /* free memory */
        free(current); 
        return 0; 
    }
    if(current != NULL)
    {
        return -1; /*node not found*/
    }
}


