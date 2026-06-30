#include <stdio.h>

int main() {
    int frames[10], pages[50];
    int n, f, i, j, k, pos, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            int farthest = i, index = -1;

            for(j = 0; j < f; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }

                if(k == n) {
                    index = j;
                    break;
                }
            }

            if(index == -1)
                index = 0;

            frames[index] = pages[i];
            faults++;
        }

        printf("\nFrame status: ");
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}