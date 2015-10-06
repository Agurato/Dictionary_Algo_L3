typedef char* Word;
typedef enum('False', 'True') Boolean;
typedef struct noeud{
    char car;
    struct noeud *rightBrother, *leftSon;
}*Dictionnary

Dictionnary create_dictionnary();
Dictionnary add_word(Dictionnary, Word);
Dictionnary delete_word(Dictionnary, Word);
Boolean belongs_word(Dictionnary, Word);
Boolean void_dictionnary(Dictionnary);
void display_dictionnary(Dictionnary);
Dictionnary empty_dictionnary(Dictionnary);
Dictionnary save_dictionnary(Dictionnary);
Dictionnary load_dictionnary();
