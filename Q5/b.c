#include <stdio.h>
#include <stdlib.h>

typedef struct
{
        int pid;
        int AT;
        int BT;
        int CT;
        int TAT;
        int WT;
        int RT;
} process;

void fcfs(process p[], int n)
{
        int et = p[0].AT, totW = 0, totT = 0, totR = 0;
        float avgW = 0, avgT = 0, avgR = 0;
        printf("\nGant chart:\n");
        for (int i = 0; i < n; i++)
        {
                if (et < p[i].AT)
                        et = p[i].AT;
                p[i].RT = et - p[i].AT; // Response time = Start time - Arrival time
                p[i].WT = et - p[i].AT;
                et += p[i].BT;
                p[i].TAT = et - p[i].AT;
                p[i].CT = et;
                printf("|(%d) P%d (%d)", et - p[i].BT, p[i].pid, et);
        }
        printf("\n");
        printf("Observation Table\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
        for (int i = 0; i < n; i++)
        {
                process t = p[i];
                printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\n", t.pid, t.AT, t.BT, t.CT, t.TAT, t.WT, t.RT);
                totT += t.TAT;
                totW += t.WT;
                totR += t.RT;
        }
        avgT = (float)totT / n;
        avgW = (float)totW / n;
        avgR = (float)totR / n;
        printf("\nAverage waiting time: %.2f\n", avgW);
        printf("Average turn around time: %.2f\n", avgT);
        printf("Average response time: %.2f\n", avgR);
}

int main()
{
        int n;
        printf("Enter the number of processes: ");
        scanf("%d", &n);
        process *processes = (process *)malloc(n * sizeof(process));
        for (int i = 0; i < n; i++)
        {
                printf("\nProcess %d\n", i + 1);
                printf("Enter arrival time: ");
                scanf("%d", &processes[i].AT);
                printf("Enter burst time: ");
                scanf("%d", &processes[i].BT);
                processes[i].pid = i + 1;
                printf("\n");
        }
        for (int i = 0; i < n - 1; i++)
        {
                for (int j = 0; j < n - i - 1; j++)
                {
                        if (processes[j].AT > processes[j + 1].AT)
                        {
                                process temp = processes[j];
                                processes[j] = processes[j + 1];
                                processes[j + 1] = temp;
                        }
                }
        }
        fcfs(processes, n);
        free(processes);
        return 0;
}