#include "arbre.h"

int main(void){
    noeud_t *arbre = NULL;
    char *mot = NULL;

    FILE *fic;
    fic = fopen("dico.txt", "r");
    if (fic == NULL) {
        printf("erreur ouverture du fichier\n");
    }else {
        while (fgets(mot, MAX, fic)) {
            if (mot[strlen(mot)-1] == '\n') mot[strlen(mot)-1] = '\0'; 
            printf("%s\n", mot);
            insertion(mot, &arbre);
            afficherArbre(arbre);                                                                      
        }                                                      
        fclose(fic);
    }
    return 0;
}