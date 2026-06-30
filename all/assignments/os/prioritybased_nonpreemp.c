#include <stdio.h>

int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], pr[20], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time and Priority:\n");
    for(i = 0; i < n; i++) {
        printf("P%d BT: ", i+1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i+1);
        scanf("%d", &pr[i]);
    }

    // Sorting based on priority (lower value = higher priority)
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                // swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // swap burst time accordingly
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
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