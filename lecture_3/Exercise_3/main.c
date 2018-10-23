#include <stdio.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

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


int main()
{
    // Init th list
    node_t * head = NULL;
    node_t * current = head;
    int val;
    head = malloc(sizeof(node_t));
    if (head == NULL) 
    { 
        return -1; /*No free mem - exit with error*/
    }
    head->val = 1;
    printf("Initial list:\n");
    print_list(head);

    //  Add one more node
    ListAdd(head,5);
    printf("List with 2 members:\n");
    print_list(head);

    printf("Extend list more:\n");
    ListAdd(head, 40);
    ListAdd(head, -5);
    ListAdd(head, 13);
    ListAdd(head, 25);
    ListAdd(head, -100);
    ListAdd(head, 400);
    ListAdd(head, 10);
    ListAdd(head, 20);
    ListAdd(head, 22);
    ListAdd(head, 23);
    print_list(head);
    
    val = 10; /* change val for verifiction*/
    printf("Find a node with spec value %d\n", val);
    current = ListIs(head,val);
    if(current!=NULL)
    {
        printf("Found val: %d\n",current->val);
    } 
    else 
    {
        printf("Val not found");
    }

    printf("Delete node with found value\n");
    ListRemove(&head,current);
    print_list(head);

    val = 400; /* change val for verifiction*/
    printf("Find a node with spec value %d\n", val);
    current = ListIs(head,val);
    if(current!=NULL)
    {
        printf("Found val: %d\n",current->val);
    } 
    else 
    {
        printf("Val not found");
    }

    printf("Delete node with found value\n");
    ListRemove(&head,current);
    print_list(head);


return 0;
}

