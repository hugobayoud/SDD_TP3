#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
#include <string.h>

#define MAX 50
 
typedef struct noeud{
    char          lettre;
    struct noeud *lv;
    struct noeud *lh;
}noeud_t;
 
noeud_t** recherche(char **mot, noeud_t **arbre);
void insertion(char *mot, noeud_t **arbre);
noeud_t* creerNoeud(char lettre);
void afficherArbre(noeud_t *arbre);
void rechercheMotif(noeud_t *arbre, char *motif);
void afficherArbreMotif(noeud_t *arbre, char *motif);
void libererArbre(noeud_t *arbre);
 
#endif
