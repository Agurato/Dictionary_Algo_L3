typedef struct node {
	char character;
	struct node *leftSon, *rightBrother;
	// struct node *father, *leftBrother;
}*Dictionary;

typedef char* Word;
typedef enum {false, true} Boolean;

Dictionary createDictionary();
Dictionary createLetter(char letter);
Boolean emptyDico(Dictionary dico);
Boolean wordBelongs(Dictionary dico, Word word);
Dictionary addWordRecursive(Dictionary dico, Word word, int position);
Dictionary addWord(Dictionary dico, Word word);
Dictionary last_letter(Dictionary dico, Word word);
Dictionary delete_word(Dictionary dictionary, Word word);
