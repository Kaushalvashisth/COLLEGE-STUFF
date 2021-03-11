#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int i,j,x[12],y[12];
   int dist,a[99][99],r;
   for(i=1;i<=10;i++)
   {
       x[i] = rand() % 10+1;
       y[i] = rand() % 50+1;
       printf("\n x and y co-ordinates of node %d are: %d and %d \t",i,x[i],y[i]);
   } 
   printf("\n\n\t\t<--------- THE DISTANCE TABLE IS:--------->\n\n");
   for (size_t i = 1; i < 11; i++)
   {
       printf("\tNode %d:", i);   
   } 
   printf("\n");
   for(i=1;i<=10;i++)
   {
    //    printf("%d \t",i);
       printf("Node %d: ", i);   
       for(j=1;j<=10;j++)
       {
           dist = sqrt((pow((x[j]-x[i]),2))+ pow((y[j]-y[i]),2));
           printf("  %d \t", dist);
       }
       printf("\n");
   }
   printf("\n ENTER THE RANGE TO BE CONSIDERED AS NEIGHBOUR:");
   scanf("%d",&r);
   
   for(i=1;i<=10;i++)
   {
    //    printf("\n neighbours of %d node are : ", i);
       printf("\n NEIGHBOURS OF %d NODE ARE: ", i);
       for(j=1;j<=10;j++)
       {
           if(i!=j){
           dist = sqrt((pow((x[j]-x[i]),2))+pow((y[j]-y[i]),2));
           if(dist < r)
               
           {
             printf("%4d", j);
           }
        }
       }
   }
}