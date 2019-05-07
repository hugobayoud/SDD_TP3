#include "arbre.h"
#include "pile.h"
 
noeud_t** recherche(char **mot, noeud_t **arbre){
    noeud_t **prec = arbre;
    noeud_t  *cour = *arbre;
    
    int run = 1;
    while (run) {
        while ((cour != NULL) && (**mot > tolower(cour->lettre))) {
            prec = &(cour->lh);
            cour = cour->lh;
        }
        if (cour != NULL && tolower(cour->lettre) == **mot) {
            *mot = (*mot + 1);
            if (**mot == '\0') cour->lettre = toupper(cour->lettre); /*Si le mot est fini on met une majuscule a la lettre deja existante*/
            printf("current letter : %c\n", cour->lettre);
            prec = &(cour->lv);
            cour = cour->lv;
        }else {
            run = 0;
        }
    }
    return prec;    
}
 
 
void insertion(char *mot, noeud_t **arbre){
    noeud_t *tmp = NULL;
    noeud_t **prec = recherche(&mot, arbre);

    while (*mot != '\0') {
        printf("writing letter : %c\n", *mot);

        tmp = *prec;                                    /*On sauvegarde un eventuel lien (tmp pointe vers Null si il n'y en a pas)*/
        *prec = creerNoeud(*mot);
        (*prec)->lh = tmp;

        mot = (mot+1);
        if (*mot == '\0') {
            (*prec)->lettre = toupper((*prec)->lettre); /*On regarde si le mot est fini et si oui on met une majuscule (sinon on déplace prec)*/
        } else {
            prec = &((*prec)->lv);
        }
    }

}

void afficherArbre(noeud_t *arbre) {
    noeud_t *cour = arbre;
    pile_t *pile = initPile(MAX);
    int run = 1;
    while (run) {
        while (cour != NULL) {
            empiler(pile, cour);
            if (cour->lettre >= 65 && cour->lettre <= 90) {
                afficherPileArbre(pile);
            }
            cour = (cour->lv);
        }
        if (!pileEstVide(pile)) {
            cour = depiler(pile);
            cour = cour->lh;
        } else {
            run = 0;
        }
    }   
}
 
noeud_t* creerNoeud(char lettre){
    noeud_t *noeud = malloc(sizeof(noeud_t));
    noeud->lettre = lettre;
    noeud->lh = NULL;
    noeud->lv = NULL;
    return noeud;
}
