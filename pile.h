#ifndef PILE_H
#define PILE_H
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"

typedef  noeud_t* type;

typedef struct pile{
    int taille;
    int nbelt;
    type* base;
}pile_t;

pile_t* initPile(int taille);
int pileEstPleine(pile_t* pile);
int pileEstVide(pile_t* pile);
void empiler(pile_t* pile, type valeur);
type depiler(pile_t* pile);
void afficherPileInt(pile_t* pile);
void afficherPileArbre(pile_t* pile);
void libererPile(pile_t* pile);

#endif