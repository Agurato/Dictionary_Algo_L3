#include "libDico.h"

Dictionary createDictionary() {
	return NULL;
}

Dictionary createLetter(char letter) {
	Dictionary dico = (Dictionary) malloc(sizeof(struct node));
	dico->leftSon = NULL;
	dico->rightBrother = NULL;
	// dico->leftBrother = NULL;
	// dico->father = father;
	dico->character = letter;

	return dico;
}

Boolean emptyDico(Dictionary dico) {
	return (dico == NULL);
}

Boolean wordBelongs(Dictionary dico, Word word) {

	printf("\nChecking for the word \"%s\" in the dictionary ...\n", word);

	int currentChar = 0, lettersChecked = 0;
	// currentChar is the position of the letter we are checking
	// lettersChecked is the number of letters of the word belonging to the dictionary

	// We add a star '*' at the end of the word
	Word starWord = malloc(strlen(word) + 2);
	strcpy(starWord, word);
	strcat(starWord, "*");

	if(emptyDico(dico)) {
		return false;
	}

	// For each letter in the word we're searching for
	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar++) {
		// While the letter of the dico is inferior to the letter of the word
		while(dico->character < starWord[currentChar]) {
			printf("\tdico->character('%c') != word[%d]('%c')\n", dico->character, currentChar, starWord[currentChar]);
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
		if(dico->character == starWord[currentChar]) {
			printf("\tdico->character('%c') = word[%d]('%c')\n", dico->character, currentChar, starWord[currentChar]);
			// We checked one more letter
			lettersChecked ++;
			printf("\tlettersChecked = %d/%d\n", lettersChecked, (int) strlen(starWord));
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
	// If we didn't finish to add the word yet
	if(position < strlen(word)) {
		printf("\nword[%d]='%c'", position, word[position]);
		// If there is a letter on the dico
		if(! emptyDico(dico)) {
			printf(" \\ dico->character='%c'", dico->character);
			// If the letter of the dictionary is inferior to the letter of the word 
			if(dico->character < word[position]) {
				// If there is a right brother
				if(! emptyDico(dico->rightBrother)) {
					// If the letter of the right brother is inferior or equal to the letter of the word
					if(dico->rightBrother->character <= word[position]) {
						// We're going on with the right brother
						dico->rightBrother = addWordRecursive(dico->rightBrother, word, position);
					}
					// If the letter of the brother is superior to the letter of the word
					else {
						// We create a new letter
						Dictionary newLetter = createLetter(word[position]);
						// The right brother of the new letter is the right brother of the dico
						newLetter->rightBrother = dico->rightBrother;
						// The new letter is the right brother of the dico
						dico->rightBrother = newLetter;
						// We add the next letter on the son
						dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
					}
				}
				// If there isn't a right brother
				else {
					printf(" \\ Adding it ...");
					// We add the letter of the word as the right brother
					dico->rightBrother = createLetter(word[position]);
					// We add the next letter on the right brother's son
					dico->rightBrother->leftSon = addWordRecursive(dico->rightBrother->leftSon, word, position+1);
				}
			}
			// If the letter of the dico is equal to the letter of the word
			else if(dico->character == word[position]) {
				// If there is a son
				if(! emptyDico(dico->leftSon)) {
					// If the letter of the son is superior to the letter of the next letter of the word
					if(dico->leftSon->character > word[position+1]) {
						// We create a new letter with the next letter of the word
						Dictionary newLetter = createLetter(word[position+1]);
						// The left son of the dico is now the right brother of the new letter
						newLetter->rightBrother = dico->leftSon;
						// The new letter is the left son of the dico
						dico->leftSon = newLetter;
					}
				}
				// We add the next letter on the son
				dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
			}
			else {
				printf("dico->character > word[position] : PROBLEM\n");
			}
		}
		// If there isn't any letter on the dico
		else {
			printf(" \\ Adding it ...");
			// We create the letter
			dico = createLetter(word[position]);
			// We add the new letter on the son
			dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
		}
	}
	else {
		return dico;
	}

	return dico;
}

Dictionary deleteWordRecursive(Dictionary dico, Word word, int position, int lastBrother) {
	// printf("position=%d/%d : %c-%c \\ lastBrother=%d\n", position, (int) strlen(word)-1, word[position], dico->character, lastBrother);
	Boolean isLeftSon = false;
	if(position < strlen(word)-2) {
		if(position == lastBrother) {
			if(dico->leftSon->character == word[position+1]) {
				isLeftSon = true;
			}
		}

		if(dico->character == word[position]) {
			dico->leftSon = deleteWordRecursive(dico->leftSon, word, position+1, lastBrother);
		}
		else {
			dico->rightBrother = deleteWordRecursive(dico->rightBrother, word, position, lastBrother);
		}
	}

	printf("position:%d\n", position);
	if(position > lastBrother) {
		printf("Deleting son of word[%d]='%c' : '%c'\n", position, word[position], word[position+1]);
		free(dico->leftSon);
	}
	else if((position == lastBrother)) {
		printf("Deleting son of word[%d]='%c' : '%c'\n", position, word[position], word[position+1]);
		free(dico->leftSon);
	}
	else if(position == lastBrother-1) {
		// If he is the left son
		if(dico->leftSon->character == word[position+1]) {
			// If he has right brother
			if(! emptyDico(dico->leftSon->rightBrother)) {
				// We delete it and make the connections
				Dictionary tempDico = dico->leftSon->rightBrother;
				printf("Deleting son of word[%d]='%c' : '%c'\n", position, word[position], word[position+1]);
				free(dico->leftSon);
				dico->leftSon = tempDico;
			}
			else {
				printf("emptyDico(dico->leftSon->rightBrother)\n");
			}
		}
		// If he is a right brother
		else {
			Dictionary sonDico = dico->leftSon;
			while(sonDico->character < word[position+1]) {
				if(! emptyDico(sonDico->rightBrother)) {
					if(sonDico->rightBrother->character < word[position+1]) {
						sonDico = sonDico->rightBrother;
					}
					else if(sonDico->rightBrother->character == word[position+1]) {
						if(! emptyDico(sonDico->rightBrother->rightBrother)) {
							Dictionary tempDico = sonDico->rightBrother->rightBrother;
							printf("Deleting son of word[%d]='%c' via brother='%c': '%c'\n", position, word[position], sonDico->character, word[position+1]);
							free(sonDico->rightBrother);
							sonDico->rightBrother = tempDico;
							return dico;
						}
						else {
							free(sonDico->rightBrother);
							return dico;
						}
					}
				}
				else {
					printf("emptyDico(sonDico->rightBrother)\n");
				}
			}
		}
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
            printf("valeur du caractère : %c wordToSave : %s\n", dico->character, wordToSave);
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

Dictionary load_dico(){
    /*Boucle while + addWord pour chaque mot*/
}
