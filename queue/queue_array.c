// Time Complexity: O(1)
// Space Complexity: O(n)

#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Removed: %d\n", queue[front++]);
}

int main() {
    enqueue(5);
    enqueue(10);
    dequeue();
    return 0;
}
