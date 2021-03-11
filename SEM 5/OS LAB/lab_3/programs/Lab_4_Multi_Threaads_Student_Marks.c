#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int total1 = 0, total2 = 0, temp;
int m1[5], m2[5];

void* function1(void* tid) {
  printf("Thread: %d Calculates Marks Of Student One\n", tid+1);
  for (size_t i = 0; i < 5; i++) {
    total1 += m1[i];
  }
  pthread_exit(NULL);
}

void* function2(void* tid) {
  printf("Thread: %d Calculates Marks Of Student Two\n", tid+1);
  for (size_t i = 0; i < 5; i++) {
    total2 += m2[i];
  }
  pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
  int status;
  void* exitstatus;
  pthread_t threads[3];
  printf("\n Student 1:-" );
  printf("\n\t Enter the marks: \n");
  for (size_t i = 0; i < 5; i++) {
    scanf("\t%d", &m1[i] );
  }
  printf("\nStudent 2:-" );
  printf("\n\t Enter the marks: \n");
  for (size_t i = 0; i < 5; i++) {
    scanf("\t%d", &m2[i] );
  }

  printf("\nSucessfully created Thread 1\n");
  status = pthread_create(&threads[0], NULL, function1, (void*)0);
  pthread_join(threads[0], &exitstatus);
  printf("Total Marks of student 1: %d\n",total1);

  printf("\n---Sucessfully created Thread 2---\n");
  status = pthread_create(&threads[1], NULL, function2, (void*)1);
  pthread_join(threads[1], &exitstatus);
  printf("Total Marks of student 2: %d\n\n",total2);

  printf("Main thread calcualatess highest marks\n" );
  if (total1==total2) {
    printf("Student 1 and Student 2 scored equal marks\n" );
  }
  else   if (total1 > total2) {
      printf("Student 1 Scored Higher marks than Student 2\n" );
      temp = total1;
      return temp;
  }
  else   if (total1 < total2) {
      printf("Student 2 Scored Higher marks than Student 1\n" );
      temp = total2;
      return temp;
  }

  return 0;
}
