/* Ce sont mes essais de fonctions, stp n'y touche pas 
C'est un fichier à part pour ne pas avoir à travailler à 2 sur le même fichier et risquer des problèmes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libDico.h"

Dictionary createDictionary() {
	return NULL;
}

Dictionary createLetter(char letter) {
	Dictionary dico = (Dictionary) malloc(sizeof(Dictionary));
	dico->leftSon = dico->rightBrother = NULL;
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

	// For each letter in the word we're searching for
	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar++) {
		printf("word[%d] = '%c'\n", currentChar, starWord[currentChar]);
		// While the letter of the dico is inferior to the letter of the word
		while(dico->character < starWord[currentChar]) {
			printf("'%c' != '%c'\n", dico->character, starWord[currentChar]);
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
			printf("'%c' = '%c'\n", dico->character, starWord[currentChar]);
			// We checked one more letter
			lettersChecked ++;
			printf("lettersChecked = %d/%d\n", lettersChecked, (int) strlen(starWord));
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

Dictionary addWord(Dictionary dico, Word word) {
	printf("Trying to add the word \"%s\" into the dictionary\n", word);

	if(wordBelongs(dico, word)) {
		printf("The word \"%s\" already belongs to the dictionary\n", word);
		return dico;
	}
	else {
		printf("The word \"%s\" doesn't belong to the dictionary yet\n", word);
	}

	Dictionary initialDico = dico;

	int currentChar = 0;
	Dictionary newLetter = createDictionary();

	// We add a star '*' at the end of the word
	Word starWord = malloc(strlen(word) + 2);
	strcpy(starWord, word);
	strcat(starWord, "*");

	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar ++) {
		printf("dico->character = '%c' compared to word[%d] = '%c' \n", dico->character, currentChar, starWord[currentChar]);
		if(dico->character != NULL) {
			while(dico->character < starWord[currentChar]) {
				if(! emptyDico(dico->rightBrother)) {
					if(dico->rightBrother->character <= starWord[currentChar]) {
						dico = dico->rightBrother;
					}
					else {
						newLetter = createLetter(starWord[currentChar]);
						newLetter->rightBrother = dico->rightBrother;
						dico->rightBrother = newLetter;
						dico = dico->rightBrother;
					}
				}
				else {
					newLetter = createLetter(starWord[currentChar]);
					dico->rightBrother = newLetter;
					dico = dico->rightBrother;
				}
			}
		}
		if(dico->character == starWord[currentChar]) {
			// T'es con : le leftSon a pas de caractère définit à sa création, impossible de comparer
			dico = dico->leftSon;
			dico->character = NULL;
		}
		else {
			printf("(dico->character = '%c') != (starWord[currentChar] = '%c')\n", dico->character,starWord[currentChar]);
		}
	}

	printf("Word added to the dictionary\n");
	return initialDico;
}
