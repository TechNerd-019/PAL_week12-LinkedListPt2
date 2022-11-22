#include "List.h"
#include <stdio.h>
#include <string.h>

PLISTNODE userInput(PLISTNODE list) {

	char name[MAXLENGTH];
	char author[MAXLENGTH];
	int volume;

	puts("Enter the title of your book: ");
	fgets(name, MAXLENGTH, stdin);
	name[strlen(name) - 1] = '\0';

	puts("Enter the name of your author: ");
	fgets(author, MAXLENGTH, stdin);
	author[strlen(author) - 1] = '\0';
	
	puts("Enter the volume number of your book: ");
	scanf_s("%d", &volume);

	puts("Procesiing...");

	PLISTNODE newNode = createABook(volume, name, author);
	list = addBookToList(newNode);

	return list;
	
}