#include<stdio.h>
#include<stdlib.h>

struct poly{
    int coef;
    int expo;
}p1[10],p2[10],p3[10];

int read_poly(struct poly p[10]){
    int i,t1;
    printf("\n ENTER THE NUMBER OF TERMS OF POLYNOMIAL");
    scanf("%d",&t1);
    for(i=0;i<t1;i++){
        printf("\n ENTER THE COEFFICIENT %d",i+1);
        scanf("%d",&p[i].coef);
        printf("\n ENTER THE EXPONENT %d",i+1);
        scanf("%d",&p[i].expo);
        
    }
    return(t1);
}

void display_poly(struct poly p[10],int t){
    int i;
    for(i=0;i<t-1;i++){
        printf("%dx^%d+ ",p[i].coef,p[i].expo);
    }
    printf("%dx^%d",p[t-1].coef,p[t-1].expo);
}

int add_poly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10]){
    int i=0,j=0,k=0;
    while(i<t1 && j<t2){
        if(p1[i].expo==p2[j].expo){
            p3[k].coef=p1[i].coef+p2[j].coef;
            p3[k].expo=p1[i].expo;
            i++;
            j++;
            k++;
        }
        
        else if(p1[i].expo>p2[j].expo){
            p3[k].coef=p1[i].coef;
            p3[k].expo=p1[i].expo;
            i++;
            k++;
        }
        
        else{
            p3[k].coef=p2[j].coef;
            p3[k].expo=p2[j].expo;
            j++;
            k++;
        }
    }
        
    if(i<t1){
        p3[k].coef=p1[i].coef;
        p3[k].expo=p1[i].expo;
        i++;
        k++; 
    }
    else{
        p3[k].coef=p2[j].coef;
            p3[k].expo=p2[j].expo;
            j++;
            k++;    
    }
return(k);
    
    
}

void main(){
    int t1,t2,t3;
    t1=read_poly(p1);
    printf("\n FIRST POLUNOMIAL IS ");
    display_poly(p1,t1);

    t2=read_poly(p2);
    printf("\n SECOND POLUNOMIAL IS ");
    display_poly(p2,t2);
    
    t3=add_poly(p1,p2,t1,t2,p3);
    printf("\n RESULTANT POLYNOMIAL IS ");
    display_poly(p3,t3);
    
}
