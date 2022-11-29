#pragma once

#define MAXLENGTH		25


//Write a C program that uses doubly linked lists for a books database, allowing the user to add a book structure,
//and add that node to the list, delete a book from the list, and search for a specific book based on title.
//Finally, load the list from and save it to file.
// Sacred testament:
//while (currentBook->next != NULL) //Crawl through the list until the next is pointing to null
//{
//	currentBook = currentBook->next;
//}
//
//prevBook = currentBook->next; //re-reference the previous book to the list
//currentBook->next = newBook; //re-reference the next pointer from null to the newBook
//newBook->prev = prevBook; //reference the newBook prve to curr

typedef struct list {

	int volume;
	char author[MAXLENGTH];
	char title[MAXLENGTH];

	struct listnode* next;
	struct listnode* prev;

}LIST, *PLISTNODE;

PLISTNODE addBookToList(PLISTNODE*, PLISTNODE*);
PLISTNODE userInput(PLISTNODE*);
PLISTNODE deleteNode(PLISTNODE*, char[]);
PLISTNODE createABook(int, char[], char[]);
//void searchBook(PLISTNODE, char[]);
//void saveToDisk(PLISTNODE);
//void readFromDisk(PLISTNODE);





