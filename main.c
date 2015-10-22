#include "libDico.h"

int chooseOption();
int type_n();
Word wordToEnter();

int main(int argc, char const *argv[])
{
    int choice = 0,fd;
    int booleen = 0;
    Word word;
	printf("\t\tHello and welcome to the dictionary factory !\n");

	Dictionary dico = createDictionary();
	
	while(choice != 8) {
		choice = chooseOption();

		/* Do the selected option */

		switch(choice) {
			case 1 :
				printf("Please enter the word you desire to add : \n");
                word = wordToEnter();
				dico = addWordRecursive(dico, word, 0);
				break;
			case 3 :
                displayDico(dico,"");
				break;
			case 2 :
                printf("Please enter the word you desire to delete : \n");
                word = wordToEnter();
				/*dico = deleteWordRecursive();*/
				break;
			case 4 :
                printf("Please enter the word you desire to check : \n");
                word = wordToEnter();
                booleen = wordBelongs(dico, word);
                if(booleen)
                    printf("\n\n\n\t\tLe mot est bien dans le dictionnaire\n\n\n");
                else
                    printf("\n\n\n\t\tLe mot n'est pas dans le dictionnaire\n\n\n");
				break;
			case 5 :
                dico = removeDictionary(dico);
                printf("The dictionary is remove.\n");
				break;
			case 6 :
                fd = open("saveDictionary.save", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
                Word wordSave = malloc(27*sizeof(char));
                dico = save_dico(dico,wordSave,fd);
                close(fd);
				break;
			case 7 :
                /* dico = load_dictionary()*/
				break;
            case 8 :
                printf("\n\n\n\n\t\t\tGood Bye !!!\t\t\n\n\n\n");
                break;
			default :
				printf("Error in the matrix ... \n");
		}
	}

	printf("\n\tMade by MONOT Vincent & VALENTIN Paul\n\n");

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
		printf("\t5) Remove dictionary.\n");
		printf("\t6) Save dictionary.\n");
		printf("\t7) Load dictionary.\n\n");
		printf("\t8) Exit software\n\n");

		printf("Enter your choice : ");
        choice = type_n();
		printf("choice : %d\n",choice);
	} while((choice < 1 || choice > 8));

	return choice;
}

/*Take a character and return only the first (Avoid problems)*/
int type_n(){
    char *c = malloc(sizeof(char)); 
    
    scanf("%s",c);
       if(isdigit(*c))
        return (int) *c - '0';
    return -1;
}

Word wordToEnter(){
    Word word = malloc(25*sizeof(char));
        char buf[25] = {0};
        int d = 0;
        // read the word then erase the buffer of stdin
        do{
            read(0,word,25);
            while(d != '\n' && d != EOF){
                d = getchar();
            }
            printf("Tapez Entrée\n");
        }while(getchar() != '\n');

		Word starWord = malloc(strlen(word) + 1);
		strcpy(starWord, word);
        starWord[strlen(word)-1] = '\0';
		strcat(starWord, "*");

    return starWord;
}
