typedef char* Word;
typedef enum('Faux', 'Vrai') Boolean;
typedef struct noeud{
    char car;
    struct noeud *rightBrother, *leftSon;
}*Dictionnary

Dictionnary create_dictionnary();
Dictionnary add_word(Dictionnary, Word);
Dictionnary delete_word(Dictionnary, Word);
Boolean belongs_word();
