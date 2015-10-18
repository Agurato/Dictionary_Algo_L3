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
Dictionary displayDico(Dictionary dico, Word currentWord);
Dictionary addWordRecursive(Dictionary dico, Word word, int position);
Dictionary deleteWordRecursive(Dictionary dico, Word word, int position, Boolean deleting);
int lastBrotherPosition(Dictionary dico, Word word);
Dictionary addWord(Dictionary dico, Word word);
Dictionary last_letter(Dictionary dico, Word word);
Dictionary delete_word(Dictionary dictionary, Word word);
