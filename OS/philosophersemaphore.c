#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_PHILOSOPHERS 5

sem_t chopstick[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
  int id = *((int *)arg);
  int left_chopstick = id;
  int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;

  while (1) {
    // Think for a while
    printf("Philosopher %d thinking...\n", id);
    sleep(1);

    // Try to pick up left chopstick
    sem_wait(&chopstick[left_chopstick]);

    // Try to pick up right chopstick
    if (sem_trywait(&chopstick[right_chopstick]) == 0) {
      // Eat
      printf("Philosopher %d eating...\n", id);
      sleep(1);

      // Release chopsticks
      sem_post(&chopstick[right_chopstick]);
      sem_post(&chopstick[left_chopstick]);
    } else {
      // Couldn't get right chopstick, release left
      sem_post(&chopstick[left_chopstick]);
    }
  }
  return NULL;
}

int main() {
  int i;
  pthread_t threads[NUM_PHILOSOPHERS];

  // Initialize semaphores
  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    sem_init(&chopstick[i], 0, 1);
  }

  // Create philosopher threads
  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    int *id = malloc(sizeof(int));
    *id = i;
    pthread_create(&threads[i], NULL, philosopher, id);
  }

  // Wait for all threads to finish
  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy semaphores
  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    sem_destroy(&chopstick[i]);
  }

  return 0;
}
