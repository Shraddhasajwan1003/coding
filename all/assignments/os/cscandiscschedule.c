#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, pos, size, temp;
    int req[50], total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &pos);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // Sorting requests
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    int index;
    for(i = 0; i < n; i++) {
        if(pos < req[i]) {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d", pos);

    // Move towards higher end
    for(i = index; i < n; i++) {
        total += abs(pos - req[i]);
        pos = req[i];
        printf(" -> %d", pos);
    }

    // Move to end
    total += abs(pos - (size - 1));
    pos = size - 1;

    // Jump to beginning
    total += (size - 1);
    pos = 0;

    printf(" -> %d", pos);

    // Continue servicing
    for(i = 0; i < index; i++) {
        total += abs(pos - req[i]);
        pos = req[i];
        printf(" -> %d", pos);
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}