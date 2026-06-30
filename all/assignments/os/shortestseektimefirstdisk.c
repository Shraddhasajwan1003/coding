#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, pos, total = 0;
    int req[50], visited[50] = {0};

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &pos);

    printf("\nSeek Sequence: %d", pos);

    for(i = 0; i < n; i++) {
        int min = 9999, index = -1;

        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(pos - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        total += min;
        pos = req[index];
        visited[index] = 1;

        printf(" -> %d", pos);
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}