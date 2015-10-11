typedef struct node {
	char character;
	struct node *leftSon, *rightBrother;
}*Dictionary;

typedef char* Word;
// typedef enum {false, true} Boolean;

Dictionary createDictionary();
Dictionary createLetter(char letter);
int emptyDico(Dictionary dico);
int wordBelongs(Dictionary dico, char word[50]);
Dictionary addWord(Dictionary dico, Word word);