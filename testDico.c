#include <stdio.h>
#include <stdlib.h>
#include "libDico.h"

int main(int argc, char const *argv[])
{
	Dictionary dico = createDictionary();
	dico = createLetter('A');
	dico->leftSon = createLetter('*');
	
	printf("dico created : ");

	if(emptyDico(dico)) {
		printf("NULL\n");
	} else {
		printf("%c", dico->character);
	}
	
	Word testWord = "A";
	// char testWord[50] = "test";
	printf("\ntestWord : %s\n", testWord);
	
	if(wordBelongs(dico, testWord)) {
		printf("\"%s\" belongs to dico !", testWord);
	} else {
		printf("\"%s\" doesn't belong to dico", testWord);
	}
	
	printf("\n");
	return 0;
}