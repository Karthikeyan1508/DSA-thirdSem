// 2b --> Write a program to implement Insertion Sort

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main(){
    int a[20],n,k,i,j;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        k=a[i];
        for(j=i-1;j>=0 && k<a[j]; j--){
            a[j+1]=a[j];
        }
        a[j+1]=k;
    }
    printf("After Sorting: \n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    getch();
}
