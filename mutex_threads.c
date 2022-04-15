#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 2500
#define ARRAY_SIZE 10000000
int *array_ints;
long *sum;
long wrong_sum; //Global variable that would generate the wrong sum without 

pthread_mutex_t sum_lock;

/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;

/* thread function */
void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
  printf("hello from thr_func, thread id: %d\n", data->tid);
  sum[data->tid]=0;
  int thread_part = ARRAY_SIZE/NUM_THREADS;
  for(int i=data->tid * thread_part,j=0; j<thread_part; i++,j++) {
          sum[data->tid] += array_ints[i];
              pthread_mutex_lock(&sum_lock);
          wrong_sum += array_ints[i];
              pthread_mutex_unlock(&sum_lock);
  }
  printf("The sum calculated by thread %d was %ld\n", data->tid, sum[data->tid]);
  pthread_exit(NULL);
}
int main(int argc, char **argv) {
  pthread_t thr[NUM_THREADS];
  int i, rc;
  /* create a thread_data_t argument array */
  thread_data_t thr_data[NUM_THREADS];
  array_ints = malloc(ARRAY_SIZE * sizeof(int));
  for(int i=0; i<ARRAY_SIZE; i++)
         array_ints[i] = rand()%100;
  sum = malloc(NUM_THREADS * sizeof(long));
  long total_sum=0;
    if (pthread_mutex_init(&sum_lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
  /* create threads */
 for (i = 0; i < NUM_THREADS; ++i) {
    thr_data[i].tid = i;
    if ((rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]))) {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
    }
  }
  /* block until all threads complete */
  for (i = 0; i < NUM_THREADS; ++i) {
    pthread_join(thr[i], NULL);
  }
    pthread_mutex_destroy(&sum_lock);
  for (i = 0; i < NUM_THREADS; ++i)
          total_sum += sum[i];
  printf("\nTotal sum is: %ld\n",total_sum);
  printf("\nTotal wrong sum is: %ld\n",wrong_sum);
  return EXIT_SUCCESS;
}