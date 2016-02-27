/*****************************************************************
 *
 *  NAME: 		Torleif Nielsen
 *
 *  HOMEWORK:       5
 *
 *  CLASS:           	ICS 212
 *
 *  INSTRUCTOR:     Ravi Narayan
 *
 *  DATE:            	March 3, 2015           
 *
 *  FILE:  	         	driver.c        
 *
 *  DESCRIPTION:     This is driver file for the read and write to a file
 					programs. It contains the main method to drive the program.
 *
 *****************************************************************/
 
#include <stdio.h>
#include <string.h>
#include "iofunctions.h"

 /*****************************************************************
 *
 *  Function name:  	main 
 *
 *  DESCRIPTION:   Main method for the hw5 assignment, it drives and tests
 					the read and write methods to a file..
 *
 *  Parameters:      	int argc, char argv[]
 *
 *  Return values:  	 0
 *
 *****************************************************************/
 
int main(int argc, char * argv[])
{
	int numCust;
	
	struct account emptyaccounts[5];

	/* Get number of customers from user */
	printf("Please enter the number of customers to read: ");
	scanf("%d", &numCust);
	printf("\n");
	
	if (numCust <= 0)
	{
		printf("Oops, please enter an integer number greater than zero.\n");
	}
	else
	{
		
		printf("Testing read from file that does not exist...\n");
		readfile(emptyaccounts, &numCust, "wrongfile.txt");
		
		printf("Testing read from file that has no lines...\n");
		readfile(emptyaccounts, &numCust, "emptyfile.txt");
		
		printf("Please enter the number of customers to read: ");
		scanf("%d", &numCust);
		struct account bankaccounts[numCust];
		readfile(bankaccounts, &numCust, "testfile1.txt");
	
		printf("Read the following lines from \"%s\"\n", "testfile1.txt");
		int i = 0;
		while (i < numCust)
		{
			printf( "%s\t%d\t$%.2f\n", bankaccounts[i].name, bankaccounts[i].accountno, bankaccounts[i].balance);
			i++;
		}
	}
	
	/* Get number of customers from user */
	printf("Please enter the number of customers to write: ");
	scanf("%d", &numCust);
	printf("\n");
	
	if (numCust <= 0)
	{
		printf("Oops, please enter an integer number greater than zero.\n");
	}
	else
	{
		struct account bankaccounts[numCust];
		writefile(bankaccounts, numCust, "testfile1.txt");
	}
	
	struct account bankaccounts[numCust];
	printf("Testing read from newly written file...\n");
	readfile(bankaccounts, &numCust, "testfile1.txt");

	printf("Read the following lines from \"%s\"\n", "testfile1.txt");
	int j = 0;
	while (j < numCust)
	{
		printf( "%s\t%d\t$%.2f\n", bankaccounts[j].name, bankaccounts[j].accountno, bankaccounts[j].balance);
		j++;
	}
	numCust = 5;
	printf("Testing partial read from file with 10 lines...\n");
	struct account manyaccounts[numCust];
	readfile(manyaccounts, &numCust, "tenaccounts.txt");

	printf("Read the following lines from \"%s\"\n", "tenaccounts.txt");
	int k = 0;
	while (k < numCust)
	{
		printf( "%s\t%d\t$%.2f\n", manyaccounts[k].name, manyaccounts[k].accountno, manyaccounts[k].balance);
		k++;
	}
	return 0;
}

