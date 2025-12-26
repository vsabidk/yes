#define SIZE 5
int pq[SIZE];
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Full\n");
        return;
    }

    int i;
    for (i = rear; i >= 0 && pq[i] < value; i--)
        pq[i + 1] = pq[i];

    pq[i + 1] = value;
    rear++;
}

void dequeue() {
    if (rear == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("%d removed\n", pq[0]);

    for (int i = 0; i < rear; i++)
        pq[i] = pq[i + 1];

    rear--;
}
