#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct {
    int pid; // Process ID
    int priority; // Priority (Lower value indicates higher priority)
    int burst_time; // Burst time
    int remaining_time; // Remaining burst time
} Process;

// Function to swap two processes
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Priority Scheduling with Preemption
void priorityScheduling(Process processes[], int n) {
    int total_time = 0;
    int completed = 0;

    // Calculate total burst time
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Priority Scheduling with Preemption
    while (completed < n) {
        int highest_priority = -1;
        int selected_process = -1;

        // Select process with highest priority
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].priority > highest_priority) {
                highest_priority = processes[i].priority;
                selected_process = i;
            }
        }

        // Decrement remaining time of selected process
        processes[selected_process].remaining_time--;

        // Check if process is completed
        if (processes[selected_process].remaining_time == 0) {
            completed++;
            printf("Process %d completed at time %d\n", processes[selected_process].pid, total_time);
        }

        total_time++;
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

    // Perform Priority Scheduling with Preemption
    priorityScheduling(processes, n);

    // Free allocated memory
    free(processes);

    return 0;
}
