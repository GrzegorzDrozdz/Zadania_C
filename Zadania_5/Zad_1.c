#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

void add_first(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);
    print_list(head);
    return 0;
}