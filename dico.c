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
	Dictionary dico = NULL;
	dico = (Dictionary) malloc(sizeof(Dictionary));
	dico->leftSon = dico->rightBrother = NULL;
	dico->character = letter;

	return dico;
}

int emptyDico(Dictionary dico) {
	return (dico == NULL);
}

int wordBelongs(Dictionary dico, Word word) {

	int currentChar = 0, lettersChecked = 0;
	// currentChar is the position of the letter we are checking
	// lettersChecked is the number of letters of the word belonging to the dictionary

	// We add a star '*' at the end of the word
	Word starWord = malloc(strlen(word) + 2);
	strcpy(starWord, word);
	strcat(starWord, "*");

	// For each letter in the word we're searching for
	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar++) {
		printf("word[%d] = %c\n", currentChar, starWord[currentChar]);
		// While the letter of the dico is inferior to the letter of the word
		while(dico->character < starWord[currentChar]) {
			printf("%c != %c", dico->character, starWord[currentChar]);
			// If he has a brother, we check the letter with the brother's
			if(! emptyDico(dico->rightBrother)) {
				dico = dico->rightBrother;
			}
			// Else, the letter doesn't belong to the dico, therefore the word doesn't neither
			else {
				return 0;
			}
		}
		// If the letter of the dico is equal to the letter of the word
		if(dico->character == starWord[currentChar]) {
			// We checked one more letter
			lettersChecked ++;
			printf("lettersChecked = %d/%d\n", lettersChecked, (int) strlen(starWord));
		}
		// If we haven't checked every letter yet
		if(lettersChecked != strlen(starWord)) {
			// If there is a son to the letter, we move on to the next letter
			if(! emptyDico(dico->leftSon)) {
				dico = dico->leftSon;
			}
			// Else the word doesn't belong to the dico
			else {
				return 0;
			}
		}
		// If we checked every letter, the word belongs to the dico 
		else {
			return 1;
		}
	}

	return 1;
}

Dictionary addWord(Dictionary dico, Word word) {



	return dico;
}