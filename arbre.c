#include "arbre.h"
#include "pile.h"

/* ----------------------------------------------------------------- */ 
/* 
recherche

Algorithme de principe :  
Renvoie l'adresse du pointeur à modifier pour réaliser l'insertion

En entrée: un pointeur sur une chaîne de caractères (mot), un pointeur de pointeur sur un noeud (arbre)

En Sortie: un pointeur sur le pointeur sur un noeud

lexique : 
prec : pointeur de pointeur sur un noeud
cour : pointeur sur un noeud
*/
/* ----------------------------------------------------------------- */
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
            if (**mot == '\0') {
                cour->lettre = toupper(cour->lettre); /*Si le mot est fini on met une majuscule a la lettre deja existante*/
            }
            prec = &(cour->lv);
            cour = cour->lv;
        }else {
            run = 0;
        }
    }
    return prec;    
}
 
/* ----------------------------------------------------------------- */ 
/* 
insertion

Algorithme de principe :  
Renvoie l'adresse du pointeur à modifier pour réaliser l'insertion

En entrée: une chaîne de caractères (mot), un pointeur de pointeur sur un noeud (arbre)

En Sortie: un pointeur sur le pointeur sur un noeud

lexique : 
tmp : pointeur sur un noeud
prec : pointeur de pointeur sur un noeud
*/
/* ----------------------------------------------------------------- */
void insertion(char *mot, noeud_t **arbre){
    noeud_t *tmp = NULL;
    noeud_t **prec = recherche(&mot, arbre);

    while (*mot != '\0') {
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

/* ----------------------------------------------------------------- */ 
/* 
afficherArbre

Algorithme de principe :  
Affiche l'intégralité des mots du dictionnaire

En entrée: un pointeur sur l'arbre

En Sortie: 

lexique :
cour : pointeur sur noeud
pile : pointeur sur une pile
*/
/* ----------------------------------------------------------------- */
void afficherArbre(noeud_t *arbre) {
    noeud_t *cour = arbre;
    pile_t *pile = initPile(MAX);
    int run = 1;

    printf("\n       Affichage des mots du dictionnaire\n");

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
    libererPile(pile);  
}

/* ----------------------------------------------------------------- */ 
/* 
rechercheMotif

Algorithme de principe :  
Affiche les mots du dictionnaire qui commencent par un certain motif

En entrée: un pointeur sur l'arbre, une chaîne de caractères

En Sortie: 

lexique :
cour : pointeur sur noeud
pile : pointeur sur une pile
*/
/* ----------------------------------------------------------------- */
void rechercheMotif(noeud_t *arbre, char *motif) {
    char *tmp = motif;
    noeud_t **prec = recherche(&motif, &arbre);
    afficherArbreMotif(*prec, tmp);
}

/* ----------------------------------------------------------------- */ 
/* 
rechercheMotif

Algorithme de principe :  
Affiche les mots du dictionnaire en ajoutant un certain motif devant chaque mots

En entrée: un pointeur sur l'arbre (arbre), une chaîne de caractères (motif)

En Sortie: 

lexique :
cour : pointeur sur noeud
pile : pointeur sur une pile
*/
/* ----------------------------------------------------------------- */
void afficherArbreMotif(noeud_t *arbre, char *motif) {
    noeud_t *cour = arbre;
    pile_t *pile = initPile(MAX);
    int run = 1;

    printf("\n       Affichage des mots commençant par le motif : %s\n", motif);

    while (run) {
        while (cour != NULL) {
            empiler(pile, cour);
            if (cour->lettre >= 65 && cour->lettre <= 90) {
                printf("%s", motif);
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
    libererPile(pile); 
}


/* ----------------------------------------------------------------- */ 
/* 
creerNoeud

Algorithme de principe :  
créer une cellule noeud à partir d'un caractère (lettre)

En entrée: un caractère (lettre)

En Sortie: un pointeur sur une cellule noeud (noeud)

lexique :

*/
/* ----------------------------------------------------------------- */
noeud_t* creerNoeud(char lettre){
    noeud_t *noeud = malloc(sizeof(noeud_t));
    if (noeud != NULL) {
        noeud->lettre = lettre;
        noeud->lh = NULL;
        noeud->lv = NULL;
    } else {
        printf("erreur malloc\n");
    }
    return noeud;
}

/* ----------------------------------------------------------------- */ 
/* 
libererArbre

Algorithme de principe :  
libère l'intégralité des noeuds de l'arbre

En entrée: un pointeur sur l'arbre (arbre)

En Sortie: un pointeur sur une cellule noeud (noeud)

lexique :
cour : pointeur sur un noeud
tmp : pointeur sur un noeud
pile : pointeur sur une pile

*/
/* ----------------------------------------------------------------- */
void libererArbre(noeud_t *arbre) {
    noeud_t *cour = arbre;
    noeud_t *tmp = NULL;
    pile_t *pile = initPile(MAX);
    int run = 1;
    while (run) {
        while (cour != NULL) {
            empiler(pile, cour);
            cour = (cour->lv);            
        }
        if (!pileEstVide(pile)) {
            cour = depiler(pile);
            tmp = cour;
            cour = cour->lh;
            free(tmp);
        } else {
            run = 0;
        }
    }
    libererPile(pile); 
}
