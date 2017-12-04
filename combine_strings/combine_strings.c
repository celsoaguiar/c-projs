// Project 8 Problem 1 Combining Strings
// CS 135 due 12/5/17
// Gabriel Aguiar

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // need this lib for free()


char* intersperse(char string1[], char string2[]);
char* widen_stars(char string1[], char string2[]);
void *malloc(size_t size);

int main(int argc, char *argv[]) {
    char string1[30 + 1];
    char string2[30 + 1];
    char* result;

    printf("Please enter a string of maximum 30 characters: ");
    scanf("%s", string1);
    printf("Please enter a string of maximum 30 characters: ");
    scanf("%s", string2);

    if (argc == 2 && strcmp(argv[1], "-i") == 0) { // argc
        result = intersperse(string1, string2);
        printf("The combined string is: %s\n", result); // print outside function, never forget newline \n
        free(result); // always free what you malloc or u get memory leaks
    }
    if (argc == 2 && strcmp(argv[1], "-w") == 0) {
        result = widen_stars(string1, string2);
        printf("The combined string is: %s\n", result);
        free(result);
    }

    return 0;
}

char* intersperse(char string1[], char string2[]) {
    char *new, *pnew, *s1, *s2;
    int i;
    int size;

    s1 = string1;
    s2 = string2;
    size = strlen(string1) + strlen(string2) - 1; // calc size
    pnew = new = (char *)malloc(size); // use another pointer to begin of string new

    for (i = 0; i < size; i++) {
        if (*s1 != '\0') {
            *new = *s1;
            new++;
            s1++;
        }
        if (*s2 != '\0') {
            *new = *s2;
            new++;
            s2++;
        }
    }

    *new = '\0';

    return pnew; // return pointer to begin of string new
}

char* widen_stars(char string1[], char string2[]) {
    char *new, *pnew, *s1, *s2;
    int i;
    int size;

    s1 = string1;
    s2 = string2;
    size = 2*strlen(string1) + 2*strlen(string2) - 1;  // double string1 + double string2
    pnew = new = (char *)malloc(size);

    for (i = 0; i < strlen(string1); i++) {
        *new = *s1;
        new ++;
        s1++;

        *new = '*'; // add *
        new++;
    }

    for (i = 0; i < strlen(string2); i++) {
        *new = *s2;
        new++;
        s2++;

        *new = '*'; // add *
        new++;
    }

    new--;  // eliminate last * in string new
    *new = '\0';

    return pnew;
}
