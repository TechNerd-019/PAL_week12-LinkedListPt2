#include "List.h"
#include "MainScreen.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NUM_SIZE_BYTES 4


int main(void) {

	bool isRunning = true;
	PLISTNODE list = NULL;
	int userChoice;
	char buf[NUM_SIZE_BYTES];
	char itemToDelete[MAXLENGTH];
	do {
		displayMenu();

		do {
			printf("enter a number: ");
			if (!fgets(buf, NUM_SIZE_BYTES, stdin)) {
				return 1;
			}
			userChoice = atoi(buf);
		} while (userChoice == 0);

		switch (userChoice) {
		case 1:
			userInput(&list);
			break;
		case 2:
			puts("What is the title of the book to delete? ");
			fgets(itemToDelete, MAXLENGTH, stdin);
			itemToDelete[strlen(itemToDelete) - 1] = '\0';
			deleteNode(&list, itemToDelete);
			break;
		case 3:
			//
			break;
		case 4:
			isRunning == false;
			break;
		}
	} while (isRunning == true);

	// Function to save list before exiting the program.


	return 0;
}

