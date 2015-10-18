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
		printf("\n");
	}

	newWord = "Batiment";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
		printf("\n");
	}

	newWord = "Bataille";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
		printf("\n");
	}

	newWord = "Batailles";
	starWord = malloc(strlen(newWord) + 2);
	strcpy(starWord, newWord);
	strcat(starWord, "*");
	if(! wordBelongs(dico, newWord)) {
		dico = addWordRecursive(dico, starWord, 0);
		printf("\n");
	}

	printf("\n\nDisplaying dictionary : \n\n");
	displayDico(dico, "");

	printf("Bataille : last stage where brother = %d\n", lastBrotherPosition(dico, "Bataille"));
	printf("Batailles : last stage where brother = %d\n", lastBrotherPosition(dico, "Batailles"));
	printf("Bateau : last stage where brother = %d\n", lastBrotherPosition(dico, "Bateau"));
	printf("Batiment : last stage where brother = %d\n", lastBrotherPosition(dico, "Batiment"));

	/*
	Word oldWord = "Bateau";
	starWord = malloc(strlen(oldWord) + 2);
	strcpy(starWord, oldWord);
	strcat(starWord, "*");
	if(wordBelongs(dico, oldWord)) {
		dico = deleteWordRecursive(dico, starWord, 0, false);
		printf("\n");
	}
	
	printf("\n\nDisplaying dictionary : \n\n");
	displayDico(dico, "");
	*/
	printf("\n");

	return 0;
}