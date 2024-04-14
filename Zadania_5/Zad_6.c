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

void add_at_index(Node **head, int index, int value) {
    if (index <= 0) {
        add_first(head, value);
        return;
    }
    Node *new_node = createNode(value);
    Node *current = *head;
    Node *prev = NULL;
    int i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }
    if (current == NULL && i < index) {
        printf("Indeks przekracza długość listy. Nie dodano elementu.\n");
        free(new_node);
        return;
    }
    prev->next = new_node;
    new_node->next = current;
}

int main() {
    Node *head = NULL;
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);
    printf("Lista przed dodaniem elementu o wartosci 5 na indeksie 2:\n");
    print_list(head);

    add_at_index(&head, 2, 5);

    printf("Lista po dodaniu elementu o wartosci 5 na indeksie 2:\n");
    print_list(head);

    return 0;
}
