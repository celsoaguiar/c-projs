// Project 8 Problem 2 Planet Sort
// CS 135 due 12/5/17
// Gabriel Aguiar

#include <stdio.h>
#include <string.h>

int string_compare(char str1[], char str2[]);

int main(int argc, char *argv[]) {
	int i, j, temp;
	const int size_planets = 9;
    char *planets[size_planets]  = { "Pluto", "Venus", "Saturn", "Mercury", "Jupiter", "Earth", "Neptune", "Uranus", "Mars" };
	int planets_indexes[size_planets] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    if (argc == 3 && strcmp(argv[1], "-o") == 0) {

    	if (strcmp(argv[2], "a") == 0) {

			for (i = 0; i < size_planets; i++) 
			{
				for (j = (size_planets - 1); j > (i); j--) 
				{
					if (string_compare(planets[planets_indexes[j]], planets[planets_indexes[j-1]]) == 0) {
						temp = planets_indexes[j];
						planets_indexes[j] =  planets_indexes[j-1];
						planets_indexes[j-1] = temp;
					}
				}
			}


			printf("The planets in alphabetical order are: ");
			for (i = 0; i < size_planets; i++) {
				printf("%s, ", planets[planets_indexes[i]]);
			}
			printf("\n");
		}

    	if (strcmp(argv[2], "r") == 0) {

			for (i = 0; i < size_planets; i++) 
			{
				for (j = (size_planets - 1); j > (i); j--) 
				{
					if (string_compare(planets[planets_indexes[j]], planets[planets_indexes[j-1]]) == 1) { 
						temp = planets_indexes[j];
						planets_indexes[j] =  planets_indexes[j-1];
						planets_indexes[j-1] = temp;
					}
				}
			}

			printf("The planets in reverse alphabetical order are: ");
			for (i = 0; i < size_planets; i++) {
				printf("%s, ", planets[planets_indexes[i]]);
			}
			printf("\n");
		}
    }

	return 0;	
}

int string_compare(char str1[], char str2[]) {
	
	char* s1 = str1;
	char* s2 = str2;

    while (*(s1) != '\0' || *s2 != '\0') {

		if (*s1 < *s2) {
			return 0;
		} else if (*s1 > *s2) {
			return 1;
		}

		s1++;
		s2++;
	}

	return -1;
}
