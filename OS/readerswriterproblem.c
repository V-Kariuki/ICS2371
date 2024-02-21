#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
sem_t mutex, writeBlock;
int data = 0, readerCount = 0;

void *readerFunc(void *arg) {
    int id = *((int*)arg);
    while (1) {
        // Reader enters critical section
        sem_wait(&mutex);
        readerCount++;
        if (readerCount == 1) {
            // First reader blocks writers
            sem_wait(&writeBlock);
        }
        sem_post(&mutex);

        // Read data
        printf("Reader %d reads data: %d\n", id, data);
        sleep(1);

        // Reader exits critical section
        sem_wait(&mutex);
        readerCount--;
        if (readerCount == 0) {
            // Last reader unblocks writers
            sem_post(&writeBlock);
        }
        sem_post(&mutex);

        sleep(2); // Reader resting
    }
    return NULL;
}

void *writerFunc(void *arg) {
    int id = *((int*)arg);
    while (1) {
        // Writer enters critical section
        sem_wait(&writeBlock);

        // Write data
        data++;
        printf("Writer %d writes data: %d\n", id, data);
        sleep(2);

        // Writer exits critical section
        sem_post(&writeBlock);

        sleep(3); // Writer resting
    }
    return NULL;
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&writeBlock, 0, 1);

    int i;
    int readerIds[NUM_READERS];
    int writerIds[NUM_WRITERS];

    for (i = 0; i < NUM_READERS; i++) {
        readerIds[i] = i;
        pthread_create(&readers[i], NULL, readerFunc, &readerIds[i]);
    }

    for (i = 0; i < NUM_WRITERS; i++) {
        writerIds[i] = i;
        pthread_create(&writers[i], NULL, writerFunc, &writerIds[i]);
    }

    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&writeBlock);

    return 0;
}
