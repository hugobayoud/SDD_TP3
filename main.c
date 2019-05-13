#include "arbre.h"

int main(void){
    noeud_t *arbre = NULL;
    char mot[MAX];

    FILE *fic;
    fic = fopen("dico.txt", "r");
    if (fic == NULL) {
        printf("Erreur ouverture du fichier\n");
    }else {
        while (fgets(mot, MAX, fic)) {
            if (mot[strlen(mot)-1] == '\n') {
                mot[strlen(mot)-1] = '\0'; 
            }
            insertion(mot, &arbre);                                                                    
        }                                                    
        fclose(fic);
    }

    afficherArbre(arbre);

    printf("\n\n");
    rechercheMotif(arbre, "el");

    libererArbre(arbre);
    return 0;
}
