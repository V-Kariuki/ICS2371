#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct {
    int pid; // Process ID
    int priority; // Priority (Lower value indicates higher priority)
    int burst_time; // Burst time
} Process;

// Function to swap two processes
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Priority Scheduling without Preemption
void priorityScheduling(Process processes[], int n) {
    // Sort processes based on priority (higher priority first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    int total_time = 0;

    // Calculate completion time for each process
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        printf("Process %d completed at time %d\n", processes[i].pid, total_time);
    }
}

int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for array of processes
    Process *processes = (Process *)malloc(n * sizeof(Process));

    // Input process details
    printf("Enter details for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i].pid = i + 1;
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }

    // Perform Priority Scheduling without Preemption
    priorityScheduling(processes, n);

    // Free allocated memory
    free(processes);

    return 0;
}
