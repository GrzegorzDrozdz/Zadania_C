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

void remove_by_value(Node **head, int value) {
    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return;
    }
    if ((*head)->value == value) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *current = *head;
    Node *prev = NULL;
    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Nie znaleziono elementu o podanej wartości\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

int main() {
    Node *head = NULL;
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);
    printf("Lista przed usunieciem elementu o wartosci 2:\n");
    print_list(head);

    remove_by_value(&head, 2);

    printf("Lista po usunieciu elementu o wartosci 2:\n");
    print_list(head);

    remove_by_value(&head, 1);
    printf("Lista po usunieciu elementu o wartosci 1:\n");
    print_list(head);
    return 0;
}
