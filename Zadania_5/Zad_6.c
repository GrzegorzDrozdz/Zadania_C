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

void add_at_index(int index, int value) {
    if (index <= 0) {
        push(value);
        return;
    }

    listElement *current = head;
    listElement *prev = NULL;
    int i = 0;

     while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL && i < index) {
           printf("Indeks przekracza długość listy. Nie dodano elementu.\n");
        return;
    }

    listElement *new_node = malloc(sizeof(listElement));
    if (new_node == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci.\n");
        exit(EXIT_FAILURE);
    }
   prev->next = new_node;
    new_node->next = current;
}

int main() {
    push(3);
    push(1);

    printf("Lista przed dodaniem elementu na indeksie 1:\n");
    print_list();

     add_at_index(1, 2);

    printf("Lista po dodaniu elementu na indeksie 1:\n");
    print_list();

    return 0;
}
