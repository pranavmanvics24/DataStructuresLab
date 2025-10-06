#include <stdio.h> 
#define max 5
int queue[max];
int front = -1, rear = -1;

int isfull() {
    return ((rear + 1) % max == front);
}

int isempty() {
    return (front == -1);
}

int insert(int element) {
    if (isfull()) {
        printf("Queue has no more space\n");
        return -1;
    }
    if (isempty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % max;
    }
    queue[rear] = element;
    return 0;
}

int delete() {
    int x;
    if (isempty()) {
        printf("Queue is empty\n");
        return -1;
    }
    x = queue[front];
    printf("%d has been deleted\n", x);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max;
    }
    return x;
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements in the queue are-> ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % max;
    }
    printf("\n");
}

int main() {
    int choice, element;
    do {
        printf("Enter 1 to insert element\n");
        printf("Enter 2 to delete element\n");
        printf("Enter 3 to display queue\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert\n");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
