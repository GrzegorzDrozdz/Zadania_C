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

void remove_last(Node **head) {
    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return;
    }
    Node *current = *head;
    Node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        free(current);
        *head = NULL;
    } else {
        prev->next = NULL;
        free(current);
    }
}

int main() {
    Node *head = NULL;
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);
    printf("Lista przed usunieciem ostatniego elementu:\n");
    print_list(head);

    remove_last(&head);

    printf("Lista po usunieciu ostatniego elementu:\n");
    print_list(head);
    remove_last(&head);
    print_list(head);
    remove_last(&head);
    print_list(head);
    remove_last(&head);
    print_list(head);
    return 0;
}
