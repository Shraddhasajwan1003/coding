#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, highest;
    int bt[20], rt[20], pr[20];
    int wt[20], tat[20], complete = 0;
    int min_pr = INT_MAX;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time and Priority:\n");
    for(i = 0; i < n; i++) {
        printf("P%d BT: ", i+1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i+1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];
    }

    while(complete != n) {
        highest = -1;
        min_pr = INT_MAX;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && pr[i] < min_pr) {
                min_pr = pr[i];
                highest = i;
            }
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0) {
            complete++;
            int finish_time = time;
            wt[highest] = finish_time - bt[highest];
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}