#define SIZE 5
int cq[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    cq[rear] = value;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("%d removed\n", cq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

