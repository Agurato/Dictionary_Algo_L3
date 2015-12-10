#include "libDico.h"

Dictionary createDictionary() {
	return NULL;
}

Dictionary createLetter(char letter) {
	Dictionary dico = (Dictionary) malloc(sizeof(struct node));
	dico->leftSon = NULL;
	dico->rightBrother = NULL;
	dico->character = letter;

	return dico;
}

Boolean emptyDico(Dictionary dico) {
	return (dico == NULL);
}

int lastBrotherPosition(Dictionary dico, Word word) {
	int currentChar = 0, position = 0;

	Word starWord = malloc(strlen(word) + 2);
	strcpy(starWord, word);
//	strcat(starWord, "*");

	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar ++) {
		char lowerChar = tolower(starWord[currentChar]);
		printf("starWord[%d]='%c' \\", currentChar, lowerChar);
		if(! emptyDico(dico->rightBrother)) {
			printf(" count ++\n");
			position = currentChar;
		}
		else {
			printf("\n");
		}
		while(dico->character < lowerChar) {
			dico = dico->rightBrother;
		}
		if(! emptyDico(dico->leftSon)) {
			dico = dico->leftSon;
		}
	}
	return position;
}

Boolean wordBelongs(Dictionary dico, Word word) {

	int currentChar = 0, lettersChecked = 0;
	// currentChar is the position of the letter we are checking
	// lettersChecked is the number of letters of the word belonging to the dictionary

	// We add a star '*' at the end of the word
	Word starWord = malloc(strlen(word) + 2);
	strcpy(starWord, word);
	//strcat(starWord, "*");

	if(emptyDico(dico)) {
		return false;
	}

	// For each letter in the word we're searching for
	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar++) {
		char lowerChar = tolower(starWord[currentChar]);
		// While the letter of the dico is inferior to the letter of the word
		while(dico->character < lowerChar) {
			// printf("\tdico->character('%c') != word[%d]('%c')\n", dico->character, currentChar, starWord[currentChar]);
			// If he has a brother, we check the letter with the brother's
			if(! emptyDico(dico->rightBrother)) {
				dico = dico->rightBrother;
			}
			// Else, the letter doesn't belong to the dico, therefore the word doesn't neither
			else {
				return false;
			}
		}
		// If the letter of the dico is equal to the letter of the word
		if(dico->character == lowerChar) {
			// printf("\tdico->character('%c') = word[%d]('%c')\n", dico->character, currentChar, starWord[currentChar]);
			// We checked one more letter
			lettersChecked ++;
			// printf("\tlettersChecked = %d/%d\n", lettersChecked, (int) strlen(starWord));
		}
		// If we went to far and passed the letter we were searching for
		// This means the letter isn't in the dico and the word neither
		else {
			return false;
		}
		// If we haven't checked every letter yet
		if(lettersChecked != strlen(starWord)) {
			// If there is a son to the letter, we move on to the next letter
			if(! emptyDico(dico->leftSon)) {
				dico = dico->leftSon;
			}
			// Else the word doesn't belong to the dico
			else {
				return false;
			}
		}
		// If we checked every letter, the word belongs to the dico
		else {
			return true;
		}
	}

	return true;
}

Dictionary displayDico(Dictionary dico, Word currentWord) {
	// If the dico isn't empty
	if(! emptyDico(dico)) {
		// If we are at the end of the word
		if(dico->character == '*') {
			// We display it
			printf("%s\n", currentWord);
			// If he has a right brother
			if(! emptyDico(dico->rightBrother)) {
				// We go on with the brother
				dico->rightBrother = displayDico(dico->rightBrother, currentWord);
			}
			// We continue with the next word
			return dico;
		}

		// If there is a left son
		if(! emptyDico(dico->leftSon)) {
			// We add the new character to the word to display
			int length = strlen(currentWord);
			Word newWord = malloc(length+2);
			strcpy(newWord, currentWord);	
			newWord[length] = dico->character;
			newWord[length+1] = '\0';

			// We continue with the son
			dico->leftSon = displayDico(dico->leftSon, newWord);
		}

		// If there is a right brother, we continue with him
		if(! emptyDico(dico->rightBrother)) {
			dico->rightBrother = displayDico(dico->rightBrother, currentWord);
		}
	}
	return dico;
}

Dictionary addWordRecursive(Dictionary dico, Word word, int position) {
	if(position < strlen(word)) {
		char lowerChar = tolower(word[position]);
		if(emptyDico(dico)) {
			dico = createLetter(lowerChar);
			dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
		}
		else {
			if(dico->character < lowerChar) {
				dico->rightBrother = addWordRecursive(dico->rightBrother, word, position);
			}
			else if(dico->character == lowerChar) {
				dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
			}
			else {
				Dictionary tempDico = createLetter(lowerChar);
				tempDico->rightBrother = dico;
				dico = tempDico;
				dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
			}
		}
	}

	return dico;
}

Dictionary deleteWordRecursive(Dictionary dico, Word word, int position, int lastBrother) {
	if(position < strlen(word)-1) {
		char lowerChar = tolower(word[position]);
		if(dico->character == lowerChar) {
			dico->leftSon = deleteWordRecursive(dico->leftSon, word, position+1, lastBrother);
		}
		else {
			dico->rightBrother = deleteWordRecursive(dico->rightBrother, word, position, lastBrother);
		}
	}

	if(position > lastBrother) {
		free(dico);
		dico = NULL;
	}

	return dico;
}

Dictionary save_dico(Dictionary dico, Word wordToSave, int fd){
    if(!emptyDico(dico)){
        if(dico->character == '*'){
            write(fd,wordToSave,strlen(wordToSave));
            write(fd,"\n",1);
        }
        
        /*Si il y à un fils on remplit le buffer avec la lettre courante
         * puis on passe au fils
         * */
        if(!emptyDico(dico->leftSon)){
            //printf("valeur du caractère : %c wordToSave : %s\n", dico->character, wordToSave);
            int length = strlen(wordToSave);
			Word newWord = malloc(length+2);
			strcpy(newWord, wordToSave);	
			newWord[length] = dico->character;
			newWord[length+1] = '\0';
            dico->leftSon = save_dico(dico->leftSon, newWord, fd);
        }
        if(!emptyDico(dico->rightBrother)){
            dico->rightBrother = save_dico(dico->rightBrother, wordToSave, fd);
        }
    }
    return dico;
}

Dictionary removeDictionary(Dictionary dico){
    if(!emptyDico(dico)){
        if(dico->leftSon != NULL)
            dico->leftSon = removeDictionary(dico->leftSon);
        if(dico->rightBrother != NULL)
            dico->rightBrother = removeDictionary(dico->rightBrother);
        free(dico);
        dico = NULL;
    }
    return dico;
}

Dictionary load_dico(){
    Dictionary dico = createDictionary();
    FILE *file;
    char *word = malloc(27*sizeof(char));
    int length;
    file = fopen("saveDictionary.save", "r");
   if(file != NULL){
        while(fgets(word, 27, file) != NULL){
            length = strlen(word);
            char *newWord = malloc(length+1);
            strcpy(newWord, word);
            newWord[length-1] = '*';
            dico = addWordRecursive(dico, newWord,0);
        }
   }else{
       printf("Impossible de charger le fichier\n");
   }

    fclose(file);
    return dico;
}
