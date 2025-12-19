// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;

    printList(head);
    return 0;
}
