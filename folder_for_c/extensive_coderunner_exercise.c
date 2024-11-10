#include <stdio.h>
#include <stdlib.h>

//Project still in development!

int error_stat(double *p) { //Checks if input is lower or equal to 0. If so, function quits.
    if (*p <= 0) {
        return 1;
    }
    return 0;
}
void count(double *p, double arraySize[256], int *indexCounter) { //Adds each input into each index. After that it increments the index by one.
    arraySize[*indexCounter] = *p;
    (*indexCounter)++;
}

int array_branch(int *i, double arraySize[256], int *indexCounter) { //If index is equal to 0 (no input), statement pops up.
        if (*indexCounter == 0) {
        printf("no numbers entered\n");
        return 1;
    } else {
        for (int i = 0; i < *indexCounter; (i)++) { //Otherwise, save each element respectively.
            if (arraySize[i] - (int) arraySize[i] == 0) { 
                printf("%.0lf\n", arraySize[i]);
            } else {
                printf("%.1lf\n", arraySize[i]);
            }
        }  
    }
    return 0;
}
   

void array_addition(double arraySize[256], int *indexCounter) { //Function adds all elements together and divides by amount of inputs.
    double overall_sum = 0;
    for (int i = 0; i < *indexCounter; i++) {
        overall_sum += arraySize[i];
        }
        printf("Average area: %.1lf\n", overall_sum / *indexCounter);
    }

int main() {
    double arraySize[256];
    int indexCounter = 0;
    double p;
    int j;
    int *i = &j;
    double overall_sum;
    while (1) { //Infinite loop
        scanf(" %lf", &p);
        if (error_stat(&p)) { //If function returns 1, branch continues.
            array_branch(i, arraySize, &indexCounter); //Continue with this function.
            array_addition(arraySize, &indexCounter); //Then continue with this function.
            printf(": count: %d\n", indexCounter); //In the end, once the process is finished, print out this statement (once returned 1).
            break; //Finally, break the loop.
        } else {
            count(&p, arraySize, &indexCounter); //While error_stat is 0, count will be repeated.
        } 
    }
    return 0;
}
