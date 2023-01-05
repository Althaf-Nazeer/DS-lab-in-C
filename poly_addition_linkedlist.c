#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
    int expo;
    struct node *link;
};

struct node *phead,*qhead,*rhead;

struct node * read_poly(){
    struct node *new,*ptr,*head=NULL;
    int n,i;
    printf("\nENTER THE NUMBER OF TERMS IN THE POLYNOMIAL");
    scanf("%d",&n);
    
    printf("\nENTER THE COEFFICIENTS AND EXPONENTS");
    for(i=1;i<=n;i++){
        printf("ENTER (COEFFICIENT %d , EXPONENT %d)",i,i);
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&new->coef);
        scanf("%d",&new->expo);
        new->link=NULL;
        if(head==NULL){
            head=new;
            ptr=head;
        }
        else{
            ptr->link=new;
            ptr=new;
        }
        
    }
    return(head);
}

void display_poly(struct node *head){
    struct node *ptr;
    ptr=head;
    if (head==NULL){
        printf("THE POLYNOMIAL IS EMPTY");
    }
    else{
        while(ptr->link!=NULL){
            printf("%dx^%d + ",ptr->coef,ptr->expo);
            ptr=ptr->link;
        }
        printf("%dx^%d ",ptr->coef,ptr->expo);
    }
}

struct node * add_poly(){
    struct node *p,*q,*r,*new,*head=NULL;
    p=phead;
    q=qhead;
    while(p!=NULL && q!=NULL){
        if(p->expo==q->expo){
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=p->coef+q->coef;
            new->expo=p->expo;
            p=p->link;
            q=q->link;
            new->link=NULL;
        }
        else if(p->expo>q->expo){
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=p->coef;
            new->expo=p->expo;
            new->link=NULL;
            p=p->link;
        }
        else{
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=q->coef;
            new->expo=q->expo;
            new->link=NULL;
            q=q->link;
        }
        if(head==NULL){
            head=new;
            r=head;
        }
        else{
            r->link=new;
            r=new;
        }
    }
    while(p!=NULL){
        new=(struct node *)malloc(sizeof(struct node));
        new->coef=p->coef;
        new->expo=p->expo;
        new->link=NULL;
        
        if(head==NULL){
            head=new;
            r=head;
        }
        else{
            r->link=new;
            r=new;
        }
        p=p->link;
    }
    
    while(q!=NULL){
        new=(struct node *)malloc(sizeof(struct node));
        new->coef=q->coef;
        new->expo=q->expo;
        new->link=NULL;
            
        
        if(head==NULL){
            head=new;
            r=head;
        }
        else{
            r->link=new;
            r=new;
        }
        q=q->link;
    }
    return(head);
}

void main(){
    int n,m;
    printf("\nENTER THE DETAILS OF FIRST POLYNOMIAL");
    phead=read_poly();
    
    printf("\nENTER THE DETAILS OF SECOND POLYNOMIAL");
    qhead=read_poly();
    
    printf("\nTHE FIRST POLYNOMIAL IS");
    display_poly(phead);
    
    printf("\nTHE SECOND POLYNOMIAL IS");
    display_poly(qhead);
    
    rhead=add_poly();
    printf("\nTHE RESULTANT POLYNOMIAL IS");
    display_poly(rhead);
    
}
