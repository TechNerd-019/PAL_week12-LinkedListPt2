#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

PLISTNODE userInput(PLISTNODE* list) {

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

	puts("Processing...");

	PLISTNODE newNode = createABook(volume, name, author);
	list = addBookToList(list, newNode);

	return list;
	
}

PLISTNODE createABook(int volume, char name[], char author[]) {

	PLISTNODE newBook = (PLISTNODE)malloc(sizeof(LIST));

	if (!newBook)
	{
		fprintf(stderr, "error allocating memory\n");
		exit(1);
	}

	strncpy(newBook->author, author, MAXLENGTH);
	strncpy(newBook->title, name, MAXLENGTH);

	newBook->volume = volume;

	newBook->next = NULL;
	newBook->prev = NULL;

	return newBook;
}

PLISTNODE addBookToList(PLISTNODE* list, PLISTNODE newNode) {

	if (*list == NULL) 
	{
		*list = newNode;
	}

	PLISTNODE currentNode = *list;
	PLISTNODE previousNode = currentNode->prev;

	//This makes sense to Hayden.
	while (currentNode->next != NULL) 
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	newNode->prev = currentNode;

	return *list;
}

PLISTNODE deleteNode(PLISTNODE* list, char title[]) 
{
	if (*list == NULL)
	{
		puts("List is empty. Nothing to delete.");
	}

	PLISTNODE currentItem = *list;

	if (currentItem->title == title)
	{
		if (currentItem->next != NULL)
		{
			currentItem->prev = currentItem;
			*list = currentItem->next;

		}

		else
		{
			*list = NULL;
			return *list;
		}
		free(currentItem);
		return *list;
	}

	while (currentItem != NULL && currentItem->title != title)
	{
		currentItem->prev = currentItem;
		currentItem = currentItem->next;

	}

	if (currentItem == NULL)
	{
		puts("Item with title does not exist.");
		return *list;
	}

	currentItem->prev = currentItem;
	currentItem = currentItem->next;
	
	printf("Item %s has been deleted.", title);

	free(currentItem);
	
	return *list;
}


