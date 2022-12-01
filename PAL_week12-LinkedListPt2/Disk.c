#define _CRT_SECURE_NO_WARNINGS
#include "Disk.h"


void saveToDisk(PLISTNODE list)
{
	FILE* database;
	if ((database = fopen("Data.txt", "w")) == NULL)
	{
		printf(stderr, "Cannot create a file");
	}

	PLISTNODE listHead = list;
	while (listHead != NULL)
	{
		fprintf(database, "%s\n", listHead->title);
		fprintf(database, "%s\n", listHead->author);
		fprintf(database, "%d\n", listHead->volume);
		listHead = listHead->next;
	}
	fclose(database);
}
void readFromDisk(PLISTNODE list)
{
	char tempVol[MAXLENGTH];
	char tempAuthor[MAXLENGTH];
	char tempTitle[MAXLENGTH];

	PLISTNODE headList = NULL;
	FILE* loadFile;

	if ((loadFile = fopen("Data.txt", "r")) == NULL)
	{
		printf(stderr, "Cannot create a file");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i != EOF; i++)
	{
		fgets(tempTitle, MAXLENGTH, loadFile);
		fgets(tempAuthor, MAXLENGTH, loadFile);
		fgets(tempVol, MAXLENGTH, loadFile);
		int vol = atoi(tempVol);

		headList = createABook(vol, tempTitle, tempAuthor);
		list = addBookToList(list, headList);
	}

	fclose(loadFile);
}