typedef struct node {
	char character;
	struct node *leftSon, *rightBrother, *father, *leftBrother;
}*Dictionary;

typedef char* Word;
typedef enum {false, true} Boolean;

Dictionary createDictionary();
Dictionary createLetter(char letter, Dictionary father);
Boolean emptyDico(Dictionary dico);
Boolean wordBelongs(Dictionary dico, Word word);
Dictionary addWord(Dictionary dico, Word word);
Dictionary last_letter(Dictionary dico, Word word);
Dictionary delete_word(Dictionary dictionary, Word word);
