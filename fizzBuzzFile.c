#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: input file");
        exit(1);
    }

    FILE *f = fopen(argv[1], "r");
    if(f == NULL) {
        exit(1);
    }

    char buffer[1000];
    char *line = fgets(buffer, 1000, f);
    int n = atoi(buffer);
    int *numbers = (int *) malloc(sizeof(int) * n);
    for(int i=0; i<n; i++) {
        line = fgets(buffer, 1000, f);
        numbers[i] = atoi(line);

    }

    fclose(f);

    int huskerTotal = 0;
    int mavTotal = 0;
    for(int i=0; i<n; i++) {
        if(numbers[i] % 5 == 0 && numbers[i] % 3 == 0) {
            huskerTotal += numbers[i];
            mavTotal += numbers[i];
        } else if(numbers[i] % 3 == 0) {
            huskerTotal += numbers[i];
        } else if(numbers[i] % 5 == 0) {
            mavTotal += numbers[i];
        }
    }
    printf("  Husker total:     %d\n", huskerTotal);
    printf("  Mavericks total:        %d\n", mavTotal);


}

