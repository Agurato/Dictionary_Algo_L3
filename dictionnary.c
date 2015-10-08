#include "libDictionnaire.h"
#include <malloc.h>



Dictionnary create_dictionnary(){
    return NULL;
}

/*Add a word in the dictionnary if he doesn't exist*/
Dictionnary add_word(Dictionnary dictionnary, Word word){
/*Chercher dans un premier temps où il faut mettre le mot puis ajouter*/
    if(belongs_dictionnary(word)){
        write("0","The word already exist in the dictionnary",45);
    }
    else{


    }
    return dictionnary;
}

/* Search the word with belongs_word and delete the Word*/
Dictionnary delete_word(Dictionnary dictionnary, Word word){
/* Search the word
 * Delete it
 * return the new dictionnary
 */

}

/*If the word word belongs to the dictionnary return True else return False*/
Boolean belongs_word(Dictionnary dictionnary, Word word){



}

/*Is the dictionnary empty or not ?*/
Boolean void_dictionnary(Dictionnary dictionnary){
    return (dictionnary = NULL);
}

/*Display words that are in the dictionnary*/
void display_dictionnary(Dictionnary dictionnary){



}

/*If you don't want any more word in the dictionnaries use this function*/
Dictionnary empty_dictionnary(Dictionnary dictionnary){



}

/*Save a dictionnary in a file*/
int save_dictionnary(Dictionnary dictionnary){



}

/*Load dictionnary from a file*/
Dictionnary load_dictionnary(){


}
