#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to stack\n", data);
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peekStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void displayStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        printf("Enqueued %d to queue\n", data);
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    printf("Enqueued %d to queue\n", data);
}

int dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    Node* temp = *front;
    int dequeued = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return dequeued;
}

int peekQueue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void displayQueue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* stackTop = NULL;
    Node* queueFront = NULL;
    Node* queueRear = NULL;
    
    printf(" Stack Operations \n");
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    push(&stackTop, 40);
    displayStack(stackTop);
    printf("Top element: %d\n", peekStack(stackTop));
    printf("Popped: %d\n", pop(&stackTop));
    printf("Popped: %d\n", pop(&stackTop));
    displayStack(stackTop);
    
    printf("\n Queue Operations \n");
    enqueue(&queueFront, &queueRear, 5);
    enqueue(&queueFront, &queueRear, 15);
    enqueue(&queueFront, &queueRear, 25);
    enqueue(&queueFront, &queueRear, 35);
    displayQueue(queueFront);
    printf("Front element: %d\n", peekQueue(queueFront));
    printf("Dequeued: %d\n", dequeue(&queueFront, &queueRear));
    printf("Dequeued: %d\n", dequeue(&queueFront, &queueRear));
    displayQueue(queueFront);
    
    return 0;
}
