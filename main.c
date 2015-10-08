#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int choice;

	printf("\t\tHello and welcome to the dictionnary factory !\n");
	choice = chooseOption();
	// interact();

	printf("\nMade by MONOT Vincent & VALENTIN Paul\n\n");

	return 0;
}

int chooseOption() {
	int choice = 0;

	do {
		printf("Please choose an option in the following list :\n");
		printf("    1) Create dictionnary.\n");
		printf("    2) Display dictionnary.\n");
		printf("    3) Delete dictionnary.\n");
		printf("    4) Add a word in a dictionnary.\n");
		printf("    5) Delete a word in a dictionnary.\n");
		printf("    6) Is the word in the dictionnary ?\n\n");
		printf("    7) Exit software\n\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);
		printf("\n");
	} while(choice < 1 || choice > 7);

	return choice;
}

int interact() {
	char choice[100] = "";
	int quit = 0;

	while(!quit) {
		printf("\n> ");

		fgets(choice, sizeof(choice), stdin);

		if((strcmp(choice, "help") == 0) || (strcmp(choice, "?") == 0)) {
			printf("Help displayed");
		} else if((strcmp(choice, "list dictionnaries")) == 0 || (strcmp(choice, "list dicos") == 0)) {
			printf("Displays dictionnaries");
		} else if(strcmp(choice, "select") == 32) {
			printf("Checking if the dictionnary exists ...");
		} else if((strcmp(choice, "exit") == 0) || (strcmp(choice, "quit") == 0)) {
			printf("Exiting the software");
			quit = 1;
		} else {
			printf("String : %s\n", choice);
			printf("? : %d\n", strcmp(choice, "?"));
			printf("help : %d\n", strcmp(choice, "help"));
			printf("list dictionnaries : %d\n", strcmp(choice, "list dictionnaries"));
			printf("list dicos : %d\n", strcmp(choice, "list dicos"));
			printf("select : %d\n", strcmp(choice, "select"));
			printf("exit : %d\n", strcmp(choice, "exit"));
			printf("quit : %d\n", strcmp(choice, "quit"));
		}

		memset(choice, 0, sizeof(choice));
		printf("Reset : %s", choice);
	}
	printf("\n");
}