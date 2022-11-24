#include "List.h"
#include "MainScreen.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void) {

	bool isRunning = true;
	PLISTNODE list = NULL;
	int userChoice;
	do {
		displayMenu();

		scanf_s("%d", &userChoice);

		switch (userChoice) {
		case 1:
			userInput(&list);
			break;
		case 2:
			//
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

