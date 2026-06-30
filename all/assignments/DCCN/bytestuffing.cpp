#include <stdio.h>
#include <string.h>

int main() {
    char d[100], s[200];
    int j = 0;

    scanf("%s", d);

    s[j++] = 'F'; // start flag

    for (int i = 0; i < strlen(d); i++) {
        if (d[i] == 'F' || d[i] == 'E')
            s[j++] = 'E';
        s[j++] = d[i];
    }

    s[j++] = 'F'; // end flag
    s[j] = '\0';

    printf("%s", s);
}