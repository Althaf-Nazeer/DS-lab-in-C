#include<stdio.h>
#include<stdlib.h>

int top,size,choice,array[100],i;

void push(int n){
    if(top==size-1){
        printf("\n THE STACK IS FULL");
    }
    else{
        top++;
        array[top]=n;
    }
    
}

void pop(){
    int m;
    if(top==-1){
        printf("\n THE STACK IS EMPTY");
    }
    else{
        m=array[top];
        printf("\n THE POPED ELEMENT IS %d" , m);
        top--;
    }
}

void display(){
    if(top==-1){
        printf("\n THE STACK IS EMPTY");
    }
    else{
        for(i=top;i>=0;i--){
            printf("\n%d",array[i]);
        }
    }
}

void main(){
    top=-1;
    int n,m;
    printf("\n ENTER THE SIZE OF THE STACK");
    scanf("%d",&size);
    do{
        printf(" \n ENTER 1 TO PUSH \n ENTER 2 TO POP \n ENTER 3 TO DISPLAY \n ENTER 4 TO EXIT");
        printf(" \n ENTER YOUR CHOICE");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: printf(" \n ENTER THE ELEMENT TO PUSH");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2: pop();
                    break;
            case 3: printf("\n THE STACK IS");
                    display();
                    break;
            case 4: printf(" \n THE PROGRAM HAS ENDED");
                    break;
            default:printf(" \n ENTER A CHOICE FROM (1,2,3,4)");
        }
    }
    while(choice!=4);
}
