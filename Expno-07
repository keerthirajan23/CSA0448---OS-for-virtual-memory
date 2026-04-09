#include <stdio.h>
struct Process 
{
    int pid;
    int bt;   // Burst Time
    int wt;   // Waiting Time
    int tat;  // Turnaround Time
};
int main()
{
    int n, i, j;
    struct Process p[10], temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
    }
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(p[j].bt > p[j + 1].bt) 
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    p[0].wt = 0;
    for(i = 1; i < n; i++) 
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }
    for(i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
    }
    float total_wt = 0, total_tat = 0;
    printf("\nPID\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}
