// C program for implementation of FCFS 
// scheduling 
#include <stdio.h> 	
//Function to calculate average time 
void findavgTime( int prs[], int n, int bt[]) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	// waiting time for first process is 0 
	wt[0] = 0; 
	// calculating waiting time 
	for (int i = 1; i < n ; i++ ) {
		wt[i] = bt[i-1] + wt[i-1] ;
    }

    // calculating tat
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++){ 
		tat[i] = bt[i] + wt[i]; 
    }
	//Display processes along with all details 
	printf("Prs.\tBt\tWt\tTAT \n"); 
	
	// Calculate total wt and total tat 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		printf(" %d ",(i+1)); 
		printf("\t%d ", bt[i] ); 
		printf("\t%d",wt[i] ); 
		printf("\t%d\n",tat[i] ); 
	} 
	float s=(float)total_wt / (float)n; 
	float t=(float)total_tat / (float)n; 
	printf("Average waiting time = %0.3f",s); 
	printf("\n"); 
	printf("Average turn around time = %0.3f ",t); 
} 
	
// Driver code 
int main() 
{
	int n;
    printf("Enter no of processes:-");
    scanf("%d",&n);
	//process id's 
	int processes[n];
	int burst_time[n]; 
    printf("Enter burst times:- \n");
	for (size_t i = 0; i < n; i++)
    {
        processes[i]=i;
        scanf(" %d",&burst_time[i]);
    }
    
	findavgTime(processes, n, burst_time); 
	return 0; 
} 
