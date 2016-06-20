#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node *next;
    struct Word *second;
}Node;
typedef struct Word {
    char *data;
    struct Word *next;
}Word;
void create(Node *head);
void list(Node *head);
void insert(Node *head, char *word);
int sll_insert(Word **linkp, char *word);

int main(void) {
    Node *head;
    head = (Node *) malloc(sizeof(Node));
    head->data = -1;
    create(head);
    list(head);
    printf("=====\n");
    insert(head, "apple");
    insert(head, "a");
    insert(head, "an");
    insert(head, "be");
    insert(head, "bag");
    list(head);
}
void create(Node *head) {
    int i;
    for(i = 'a'; i <= 'z'; i++) {
        Node *current;
        current = (Node *) malloc(sizeof(Node));
        current->data = i;
        current->next = NULL;
        current->second = NULL;
        head->next = current;
        head = head->next;
    }
}
void list(Node *head) {
    head = head->next;
    Word *current;
    while(head != NULL) {
        printf("%c:", head->data);
        for(current = head->second; current != NULL; current = current->next) {
            printf("%s\t", current->data);
        }
        printf("\n");
        head = head->next;
    }
}
void insert(Node *head, char *word) {
    head = head->next;
    while(head != NULL) {
        if (head->data == *word) {
            sll_insert(&head->second, word);
            break;
        }
        head = head->next;
    }
}
int sll_insert(Word **linkp, char *word) {
    Word *current;
    Word *new;

    while ((current = *linkp) != NULL && strcmp(current->data, word) < 0) {
        linkp = &current->next;
    }
    new = (Word *)malloc(sizeof(Word));
    if (new == NULL)
        return FALSE;
    new->data = word;
    new->next = current;
    *linkp = new;
    return TRUE;
}
