#define SIZE 5
int deque[SIZE];
int front = -1, rear = -1;

void insertRear(int value) {
    if (rear == SIZE - 1) {
        printf("Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    deque[++rear] = value;
}

void insertFront(int value) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        front--;

    deque[front] = value;
}

void deleteFront() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    printf("%d removed\n", deque[front++]);
}
