#include<stdio.h>
#include<stdlib.h>
void main(){
int size,i,key,flag=0;
printf("ENTER THE SIZE OF THE ARRAY");
scanf("%d",&size);
int array[size];
printf("\nENTER ARRAY ELEMENTS");
for(i=0;i<size;i++){
    scanf("%d",&array[i]);
}
printf("\nTHE ENTERED ARRAY IS ");
for(i=0;i<size;i++){
    printf("\t%d",array[i]);
}
printf("ENTER THE ELEMENT TO BE SEARCHED");
scanf("%d",&key);
for(i=0;i<size;i++){
    if(array[i]==key){
        flag=1;
        break;
    }
}
if(flag==1){
    printf("ELEMENT FOUNT AT INDEX %d",i);
}
else{
    printf("SEARCH ELEMENT NOT FOUND");
}
} 
