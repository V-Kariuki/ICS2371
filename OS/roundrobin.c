#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
typedef struct process {
    int pid;           // Process ID
    int arrival_time;  // Arrival time
    int burst_time;   // Burst time
    int remaining_time; // Remaining burst time (for preemption)
    int waiting_time;  // Waiting time (calculated later)
    int turnaround_time; // Turnaround time (calculated later)
} process;

// Function to calculate waiting and turnaround times
void calculateTimes(process processes[], int n, int quantum) {
    int curr_time = 0, completed = 0;
    int wait_time[n], turnaround_time[n];

    // Copy burst times to remaining times for preemption
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Round Robin scheduling loop
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= curr_time && processes[i].remaining_time > 0) {
                // Execute process for quantum time or remaining time
                int time_used = processes[i].remaining_time > quantum ? quantum : processes[i].remaining_time;
                processes[i].remaining_time -= time_used;
                curr_time += time_used;

                // Check if process completed
                if (processes[i].remaining_time == 0) {
                    turnaround_time[i] = curr_time - processes[i].arrival_time;
                    wait_time[i] = turnaround_time[i] - processes[i].burst_time;
                    completed++;
                }
            }
        }
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
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process processes[n];

    printf("Enter details for each process (PID, arrival_time, burst_time):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    calculateTimes(processes, n, quantum);

    return 0;
}
