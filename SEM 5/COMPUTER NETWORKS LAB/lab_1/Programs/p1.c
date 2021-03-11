#include <stdio.h>
#include <stdlib.h>
int countOnes(int arr[],int n){
    int count;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==1)count++;
    }
    return count;
}

int main() {
    int n,choice;
    printf("Enter number of bits: ");
    scanf(" %d",&n);

    int arr[n];
    printf("Enter Bits:- \n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %d",&arr[i]);
    };
    printf("\n Choose Parity:- \n 1. Even Parity \n 2. Odd Parity \n");

    printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:arr[n]=(countOnes(arr,n)%2==0)?0:1;
        break;
    case 2:arr[n]=(countOnes(arr,n)%2==0)?1:0;
        break;
    default:printf("Enter valid choice \n");
        break;
    }
    
    printf("Parity is : %d \n" ,arr[n]);
    printf("Parity bits are : \n");
    for (int j = 0; j <=n; j++)
    {
        printf("%d ",arr[j]);
    }
    

    return 0;
}