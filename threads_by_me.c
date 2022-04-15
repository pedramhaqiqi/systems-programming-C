#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 100000000

int *array_ints;
int *sum_arr;


//struct for thread arg
typedef struct thread_arg{
    int tid;
    double stuff;
}thr_arg;

void func(void* arg){
    thr_arg *data = (thr_arg *) arg;
    printf("hello from thr_func, thread id: %d\n", data->tid);
    sum_arr[data->tid]=0;
    int thread_part = ARRAY_SIZE/NUM_THREADS;
    for(int i=data->tid * thread_part,j=0; j<thread_part; i++,j++)
         sum_arr[data->tid] += array_ints[i];
    printf("The sum calculated by thread %d was %ld\n", data->tid, sum_arr[data->tid]);
    pthread_exit(NULL);
}



int main(int argc, char** argv){
    long total;

    pthread_t thr_arry[NUM_THREADS];
    thr_arg thr_arg[NUM_THREADS];
    
    array_ints = malloc(ARRAY_SIZE * sizeof(int));
    sum_arr = malloc(NUM_THREADS * sizeof(long));

    for(int i = 0; i < ARRAY_SIZE ; i++){
        array_ints[i] = rand() % 100;
    }


    for(int i = 0;i<NUM_THREADS;i++){
        thr_arg[i].tid = i;
        pthread_create(&thr_arry[i], NULL, func, &thr_arg[i]);
    }

    for(int i = 0; i<NUM_THREADS;i++){
        pthread_join(thr_arry[i], NULL);
        
    }

    for (int i = 0; i < NUM_THREADS; ++i)
          total += sum_arr[i];
  printf("\nTotal sum is: %ld\n",total);
  return EXIT_SUCCESS;



}