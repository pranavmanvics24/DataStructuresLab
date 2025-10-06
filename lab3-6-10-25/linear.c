#include <stdio.h> 
#define max 5
int queue[max];
int front=-1,rear=-1;

int isfull(){
    return(rear == max-1);
}

int isempty(){
    return(rear==-1 || front>rear);
}

int insert (int element){
    if (isfull()){ printf("Queue has no more space\n"); return -1;
        }
    if (front==-1) front=0;
    rear++;
    queue[rear]=element;
    return 0;
}
int delete(){
    int x;
    if (isempty()){
        printf("Queue is empty\n");
        return -1;
    }else{
        x=queue[front];
        printf("%d has been deleted\n",x);
    }
     if (front == rear) {
        front = -1;
        rear = -1;
    }else{
        front++;
    }
    return x;
}

void display(){
    printf("The elements in the queue are-> ");
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
}

void main(){
    int choice,element;
    do {
        printf("enter 1 to insert element\n");
        printf("enter 2 to delete element\n");
        printf("enter 3 to display queue\n");
        printf("enter 4 to exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case(1):
                printf("Enter element to insert\n");
                scanf("%d",&element);
                insert(element);
                break;
            case(2):
                delete();
                break;
            case(3):
                display();
                break;
            case(4):
                break;
            default:
                printf("invalid input");
                break;
        }
}while(choice!=4);
}