#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    int info;
    struct linked_list* next_p;
} l_list;
l_list* l_list_init(int item) {
    l_list *l_p;
    l_p = malloc(sizeof(struct linked_list));
    l_p->info = item;
    l_p->next_p = NULL;
    return l_p;
}
l_list* add_list(l_list* head, int item) {
    if (head == NULL) {
        return l_list_init(item);
    }
    l_list* current = head;
    while (current->next_p != NULL) {
        current = current->next_p;
    }
    current->next_p = l_list_init(item);
    return head;
}
void free_list(l_list* head) {
    l_list* temp;
    while (head != NULL) {
        temp = head;
        head = head->next_p;
        free(temp);
    }
}
void print_list(l_list* head) {
    l_list* reversed_head = NULL;
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->info);
        l_list* temp = l_list_init(head->info);
        temp->next_p = reversed_head;
        reversed_head = temp;
        head = head->next_p;
    }
    while (reversed_head != NULL) {
        printf("%d ", reversed_head->info);
        reversed_head = reversed_head->next_p;
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    l_list* head = NULL;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int item;
        scanf("%d", &item);
        head = add_list(head, item);
    }
    print_list(head);
    free_list(head);
    return 0;
}