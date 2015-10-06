#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int choice;

	printf("\n\t\tHello and welcome to the dictionnary factory !\n\n");
	printf("Please choose an option in the following list :\n");
	printf("    1) Create dictionnary.\n");
	printf("    2) Display dictionnary.\n");
	printf("    3) Delete dictionnary.\n");
	printf("    4) Add a word in a dictionnary.\n");
	printf("    5) Delete a word in a dictionnary.\n");
	printf("    6) Is the word in the dictionnary ?\n\n");

	printf("Enter your choice : ");
	scanf("%d", &choice);


	printf("\nMade by MONOT Vincent & VALENTIN Paul\n\n");

	return 0;
}