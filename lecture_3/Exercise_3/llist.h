/**
  * @brief  Declarations.
  */

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head);
int ListAdd(node_t * head, int val);
node_t* ListIs(node_t * head, int val);
int ListRemove(node_t ** head, node_t * node_del);


