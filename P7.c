#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = 0, rear = 0;

void addFront(int element) {
    if ((front - 1 + MAX) % MAX == rear) {
        printf("Deque is full!\n");
        return;
    }
    deque[front] = element;
    front = (front - 1 + MAX) % MAX;
}

void addRear(int element) {
    if ((rear + 1) % MAX == front) {
        printf("Deque is full!\n");
        return;
    }
    deque[rear] = element;
    rear = (rear + 1) % MAX;
}

int removeFront() {
    if (front == rear) {
        printf("Deque is empty!\n");
        return -1;
    }
    int element = deque[front];
    front = (front + 1) % MAX;
    return element;
}

int removeRear() {
    if (front == rear) {
        printf("Deque is empty!\n");
        return -1;
    }
    int element = deque[(rear - 1 + MAX) % MAX];
    rear = (rear - 1 + MAX) % MAX;
    return element;
}

void displayDeque() {
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("1. Add to front\n");
        printf("2. Add to rear\n");
        printf("3. Remove from front\n");
        printf("4. Remove from rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add to front: ");
                scanf("%d", &element);
                addFront(element);
                break;
            case 2:
                printf("Enter element to add to rear: ");
                scanf("%d", &element);
                addRear(element);
                break;
            case 3:
                element = removeFront();
                if (element != -1) {
                    printf("Removed from front: %d\n", element);
                }
                break;
            case 4:
                element = removeRear();
                if (element != -1) {
                    printf("Removed from rear: %d\n", element);
                }
                break;
            case 5:
                printf("Deque: ");
                displayDeque();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
