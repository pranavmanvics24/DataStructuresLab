#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void displayInorder(struct Node* root) {
    printf("\nIn-order Traversal: ");
    if (root == NULL) {
        printf("Tree is empty");
    } else {
        inorder(root);
    }
    printf("\n");
}

void displayPreorder(struct Node* root) {
    printf("\nPre-order Traversal: ");
    if (root == NULL) {
        printf("Tree is empty");
    } else {
        preorder(root);
    }
    printf("\n");
}

void displayPostorder(struct Node* root) {
    printf("\nPost-order Traversal: ");
    if (root == NULL) {
        printf("Tree is empty");
    } else {
        postorder(root);
    }
    printf("\n");
}

void displayAll(struct Node* root) {
    displayInorder(root);
    displayPreorder(root);
    displayPostorder(root);
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    
    while (1) {
        printf("\n\n===== Binary Search Tree Menu =====\n");
        printf("1. Insert Element\n");
        printf("2. Display In-order Traversal\n");
        printf("3. Display Pre-order Traversal\n");
        printf("4. Display Post-order Traversal\n");
        printf("5. Display All Traversals\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Element %d inserted successfully!\n", value);
                break;
                
            case 2:
                displayInorder(root);
                break;
                
            case 3:
                displayPreorder(root);
                break;
                
            case 4:
                displayPostorder(root);
                break;
                
            case 5:
                displayAll(root);
                break;
                
            case 6:
                printf("\nExiting program...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
