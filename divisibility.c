#include <stdio.h>
#include <stdlib.h>

#define START 2
#define END   13

int digitCount(int num) {

    int count = 0;

    while (num != 0) {
        num /= 10;
        count++;
    }

    return count;
}

int highestLength(int *nums, int numLen) {

    int highest = digitCount(nums[0]);
    int currentLen = 0;

    for(int i=1; i<numLen; i++) {
        currentLen = digitCount(nums[i]);
        if(currentLen >= highest)
            highest = currentLen;
    }

    return highest;
}

void spacePrinter(int num) {
    for(int i=0; i<num; i++) {
        printf(" ");
    }
}

void firstRow(int highestLen) {
    spacePrinter(highestLen);

    for(int i=START; i<END; i++) {
        printf("| %d ", i);
    }
}

void bottomOfARow(int highestLen) {

    printf("\n");

    spacePrinter(highestLen);

    for(int i=START; i<END; i++) {
        if(digitCount(i) > 1)
            printf("+----");
        else
            printf("+---");
    }

    printf("\n");
}

char isDivisible(int dividend, int divisor) {
    if(dividend % divisor == 0) 
        return 'O';
    return ' ';
}

void mainPrinter(int *nums, int numLen, int highestLen) {

    for(int i=0; i<numLen; i++) {

        int currLen = digitCount(nums[i]);
        int reqLen = highestLen - currLen;

        spacePrinter(reqLen-1);

        printf("%d ", nums[i]);

        for(int j=START; j<END; j++) {
            if(digitCount(j) > 1)
                printf("|  %c ", isDivisible(nums[i], j));
            else
                printf("| %c ", isDivisible(nums[i], j));
        }

        bottomOfARow(highestLen);
    }
}


int main(int argc, char *argv[]) {

    int numLen = argc - 1;
    int nums[numLen];

    if(argc < 2) {
        printf("Please some values like 24 54 82\n");
        return 1;
    }
    
    for(int i=1; i<argc; i++)
        nums[i-1] = atoi(argv[i]);

    int highestLen = highestLength(nums, numLen) + 1;

    firstRow(highestLen);
    bottomOfARow(highestLen);
    mainPrinter(nums, numLen, highestLen);

    return 0;

}
