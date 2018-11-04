#include <stdlib.h>
#include <stdio.h>
#include "llist.h"






int main()
{
    // Init the list with 1-st value
    node_t * head = NULL;
    node_t * current = head;
    int val;
    head = malloc(sizeof(node_t));
    if (head == NULL) 
    { 
        return -1; /*No free mem - exit with error*/
    }
    head->next = NULL;
    head->val = 1;

    printf("Initial list:\n");
    print_list(head);
//return 0;
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

