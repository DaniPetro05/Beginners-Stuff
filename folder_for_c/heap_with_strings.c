#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_CHAR 100

int food() {
    char *memtoch = (char *)malloc(MAX_LENGTH_CHAR * sizeof(char)); //Memory allocated to an array of characters; malloc stored in memtoch pointer
    const char *food_options[] = {"pizza", "burger", "sushi", "chocolate"};
    int main_options = sizeof(food_options) / sizeof(food_options[0]);
    printf("Type in your favorite food: ");
    if (memtoch == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return 1;
    }
    int found = 0; 
    while(1) {
        //Get the input
        if (fgets(memtoch, MAX_LENGTH_CHAR, stdin) == NULL)  {
            fprintf(stderr, "Please try again. Type in your favorite food:");
            while (getchar() != '\n');
            continue; //Restart loop if input fails
        }  
        memtoch[strcspn(memtoch, "\n")] = '\0'; //Replace every newline string (trailing newline) with the null terminator.
        for (int i = 0; i < main_options; ++i) {
            if (strcmp(memtoch, food_options[i]) == 0) {
                printf("You enjoy: %s\n", food_options[i]);
                found = 1;
                return 0; // Exit function on success
            }
        }
       if(!found) {
        printf("Try again: \n");
    }
}
if (strchr(memtoch, '\n') == NULL) {
    while (getchar() != '\n' && getchar() != EOF);
    }  
    free(memtoch);
    return 0;
}
int main() {
    return food();
}
