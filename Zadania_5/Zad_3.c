#include <stdio.h>
#include <stdlib.h>

typedef struct listElement {
    int data;
    struct listElement *next;
} listElement;

listElement *head = NULL;

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

void remove_last() {
    if (head == NULL) {
        printf("Lista jest pusta. Nie można usunąć ostatniego elementu.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    listElement *current = head;
    listElement *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
prev->next = NULL;
    free(current);
}

int main() {
    push(3);
    push(2);
    push(1);


    printf("Lista przed usunięciem ostatniego elementu:\n");
    print_list();


    remove_last();


    printf("Lista po usunięciu ostatniego elementu:\n");
    print_list();

    return 0;
}
