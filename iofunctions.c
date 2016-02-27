#include <stdio.h>
#include <string.h>
#include "iofunctions.h"

/*****************************************************************
 *
 *  Function name:  	readfile
 *
 *  DESCRIPTION:   This function reads lines of text from a file into
 					a struct array for a bank account.
 *
 *  Parameters:      	struct account[], int *, char[]
 *
 *  Return values:  	 void
 *
 *****************************************************************/
 
void readfile(struct account accarray[], int * numcust, char filename[])
{
	int i = 0;
	int character;
	int lines = 0;
	
	/* Correct the number of customers based on the actual lines in the file */
	FILE *file = fopen(filename, "r");
	
	if (file != NULL)
	{
		while (!feof(file))
		{
			character = fgetc(file);
			if (character == '\n')
			{
				++lines;
			}
		}
		fclose(file);
	}
	if (*numcust > lines)
	{
		*numcust = lines;
	}
	
	fopen(filename, "r");
	if (file != NULL && lines != 0)
	{

		printf("Reading from file: %s...\n", filename);
		
		fseek(stdin, 0, SEEK_END);
		while (i < *numcust)
		{
			fscanf(file, "%[^\t]\t%d\t%f\n", accarray[i].name, &accarray[i].accountno, &accarray[i].balance);
			i++;
		}
		fclose(file);
	}
	else if (lines == 0)
	{
		printf("There are no lines in file: \"%s\" to read.\n", filename);
	}
	else
	{
		printf("ERROR: Invalid file name or file does not exist.\n");
	}
}

/*****************************************************************
 *
 *  Function name:  	writefile
 *
 *  DESCRIPTION:   This function writes lines of text to a file and a struct
 					account array from a the user for a bank account.
 *
 *  Parameters:      	struct account[], int, char[]
 *
 *  Return values:  	 void
 *
 *****************************************************************/
 
void writefile(struct account accarray[], int numcust, char filename[])
{
	int i = 0;
	FILE *file = fopen(filename, "w");
	if (file != NULL)
	{
		printf("Writing to file: %s...\n", filename);
	
		while (i < numcust)
		{
			char *lastChar;
			int loopBreaker = 0;
			
			do{
				printf("Please enter the account holder's name with a $ immediately following the last letter.\n");
				fseek(stdin, 0, SEEK_END);
				fgets(accarray[i].name, 25, stdin);
		
				if ((lastChar = strchr(accarray[i].name, '$')) != NULL)
				{
					*lastChar = '\0';
					loopBreaker = 1;
				}
				else
				{
					printf("Please end your input with a $ character.\n");
				}
		
			} while (loopBreaker == 0);
			
			fseek(stdin, 0, SEEK_END);
			printf("Enter the account number: ");
			scanf("%d", &accarray[i].accountno);
			fseek(stdin, 0, SEEK_END);
			printf("Enter the account's balance: ");
			scanf("%f", &accarray[i].balance);
			
			printf("Writing customer %d to file...\n", (i + 1));
			fprintf(file, "%s\t%d\t%f\n", accarray[i].name, accarray[i].accountno, accarray[i].balance);
			i++;
		}
		fclose(file);
	}
	else
	{
		printf("ERROR: Invalid file name or file does not exist.\n");
	}
}

