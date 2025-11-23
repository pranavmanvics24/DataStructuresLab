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

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

Node* concatenateLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    
    insertAtEnd(&list1, 5);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 8);
    insertAtEnd(&list1, 1);
    
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 7);
    insertAtEnd(&list2, 4);
    
    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);
    
    printf("\nAfter sorting List 1: ");
    sortList(&list1);
    displayList(list1);
    
    printf("\nAfter concatenation: ");
    list1 = concatenateLists(list1, list2);
    displayList(list1);
    
    printf("After reversing: ");
    list1 = reverseList(list1);
    displayList(list1);
    
    return 0;
}
