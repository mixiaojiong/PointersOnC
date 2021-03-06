#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
}Node;
typedef struct Transaction {
    int value;
}Transaction;

int main (void) {
}

/*
 * ** Modified prototypes for existing functions (the functions themselves must be
 * ** modified to match).
 * */
void    add_new_trans( Node *list, Node **current, Transaction *trans );
void    delete_trans( Node *list, Node **current, Transaction *trans );
void    search( Node *list, Node **current, Transaction *trans );
void    edit( Node *list, Node **current, Transaction *trans );
/*
 * **      Definitions of the new functions that are needed.
 * */
    void
forward( Node *list, Node **current, Transaction *trans )
{
    *current = (*current)->next;
}
    void
backward( Node *list, Node **current, Transaction *trans )
{
    *current = (*current)->prev;
}
void    (*function[])( Node *list, Node **current, Transaction *trans ) = {
    add_new_trans,
    delete_trans,
    forward,
    backward,
    search,
    edit
};
