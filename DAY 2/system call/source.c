#include <stdio.h> 
#include <stdlib.h> // For exit() 
#include <errno.h>
int main() 
{ 
	FILE *fptr1, *fptr2; 
	char filename[50] = {"ARM-Architecture Reference Manual by David.txt"};
	char filename2[50] = {"out.txt"};
	char buffer[100];	
	char c; 

	
	fptr1 = fopen(filename, "r"); 
	if (fptr1 == NULL) 
	{ 
		perror("Cannot open file.\n"); 
		exit(0); 
	} 

	

	fptr2 = fopen(filename2, "w"); 
	if (fptr2 == NULL) 
	{ 
		perror("Cannot open file\n"); 
		exit(0); 
	} 

	// Read contents from file 
	int x =1;
	while (1) 
	{ 
		fputs(buffer, fptr2); 
		if(NULL==fgets(buffer, 100*sizeof(char),fptr1)) break; 
	} 

	printf("\nContents copied\n"); 

	fclose(fptr1); 
	fclose(fptr2); 
	return 0; 
}

