#include <stdio.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5

void *philosopher(void *arg) {
  int id = *((int *)arg);
  int left_chopstick = id;
  int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;

  while (1) {
    // Think for a while
    printf("Philosopher %d thinking...\n", id);
    sleep(1);

    // Pick up left chopstick based on odd/even ordering
    if (is_odd(id)) {
      printf("Philosopher %d picked up left chopstick...\n", id);
    } else {
      printf("Philosopher %d waiting for left chopstick...\n", id);
      while (is_odd(id) && someone_holds_right_chopstick(right_chopstick)) {
        // Wait if even and someone already holds right chopstick
        printf("Philosopher %d waiting because someone holds right chopstick...\n", id);
        sleep(1);
      }
    }

    // Pick up right chopstick
    printf("Philosopher %d picked up right chopstick...\n", id);

    // Eat
    printf("Philosopher %d eating...\n", id);
    sleep(1);

    // Release chopsticks
    printf("Philosopher %d released chopsticks...\n", id);
  }
  return NULL;
}

// Helper functions
int is_odd(int id) {
  return id % 2 == 1;
}

int someone_holds_right_chopstick(int chopstick) {
  // Implement logic to check if someone holds the right chopstick (can be mutex state or flag)
  // This is a simplified example and needs adaptation
  return 0; // Replace with your actual checking logic
}

int main() {
  int i;
  pthread_t threads[NUM_PHILOSOPHERS];

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

  return 0;
}
