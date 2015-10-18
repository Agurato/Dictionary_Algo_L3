Dictionary save_dico(Dictionary dico, Word wordToSave, int position){
    /* Ouvrir le fichier de sauvegarde
     * Aller sur le fils gauche tant qu'on ne rencontre pas le caractère '*'
     * Sauvegarder les données dans un fichier
     * Aller sur le frère droit
     * C'est du parcours infixe
     */

    /* On regarde si ce n'est pas la fin du mot si non :
     * on sauvegarde la lettre dans un tableau de char
     * on incréamente l'indice d'un
     * on passe à la prochaine lettre en récursif ce qui fait que quand on aura fini avec ce mot on pourra passer au frère*/
    if(dico->leftSon != '*'){
        wordToSave[postion] = dico->car;
        position ++;
        dico = save_dico(dico->leftSon, wordtoSave, position);
        /*Placer ici l'algo pour sauver le mot*/
        int fd = open('./saveDictionary.save', O_WRONLY);
        write(fd,wordToSave,26);
        close(fd);
        /*Fin de l'algo*/
    }
    /*Si on a fini le mot on passe au frère droit*/
    else if(dico -> rightBrother != NULL)
        dico = save_dico(dico->rightBrother;

}

Dictionary load_dico(){
    /*Boucle while + addWord pour chaque mot*/
}
