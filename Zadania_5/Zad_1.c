#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node* createNode(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_first(Node **head, int value) {
    Node *new_node = createNode(value);
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    add_first(&head, 3);
    print_list(head);
    add_first(&head, 2);
    print_list(head);
    add_first(&head, 1);
    print_list(head);
    return 0;
}
