#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a queue
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to enqueue an element
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else if (q->front == q->rear) {
        printf("Dequeued: %d\n", q->data[q->front]);
        q->front = q->rear = -1;
    } else {
        printf("Dequeued: %d\n", q->data[q->front]);
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

// Function to display the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = q->front;
    printf("Queue elements: ");
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->data[i]);
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
