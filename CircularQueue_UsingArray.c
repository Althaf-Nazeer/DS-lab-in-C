#include<stdio.h>
#include<stdlib.h>

int front,rear,size,choice,array[100],i,m,n;

void enqueue(int n){
    if((rear+1)%size==front){
        printf("\n THE QUEUE IS FULL");
    }
    else if(rear==-1){
        rear=0;
        front=0;
        array[rear]=n;
    }
    else{
        rear=(rear+1)%size;
        array[rear]=n;
    }
    
}

void dequeue(){
    int m;
    if(front==-1){
        printf("\n THE QUEUE IS EMPTY");
    }
    else if(front==rear){
        m=array[front];
        printf("\n THE DELETED ELEMENT IS %d" , m);
        rear=-1;
        front=-1;
    }
    else{
        m=array[front];
        printf("\n THE DELETED ELEMENT IS %d" , m);
        front=(front+1)%size;
    }
}

void display(){
    if(front==-1){
        printf("\n THE QUEUE IS EMPTY");
    }
    else if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("\n%d",array[i]);
        }
    }
    else{
        for(i=front;i<=size-1;i++){
            printf("\n%d",array[i]); 
        }
        for(i=0;i<=rear;i++){
            printf("\n%d",array[i]); 
        }
    }
}

void main(){
    front=-1;
    rear=-1;
    int n,m;
    printf("\n ENTER THE SIZE OF THE QUEUE");
    scanf("%d",&size);
    do{
        printf(" \n ENTER 1 TO ENQUEUE \n ENTER 2 TO DEQUEUE \n ENTER 3 TO DISPLAY \n ENTER 4 TO EXIT");
        printf(" \n ENTER YOUR CHOICE");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: printf(" \n ENTER THE ELEMENT TO ENQUEUE");
                    scanf("%d",&n);
                    enqueue(n);
                    break;
            case 2: dequeue();
                    break;
            case 3: printf("\n THE QUEUE IS");
                    display();
                    break;
            case 4: printf(" \n THE PROGRAM HAS ENDED");
                    break;
            default:printf(" \n ENTER A CHOICE FROM (1,2,3,4)");
        }
    }
    while(choice!=4);
}
