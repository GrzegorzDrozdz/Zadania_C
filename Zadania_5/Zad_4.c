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

void remove_by_index(Node **head, int index) {
    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return;
    }
    if (index == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *current = *head;
    Node *prev = NULL;
    int i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Nieprawidłowy indeks\n");
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
    printf("Lista przed usunieciem elementu na indeksie 1:\n");
    print_list(head);

    remove_by_index(&head, 1);

    printf("Lista po usunieciu elementu na indeksie 1:\n");
    print_list(head);

    return 0;
}
