/**
  * @Brief: Create stack library based on linked list
  */
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
  * @brief  call anouther function with its pointer.
  * @param  ptr 
  * @retval error code
  */
int Pop(node_t ** head, int * val) 
{
    node_t * current = *head;

    if (current == NULL)  
    { 
        return -1; /*stack is empty*/
    }

    if (current->next == NULL) /*It is the last*/ 
    { 
        *head = NULL;
    } else
    {
        *head = current->next;
    }

    *val = current->val;
    free(current);
    
    return 0;
}

/**
  * @brief  This function reads surrent stack value.
  * @param  head is Pointer to head node what is a top of stack. val - Pointer to value 
  * @retval error code 
  */
int Read(node_t ** head, int* value) 
{
    node_t * current = *head;

    if ((current == NULL)) 
    { 
        return -1; /*stack is empty*/
    }
    *value = current->val;
    return 0;
}

/**
  * @brief  This function pushes new value on the stak top.
  * @param  pointer to head (top of stack). Value to be pushed 
  * @retval error code. If not 0 - then no free memory and stack is considered as full.
  */
int Push(node_t ** head, int val) 
{
    node_t * current = *head;

    current = malloc(sizeof(node_t));
    if (current == NULL) 
    { 
        return -1; /*No free mem - exit with error indication. Conside like stack is full!!!*/
    }
    current->next = *head;
    current->val = val;
    *head = current; 

    return 0;
}

int main()
{
    /* Init the Stack */
    node_t * head = NULL;
    node_t * current = head;
    int val;

    printf("Case 1: Read the empty stack:\n");
    if(Read(&head, &val)==0)
    {
        printf("Value: %d\n",val);
    }else
    {
        printf("Stack is empty\n");
    }


    printf("Case 2: Add value (10) to top of stack and read back:\n");
    Push(&head, 10);
     if(Read(&head, &val)==0)
    {
        printf("Value: %d\n",val);
    }else
    {
        printf("Stack is empty\n");
    }
     if(Read(&head, &val)==0)
    {
        printf("Value: %d\n",val);
    }else
    {
        printf("Stack is empty\n");
    }

    printf("Case 3: Add more values (15,20,25) to stack and print list:\n");
    Push(&head, 15);
    Push(&head, 20);
    Push(&head, 25);
    print_list(head);


    printf("Case 4: Read top of stack:\n");
    if(Read(&head, &val)==0)
    {
        printf("Value: %d\n",val);
    }else
    {
        printf("Stack is empty\n");
    }

    printf("Case 5: Get top of stack till stack is empty:\n");

    while (Pop(&head,&val)==0)
    {
        printf("Value: %d\n",val);
    }

    printf("Try Pop()\n");
    if(Pop(&head,&val)==0)
    {
        printf("    Value: %d\n",val);
    }else
    {
        printf("    Stack is empty\n");
    }

    printf("Try Read()\n");
    if(Read(&head,&val)==0)
    {
        printf("    Value: %d\n",val);
    }else
    {
        printf("    Stack is empty\n");
    }

    printf("Try to Push (125)\n");
    Push(&head, 125);
    printf("Try to Pop\n");
    if(Pop(&head,&val)==0)
    {
        printf("    Value: %d\n",val);
    }else
    {
        printf("    Stack is empty\n");
    }

    printf("Try to Pop once more\n");
    if(Pop(&head,&val)==0)
    {
        printf("    Value: %d\n",val);
    }else
    {
        printf("    Stack is empty again\n");
    }


}

