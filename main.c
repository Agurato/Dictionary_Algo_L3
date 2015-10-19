#include "libDico.h"

int chooseOption();
int type_n();
int main(int argc, char const *argv[])
{
    int choice = 0;

	printf("\t\tHello and welcome to the dictionary factory !\n");

	Dictionary dico = createDictionary();
	
	while(choice != 8) {
		choice = chooseOption();

		/* Do the selected option */

		switch(choice) {
			case 1 :
				printf("Please enter the word you desire to add : \n");
                Word word = malloc(25*sizeof(char));
                char buf[25] = {0};
                int d = 0;
			//	fgets(word, sizeof(word), stdin);
                
            //  Il faut vider le buffer après le read sinon on a des problèmes !!
                do{
                    read(0,word,25);
                    while(d != '\n' && d != EOF){
                        d = getchar();
                    }
                    printf("Word contient : %s\n",word);
                }while(getchar() != '\n');

				Word starWord = malloc(strlen(word) + 2);
				strcpy(starWord, word);
				strcat(starWord, "*");
				dico = addWordRecursive(dico, starWord, 0);
				break;
			case 2 :
				printf("Displaying dictionaries ...\n");
				break;
			case 3 :
				printf("Deleting dictionary ... \n");
				break;
			case 4 :
				printf("Adding word to dictionary ... \n");
				break;
			case 5 :
				printf("Deleting word in dictionary ... \n");
				break;
			case 6 :
				printf("Searching for word in dictionary ... \n");
                Word wordSave = malloc(27*sizeof(char));
                dico = save_dico(dico,wordSave,0);
				break;
			case 7 :
                printf("We will load the dictionary\n");
                /* dico = load_dictionary()*/
				break;
			default :
				printf("Error in the matrix ... \n");
		}
	}

	printf("\nMade by MONOT Vincent & VALENTIN Paul\n\n");

	return 0;
}

int chooseOption() {
	int choice = 0;

	do {
		printf("Please choose an option in the following list :\n");
		printf("\t1) Add a word.\n");
		printf("\t2) Delete a word.\n");
		printf("\t3) Display dictionary.\n");
		printf("\t4) Is the word in the dictionary?\n");
		printf("\t5) Empty dictionary.\n");
		printf("\t6) Save dictionary.\n");
		printf("\t7) Load dictionary.\n\n");
		printf("\t8) Exit software\n\n");

		printf("Enter your choice : ");
        choice = type_n();
		printf("choice : %d\n",choice);
	} while((choice < 1 || choice > 8));

	return choice;
}

int type_n(){
    char *c = malloc(sizeof(char)); 
    
    scanf("%s",c);
       if(isdigit(*c))
        return (int) *c - '0';
    return -1;
}

