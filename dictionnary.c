#include "libDictionnaire.h"
#include <malloc.h>



Dictionnary create_dictionnary(){
    return NULL;
}

/*Add a word in the dictionnary if he doesn't exist*/
Dictionnary add_word(Dictionnary dictionnary, Word word){
    if(dictionnary == NULL){
        dictionnary
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
    int numberLetters = sizeof(word);
    int currentLetter = 0;
    /*While we don't find a letter place after the research letter or the research letter is after and we can go at the right*/
    while(dictionnary->car < *(word+currentLetter) ||
            (dictionnary->car != *(word+currentLetters) && dictionnary->rightBrother != NULL)){
        if(dictionnary->car == *(word+currentLetter)){
            currentLetter++;
            dictionnary = dictionnary->leftSon;
        }
        else{
            dictionnary = dictionnary->rightBrother;
        }
    }
    if(dictionnary->car = '\0' && numberLetters == (currentLetter - 1))
        return True;
    else
        return False;
}

/*Is the dictionnary empty or not ?*/
Boolean void_dictionnary(Dictionnary dictionnary){
    return (dictionnary == NULL);
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
