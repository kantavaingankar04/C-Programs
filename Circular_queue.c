#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if ((r == NULL) && (f == NULL)) {
        f = r = n;
        r->next = f;
    } else {
        r->next = n;
        r = n;
        n->next = f;
    }
}

void dequeue() {
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else if (f == r) {
        f = r = NULL;
        free(t);
    } else {
        f = f->next;
        r->next = f;
        free(t);
    }
}

void display() {
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else {
        do {
            printf(" %d", t->data);
            t = t->next;
        } while (t != f);
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Circular Queue: ");
                display();
                printf("\n");
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
