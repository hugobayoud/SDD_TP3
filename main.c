#include "arbre.h"

int main(void){
    noeud_t *arbre = NULL;
    char *mot;

    FILE *fic;
    fic = fopen("dico.txt", "r");
    if (fic == NULL) {
        printf("Erreur ouverture du fichier\n");
    }else {
        fgets(mot, MAX, fic);
        //insertion(mot, &arbre); 
        // while (fgets(mot, MAX, fic)) {
        //     if (mot[strlen(mot)-1] == '\n') {
        //         mot[strlen(mot)-1] = '\0'; 
        //     }
        //     printf("%s\n", mot);
        //     insertion(mot, &arbre);                                                                    
        // }                                                    
        fclose(fic);
    }
    afficherArbre(arbre);
    return 0;
}
