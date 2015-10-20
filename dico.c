#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
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

	// printf("\nChecking for the word \"%s\" in the dictionary ...\n", word);

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
		if(dico->character == starWord[currentChar]) {
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
	/* If we didn't finish the word yet*/
	if(position < strlen(word)) {
		/* Here we are using only lower cases */
		char lowerChar = tolower(word[position]);
		/* If the dictionary is empty */
		if(emptyDico(dico)) {
			/* We create the new letter and add the next letter recursively */
			dico = createLetter(lowerChar);
			dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
		}
		/* If the dictionary isn't empty */
		else {
			/* If the character in the dico is inferior to the character of the word */
			if(dico->character < lowerChar) {
				/* We search for the right brother */
				dico->rightBrother = addWordRecursive(dico->rightBrother, word, position);
			}
			/* If we found the character corresponding to the word, we add the next letter recursively */
			else if(dico->character == lowerChar) {
				dico->leftSon = addWordRecursive(dico->leftSon, word, position+1);
			}
			/* If we didn't find it, we create it and make the link and add the next letter recursively */
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
	if(position < strlen(word)-2) {
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
		dico->leftSon = NULL;
	}
	else if((position == lastBrother)) {
		printf("Deleting son of word[%d]='%c' : '%c'\n", position, word[position], word[position+1]);
		free(dico->leftSon);
		dico->leftSon = NULL;
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
							sonDico->rightBrother = NULL;
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

int lastBrotherPosition(Dictionary dico, Word word) {
	int currentChar = 0, position = 0;

	Word starWord = malloc(strlen(word) + 2);
	strcpy(starWord, word);
	strcat(starWord, "*");

	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar ++) {
		printf("starWord[%d]='%c' \\", currentChar, starWord[currentChar]);
		if(! emptyDico(dico->rightBrother)) {
			printf(" count ++\n");
			position = currentChar;
		}
		else {
			printf("\n");
		}
		while(dico->character < starWord[currentChar]) {
			dico = dico->rightBrother;
		}
		if(! emptyDico(dico->leftSon)) {
			dico = dico->leftSon;
		}
	}
	return position;
}

/* Search the word with belongs_word and delete the Word*/
// Dictionary delete_word(Dictionary dictionary, Word word){
//	 Dictionary wordToDelete = NULL;
//	 if(!wordBelongs(dictionary, word)){
//		 printf("Le mot a supprimer n'existe pas");
//		 return dictionary;
//	 }
//	 else{
//		 wordToDelete = last_letter(dictionary, word);
//		 /*S'il n'a pas de frère droit, ie : soit juste un père soit juste un frère gauche*/
//		 while(wordToDelete->rightBrother == NULL && wordToDelete->leftBrother == NULL){
//			 /*Il faut supprimer le père*/
//			 wordToDelete = wordToDelete->father;
//			 free(wordToDelete->leftSon);
//			 wordToDelete->leftSon = NULL;
//		 }
//		 /*Une fois que toutes les lettres sans frère droit sont supprimer
//		  * il ne reste que à supprimer la lettre avec un frère droit, ou gauche */
//		 /*S'il à uniquement un frère gauche*/
//		 if(wordToDelete->leftBrother != NULL && wordToDelete->rightBrother == NULL){
//			 wordToDelete = wordToDelete->leftBrother;
//			 free(wordToDelete->rightBrother);
//			 wordToDelete->rightBrother = NULL;
//		 }
//		 /*S'il à uniquement un frère droit*/
//		 else if(wordToDelete->leftBrother == NULL && wordToDelete->rightBrother != NULL){
//			 wordToDelete->rightBrother->leftBrother = NULL;
//			 Dictionary letter = wordToDelete->father;
//			 letter->leftSon = wordToDelete->rightBrother;
//			 free(wordToDelete);
//			 wordToDelete = letter;
//		 }
//		 /*S'il à un frère droit et un gauche*/
//		 else{
//		   Dictionary letter = wordToDelete->leftBrother;
//		   wordToDelete->leftBrother->rightBrother = wordToDelete->rightBrother;
//		   wordToDelete->rightBrother->leftBrother = wordToDelete->leftBrother;
//		   free(wordToDelete);
//		   wordToDelete = letter;
//		  }
//	 }
//	 return dictionary;
// }

// /* Function which return the pointeur of the word's last letter that we want delete
//  * Prerequire : The word have to belongs to the dictionary
//  */
// Dictionary last_letter(Dictionary dico, Word word){
// 	int currentChar = 0;
// 	// currentChar is the position of the letter we are checking

// 	// We add a star '*' at the end of the word
// 	Word starWord = malloc(strlen(word) + 2);
// 	strcpy(starWord, word);
// 	strcat(starWord, "*");

// 	// For each letter in the word we're searching for
// 	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar++) {
// 		// While the letter of the dico is inferior to the letter of the word
// 		while(dico->character < starWord[currentChar]) {
// 				dico = dico->rightBrother;
// 		}
// 		if(! emptyDico(dico->leftSon)) {
// 			dico = dico->leftSon;
// 		}
// 	}
//	 return dico;
// }