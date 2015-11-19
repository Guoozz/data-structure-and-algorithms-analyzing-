#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct doubly_linked_node * ptr_node;
typedef struct doubly_linked_node * node;
typedef struct doubly_linked_list_head * doubly_list;
typedef int object;
typedef int bool;

doubly_list create_doubly_list(void);
node create_node(object x);
void insert(node item,doubly_list List);
void delete(node item,doubly_list List);
node search(object key,doubly_list List);
void reverse_doubly_list(doubly_list List);

#endif
