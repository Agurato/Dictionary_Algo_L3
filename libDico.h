typedef struct node {
	char character;
	struct node *leftSon, *rightBrother;
}*Dictionary;

typedef char* Word;
typedef enum {false, true} Boolean;

Dictionary createDictionary();
Dictionary createLetter(char letter);
Boolean emptyDico(Dictionary dico);
Boolean wordBelongs(Dictionary dico, Word word);
Dictionary addWord(Dictionary dico, Word word);