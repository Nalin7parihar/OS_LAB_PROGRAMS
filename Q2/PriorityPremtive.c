#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int pid;            // Process ID
    int arrivalTime;    // Arrival time
    int burstTime;      // Burst time
    int remainingTime;  // Remaining burst time
    int priority;       // Priority (lower number indicates higher priority)
    int startTime;      // Start time
    int finishTime;     // Finish time
    int waitingTime;    // Waiting time
    int turnAroundTime; // Turnaround time
} Process;

void priorityPreemptiveScheduling(Process processes[], int n)
{
    int currentTime = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;
    printf("Gantt Chart:\n");

    while (completed != n)
    {
        int idx = -1;
        int highestPriority = INT_MAX;

        // Find the process with highest priority (lowest priority number)
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0)
            {
                if (processes[i].priority < highestPriority ||
                    (processes[i].priority == highestPriority && processes[i].arrivalTime < processes[idx].arrivalTime))
                {
                    highestPriority = processes[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            // Set start time if this is the first time the process runs
            if (processes[idx].remainingTime == processes[idx].burstTime)
            {
                processes[idx].startTime = currentTime;
            }

            // Execute the process for 1 time unit
            processes[idx].remainingTime--;
            currentTime++;

            // Check if process is completed
            if (processes[idx].remainingTime == 0)
            {
                processes[idx].finishTime = currentTime;
                processes[idx].turnAroundTime = processes[idx].finishTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnAroundTime - processes[idx].burstTime;

                totalWT += processes[idx].waitingTime;
                totalTAT += processes[idx].turnAroundTime;
                completed++;
            }

            printf("| (%d) P%d (%d) ", currentTime - 1, processes[idx].pid, currentTime);
        }
        else
        {
            // No process is ready, CPU is idle
            currentTime++;
            printf("| (%d) IDLE (%d) ", currentTime - 1, currentTime);
        }
    }
    printf("|\n\n");

    printf("Observation Table:\nPID\tAT\tBT\tPRI\tST\tFT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].priority, processes[i].startTime, processes[i].finishTime, processes[i].waitingTime, processes[i].turnAroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Enter Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].startTime = -1; // Initialize to -1 to indicate not started
        processes[i].finishTime = 0;
    }
    printf("\n");

    priorityPreemptiveScheduling(processes, n);

    free(processes);
    return 0;
}