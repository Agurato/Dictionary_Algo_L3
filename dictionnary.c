#include "libDico.h"
#include <malloc.h>


/*
Dictionnary create_dictionnary(){
    return NULL;
}
*/
/* Search the word with belongs_word and delete the Word*/
Dictionary delete_word(Dictionary dictionary, Word word){
    Dictionary wordToDelete = NULL;
    if(!wordBelongs(dictionnary, word)){
        printf("Le mot a supprimer n'existe pas");
        exit(dictionary);
    }
    else{
        wordToDelete = last_letter(dictionary, word);
        /*S'il n'a pas de frère droit, ie : soit juste un père soit juste un frère gauche*/
        while(wordToDelete->rightBrother == NULL && wordToDelete->leftBrother == NULL){
            /*Il faut supprimer le père*/
            wordToDelete = wordToDelete->father;
            free(wordToDelete->leftSon);
            wordToDelete->leftSon = NULL;
        }
        /*Une fois que toutes les lettres sans frère droit sont supprimer
         * il ne reste que à supprimer la lettre avec un frère droit, ou gauche */
        /*S'il à uniquement un frère gauche*/
        if(wordToDelete->leftBrother != NULL && wordToDelete->rightBrother == NULL){
            wordToDelete = wordToDelete->leftBrother;
            free(wordToDelete->rightBrother);
            wordToDelete->rightBrother = NULL;
        }
        /*S'il à uniquement un frère droit*/
        else if(wordToDelete->leftBrother == NULL && wordToDelete->rightBrother != NULL){
            wordToDelete->rightBrother->leftBrother = NULL;
            Dictionary letter = wordToDelete->father;
            letter->leftSon = wordToDelete->rightBrother;
            free(wordToDelete);
            wordToDelete = letter;
        }
        /*S'il à un frère droit et un gauche*/
        else{
          Dictionary letter = wordToDelete->leftBrother;
          wordToDelete->leftBrother->rightBrother = wordToDelete->rightBrother;
          wordToDelete->rightBrother->leftBrother = wordToDelete->leftBrother;
          free(wordToDelete);
          wordToDelete = letter;
         }
    }
    return dictionary;
}

/* Function which return the pointeur of the word's last letter that we want delete
 * Prerequire : The word have to belongs to the dictionary
 */
Dictionary last_letter(Dictionary dico, Word word){
	int currentChar = 0, lettersChecked = 0;
	// currentChar is the position of the letter we are checking
	// lettersChecked is the number of letters of the word belonging to the dictionary

	// We add a star '*' at the end of the word
	Word starWord = malloc(strlen(word) + 2);
	strcpy(starWord, word);
	strcat(starWord, "*");

	// For each letter in the word we're searching for
	for(currentChar = 0 ; starWord[currentChar] != '\0' ; currentChar++) {
		// While the letter of the dico is inferior to the letter of the word
		while(dico->character < starWord[currentChar]) {
				dico = dico->rightBrother;
		}
		if(! emptyDico(dico->leftSon)) {
			dico = dico->leftSon;
		}
	}
    return dico;
}
