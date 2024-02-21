#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
typedef struct process {
    int pid;           // Process ID
    int arrival_time;  // Arrival time
    int burst_time;   // Burst time
    int waiting_time;  // Waiting time (calculated later)
    int turnaround_time; // Turnaround time (calculated later)
} process;

// Function to swap two processes
void swap(process *a, process *b) {
    process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort processes by burst time
int compareBurst(const void *a, const void *b) {
    const process *p1 = (const process *)a;
    const process *p2 = (const process *)b;
    return p1->burst_time - p2->burst_time;
}

// Function to calculate waiting and turnaround times
void calculateTimes(process processes[], int n) {
    int curr_time = 0, completed = 0;
    int wait_time[n], turnaround_time[n];

    // Sort processes by burst time (non-preemptive SJF)
    qsort(processes, n, sizeof(process), compareBurst);

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            wait_time[i] = curr_time - processes[i].arrival_time;
        } else {
            wait_time[i] = 0;
        }
        curr_time += processes[i].burst_time;
        turnaround_time[i] = curr_time - processes[i].arrival_time;
    }

    // Print results
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, wait_time[i], turnaround_time[i]);
    }

    // Calculate average waiting and turnaround times
    float avg_wait_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("Average Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process processes[n];

    printf("Enter details for each process (PID, arrival_time, burst_time):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    calculateTimes(processes, n);

    return 0;
}