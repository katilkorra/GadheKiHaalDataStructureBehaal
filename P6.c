#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0;
int rear = -1;
int count = 0;

void enqueue(int element) {
    if (count == MAX_SIZE) {
        printf("Queue is full.\n");
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = element;
    count++;
}

int dequeue() {
int element;
    if (count == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    element = queue[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return element;
}

void display() {
int i;
    if (count == 0) {
        printf("Queue is empty.\n");
        return;
    }
    for (i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % MAX_SIZE]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
