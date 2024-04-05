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

void remove_by_index(int index) {
    if (head == NULL) {
        printf("Lista jest pusta. Nie można usunąć elementu.\n");
        return;
    }

    if (index <= 0) {
        listElement *temp = head;
        head = head->next;
        free(temp);
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

    if (current == NULL) {
        printf("Indeks przekracza długość listy. Nie można usunąć elementu.\n");
        return;
    }

     prev->next = current->next;

     free(current);
}

int main() {

    push(3);
    push(2);
    push(1);

    printf("Lista przed usunięciem elementu:\n");
    print_list();


    remove_by_index(1);


    printf("Lista po usunięciu elementu:\n");
    print_list();

    return 0;
}
