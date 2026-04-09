#include <stdio.h>
struct process
{
    int pid;
    int at;   // arrival time
    int bt;   // burst time
    int pr;   // priority (lower value = higher priority)
    int rt;   // remaining time
    int ct;   // completion time
    int wt;   // waiting time
    int tat;  // turnaround time
};
int main()
{
    int n, i, time = 0, completed = 0, highest;
    float total_wt = 0, total_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for(i = 0; i < n; i++) 
    {
        printf("\nEnter Arrival Time, Burst Time and Priority for P%d: ", i+1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].pid = i + 1;
        p[i].rt = p[i].bt;
    }
    while(completed != n)
    {
        highest = -1;
        int min_pr = 9999;
        for(i = 0; i < n; i++) 
        {
            if(p[i].at <= time && p[i].rt > 0)
            {
                if(p[i].pr < min_pr) {
                    min_pr = p[i].pr;
                    highest = i;
                }
            }
        }
        if(highest == -1)
        {
            time++;
        } else 
        {
            p[highest].rt--;
            time++;
            if(p[highest].rt == 0)
            {
                completed++;
                p[highest].ct = time;
                p[highest].tat = p[highest].ct - p[highest].at;
                p[highest].wt = p[highest].tat - p[highest].bt;

                total_wt += p[highest].wt;
                total_tat += p[highest].tat;
            }
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) 
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    return 0;
}
