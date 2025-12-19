// Time Complexity:
// Insert/Delete Front: O(1)
// Insert/Delete Middle & Last: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->prev = node->next = NULL;
    return node;
}

// Insert at front
struct Node* insertFront(struct Node* head, int value) {
    struct Node* node = createNode(value);
    node->next = head;
    if (head) head->prev = node;
    return node;
}

// Insert at last
struct Node* insertLast(struct Node* head, int value) {
    struct Node* node = createNode(value);
    if (!head) return node;

    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}

// Insert after a given key (middle)
struct Node* insertMiddle(struct Node* head, int key, int value) {
    struct Node* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) return head;

    struct Node* node = createNode(value);
    node->next = temp->next;
    node->prev = temp;

    if (temp->next)
        temp->next->prev = node;

    temp->next = node;
    return head;
}

// Delete front
struct Node* deleteFront(struct Node* head) {
    if (!head) return NULL;

    struct Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    return head;
}

// Delete last
struct Node* deleteLast(struct Node* head) {
    if (!head || !head->next) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next) temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Delete a given key (middle)
struct Node* deleteMiddle(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) return head;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

void display(struct Node* head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertFront(head, 10);
    head = insertLast(head, 30);
    head = insertMiddle(head, 10, 20);

    display(head);

    head = deleteFront(head);
    head = deleteMiddle(head, 20);
    head = deleteLast(head);

    display(head);
    return 0;
}
