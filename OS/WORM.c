#include <stdio.h>
#include <pthread.h>

#define MAX_READERS 10

int data = 0; // Shared data
int reader_count = 0; // Number of currently reading readers
pthread_mutex_t writer_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for writer access

void *reader_thread(void *arg) {
  int my_id = *(int *)arg;
  pthread_mutex_lock(&writer_mutex); // Acquire writer mutex for reader count update
  reader_count++;
  if (reader_count == 1) {
    // First reader acquires the mutex for write protection
    printf("Reader %d acquired mutex...\n", my_id);
  }
  pthread_mutex_unlock(&writer_mutex); // Release writer mutex

  // Read the shared data (simulated by a sleep)
  printf("Reader %d reading data: %d\n", my_id, data);
  sleep(1);

  pthread_mutex_lock(&writer_mutex); // Acquire writer mutex for reader count update
  reader_count--;
  if (reader_count == 0) {
    // Last reader releases the mutex
    printf("Reader %d released mutex...\n", my_id);
  }
  pthread_mutex_unlock(&writer_mutex); // Release writer mutex

  return NULL;
}

void *writer_thread(void *arg) {
  pthread_mutex_lock(&writer_mutex); // Acquire writer mutex for exclusive access

  // Modify the shared data (simulated by an increment)
  data++;
  printf("Writer modified data: %d\n", data);

  pthread_mutex_unlock(&writer_mutex); // Release writer mutex

  return NULL;
}

int main() {
  int i;
  pthread_t reader_threads[MAX_READERS], writer_thread;

  // Create reader threads
  for (i = 0; i < MAX_READERS; i++) {
    int *id = malloc(sizeof(int));
    *id = i;
    pthread_create(&reader_threads[i], NULL, reader_thread, id);
  }

  // Create writer thread
  pthread_create(&writer_thread, NULL, writer_thread, NULL);

  // Wait for all threads to finish
  for (i = 0; i < MAX_READERS; i++) {
    pthread_join(reader_threads[i], NULL);
  }
  pthread_join(writer_thread, NULL);

  pthread_mutex_destroy(&writer_mutex);
  return 0;
}
