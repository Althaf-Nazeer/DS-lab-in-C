#include<stdio.h>
#include<stdlib.h>
void main(){
int size,i,key,flag=0,low,mid,high;
printf("ENTER THE SIZE OF THE ARRAY  ");
scanf("%d",&size);
int array[size];
printf("\nENTER ARRAY ELEMENTS  ");
for(i=0;i<size;i++){
    scanf("%d",&array[i]);
}
printf("\nTHE ENTERED ARRAY IS ");
for(i=0;i<size;i++){
    printf("\t%d",array[i]);
}
printf("\nENTER THE ELEMENT TO BE SEARCHED  ");
scanf("%d",&key);
low=0;
high=size-1;
while (low<=high){
    mid=(low+high)/2;
    if (array[mid]==key){
        flag=1;
        break;
    }
    else if(array[mid]>key){
        high=mid-1;
    }
    else{
        low=mid+1;
    }
}

if(flag==1){
    printf("ELEMENT FOUNT AT INDEX %d",mid);
}
else{
    printf("SEARCH ELEMENT NOT FOUND");
}
} 
