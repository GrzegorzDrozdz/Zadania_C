#include <stdio.h>
#include <stdlib.h>

typedef struct listElement {
    int data;
    struct listElement *next;
} listElement;

listElement *head = NULL;

void pop() {
    if (head == NULL) {
        printf("Lista jest pusta. Nie można usunąć pierwszego elementu.\n");
        return;
    }

    listElement *temp = head;
    head = head->next;

    free(temp);
}

void push(int val) {
    listElement *new_node = malloc(sizeof(listElement));
    if (new_node == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void print_list() {
    listElement *current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    push(3);
    push(2);
    push(1);

    printf("Lista przed usunięciem pierwszego elementu:\n");
    print_list();

    pop();

    printf("Lista po usunięciu pierwszego elementu:\n");
    print_list();

    return 0;
}
