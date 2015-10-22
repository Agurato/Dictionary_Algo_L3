#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libDico.h"

int main(int argc, char const *argv[])
{
	Dictionary dico = createDictionary();

	Word newWord = "Bateau";
	Word starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
	}

	newWord = "Avion";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
	}

	newWord = "Batiment";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
	}

	newWord = "Bataille";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
	}

	newWord = "Batman";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
	}

	newWord = "Bateaux";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
	}

	printf("\nDisplaying dictionary : \n\n");
	displayDico(dico, "");

	Word oldWord = "avion";
	starWord = malloc(strlen(oldWord) + 2);
	strcpy(starWord, oldWord);
	strcat(starWord, "*");
	if(wordBelongs(dico, oldWord)) {
		int lastBro = lastBrotherPosition(dico, oldWord);
		printf("lastBrotherPosition(dico, oldWord)=%d\n", lastBro);
		dico = deleteWordRecursive(dico, starWord, 0, lastBro);
		printf("\n");
	}

	printf("Displaying dictionary : \n\n");
	displayDico(dico, "");

	printf("\n");

	return 0;
}
