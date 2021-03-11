#include <stdio.h>
#include <stdlib.h> 

// q create 5 processes and write there child pid parent ppid
// this method will also do the same job:-
void method2(){
    // 1 main process
    printf("child pid = %d from parent pid =%d \n",getpid(),getppid());
    // creating 4 process from 1 same parent
    for (int i = 0; i < 4; i++)// 4 processes
    {
        if(fork()==0){
            printf("child pid = %d from parent pid =%d \n",getpid(),getppid());
            exit(0);
        }
    }
}


 int main(int argc,char** argv) {
    int pid,a,status;
    pid=fork();
    if(pid==0)
    {
        pid=fork();
        if(pid==0)
        {
            pid=fork();
            if(pid==0)
            {
                pid==fork();
            }
        }
    }

    printf("\n process id: %d parent id: %d \n",getpid(),getppid());
    waitpid(-1,&status,0);
    return (EXIT_SUCCESS);
}