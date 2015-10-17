#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libDico.h"

int main(int argc, char const *argv[])
{
	Dictionary dico = createDictionary();
	dico = createLetter('A');
	dico->leftSon = createLetter('*');
	
	Word newWord = "Bateau";
	Word starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	dico = addWordRecursive(dico, starWord, 0);

	// dico = delete_word(dico, "A");

	Word testWord = "Bateau";
	
	if(wordBelongs(dico, testWord)) {
		printf("\"%s\" belongs to dico !", testWord);
	} else {
		printf("\"%s\" doesn't belong to dico", testWord);
	}

	printf("\n");

	return 0;
}