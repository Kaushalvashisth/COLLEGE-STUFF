#include <stdio.h>
#include <stdlib.h>
int countOnes(int arr[],int n){
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==1)count++;
    }
    return count;
}
int main() {
    int n,choice; 
    printf("Enter Data Size: ");
    scanf("%d",&n);

    int arr[n+1][n+1];
    printf("Enter Bits:- \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %d",&arr[i][j]);
        }
    };
    printf("\nChoose Parity:- \n\t\t1)Even Parity\n\t\t2)Odd Parity\n");

    printf("Enter choice: ");
    scanf("%d",&choice);
    // check number of ones accordingly
    int i,j;
    for (i = 0; i < n; i++)
    {
        int temp[n];// temp array for rows
        int temp2[n];// temp array for columns
        for (j = 0; j < n; j++)
        {
            temp[j]=arr[i][j];
            temp2[j]=arr[j][i];
        }
        switch (choice)
        {
        case 1:arr[i][n]=(countOnes(temp,n)%2==0)?0:1;// horizontal check
               arr[n][i]=(countOnes(temp2,n)%2==0)?0:1;// vertical check
            break;
        case 2:arr[i][n]=(countOnes(temp,n)%2==0)?1:0;// horizontal check
               arr[n][i]=(countOnes(temp2,n)%2==0)?1:0;// vertical check
            break;
        default:printf("Enter valid choice \n");
            break;
        }    
    }
    arr[n][n]=2;
    //display  
    printf("\nParity bits are : \n");
     for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            printf(" %d",arr[i][j]);
        }
        printf("\n");
        
    };
    return 0;
}