#include<stdio.h>
#include<conio.h>

tower(int n,char source, char dest, char temp){
    if(n>0){
        tower(n-1,source,temp,dest);
        printf("Move disks %d from %c to %c\n",n,source,dest);
        tower(n-1,temp,dest,source);
    }
    return;
}
void main(){
    int n;
    printf("Enter the number of Disks: ");
    scanf("%d",&n);
    tower(n,'s','d','t');
    getch();
}

