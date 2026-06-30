#include <stdio.h>

int main() {
    int frames, pages, i, j, k = 0, page_faults = 0;
    int ref[50], frame[10];

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < pages; i++) {
        int found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[k] = ref[i];
            k = (k + 1) % frames;
            page_faults++;
        }

        printf("\nFrame status: ");
        for(j = 0; j < frames; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", page_faults);

    return 0;
}