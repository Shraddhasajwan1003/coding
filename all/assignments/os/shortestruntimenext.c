#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, smallest;
    int bt[20], rt[20], wt[20], tat[20];
    int complete = 0, min;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    rt[9] = INT_MAX;

    while(complete != n) {
        smallest = 9;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && rt[i] < rt[smallest]) {
                smallest = i;
            }
        }

        rt[smallest]--;
        time++;

        if(rt[smallest] == 0) {
            complete++;
            wt[smallest] = time - bt[smallest];
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
