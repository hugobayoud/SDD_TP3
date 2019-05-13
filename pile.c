#include "pile.h"

/* ----------------------------------------------------------------- */
/* initPile                                                          */
/*                                                                   */
/* Algorithme de principe :                                          */
/* Initialise une pile et ses variables et alloue de la mémoire pour */
/* la structure                                                      */
/*                                                                   */
/* En entrée: un entier taille                                       */
/*                                                                   */
/* En sortie: un pointeur sur la pile                                */
/*                                                                   */
/* Lexique :                                                         */
/* -pile : pointeur sur la pile                                      */
/* -taille : taille de la pile                                       */
/* -nbelt : nombre d'elements de la pile                             */
/* -base : tableau d'elements de n'importe quel type                 */
/* ------------------------------------------------------------------*/
pile_t* initPile(int taille){
    pile_t* pile = malloc(sizeof(pile_t));    /*alloue la mémoire nécessaire pour la pile*/
    pile->taille = taille;
    pile->nbelt = 0;
    pile->base = malloc(taille*sizeof(type)); /*alloue la mémoire pour le tableau d'elements de la pile*/
    return pile;
}

/* ----------------------------------------------------------------- */
/* pileEstPleine                                                     */
/*                                                                   */
/* Algorithme de principe :                                          */
/* Fonction qui test si la pile est pleine en comparant sa taille et */
/* son nombre d'elements                                             */
/*                                                                   */
/* En entrée: un pointeur sur la pile                                */
/*                                                                   */
/* En sortie: un entier qui represente un booléen, le retour est de 1*/	
/* si la pile est pleine et de 0 sinon                               */
/*                                                                   */
/* Lexique :                                                         */
/* -res : variable qui stocke le resultat                            */
/* ------------------------------------------------------------------*/
int pileEstPleine(pile_t* pile){
    int res = 1;
    if (pile->nbelt < pile->taille){
        res = 0;
    }
    return res;
}


/* ----------------------------------------------------------------- */
/* pileEstVide                                                       */
/*                                                                   */
/* Algorithme de principe :                                          */
/* Fonction qui test si la pile est vide en regardant son nombre     */
/* d'elements                                                        */
/*                                                                   */
/* En entrée: un pointeur sur la pile                                */
/*                                                                   */
/* En sortie: un entier qui represente un booléen, le retour est de 1*/	
/* si la pile est vide et de 0 sinon                                 */
/*                                                                   */
/* Lexique :                                                         */
/* -res : variable qui stocke le resultat                            */
/* ------------------------------------------------------------------*/
int pileEstVide(pile_t* pile){
    int res = 0;
    if (pile->nbelt == 0){
        res = 1;
    }
    return res;
}

/* ----------------------------------------------------------------- */
/* empiler                                                           */
/*                                                                   */
/* Algorithme de principe :                                          */
/* Empile une valeur ou renvoie un message d'erreur si la pile est   */
/* pleine                                                            */
/*                                                                   */
/* En entrée: un pointeur sur la pile, une valeur de n'importe quel  */
/* type                                                              */
/*                                                                   */
/* En sortie :                                                       */	
/*                                                                   */
/* Lexique :                                                         */
/* ------------------------------------------------------------------*/
void empiler(pile_t* pile, type valeur){
    if (!pileEstPleine(pile)){
        pile->base[pile->nbelt] = valeur;
        pile->nbelt++;
    }
    else{
        printf("empilement impossible car la pile est pleine !\n");
    }
}

/* ----------------------------------------------------------------- */
/* depiler                                                           */
/*                                                                   */
/* Algorithme de principe :                                          */
/* Depile une valeur et retourne sa valeur ou renvoie un message     */
/* d'erreur si la pile est vide                                      */
/*                                                                   */
/* En entrée: un pointeur sur la pile                                */
/*                                                                   */
/* En sortie: une valeur de n'importe quel type	                     */	
/*                                                                   */
/* Lexique :                                                         */
/* -res : variable qui stocke le resultat                            */
/* ------------------------------------------------------------------*/
type depiler(pile_t* pile){
    type res = NULL;
    if (!pileEstVide(pile)){
        res = pile->base[pile->nbelt-1];        
	    pile->nbelt--;
    }
    else{
        printf("depilement impossible car la pile est vide !\n");
    }
    return res;
}

/* ----------------------------------------------------------------- */
/* afficherPile                                                      */
/*                                                                   */
/* Algorithme de principe :                                          */
/* Affiche le contenu d'une pile en bouclant sur le nombre d'elements*/
/*                                                                   */
/* En entrée: un pointeur sur la pile                                */
/*                                                                   */
/* En sortie:                                                        */	
/*	                                                                 */
/* Lexique :                                                         */
/* -i : variable d'incrémentation de la boucle for                   */
/* ------------------------------------------------------------------*/
/*void afficherPileInt(pile_t* pile){
    if(!pileEstVide(pile)){
        int i;
        printf("Affichage de la pile :\n");
   	    for (i = 0; i < pile->nbelt; i++){
            printf("element %d : %d\n", i, pile->base[i]);
        }
    }else{
	printf("la pile est vide\n");
    }
}*/

void afficherPileArbre(pile_t* pile){
    int i;
    for (i = 0; i < pile->nbelt; i++){
        printf("%c", tolower((pile->base[i])->lettre));
    }
    printf("\n");
}

/* ----------------------------------------------------------------- */
/* libererPile                                                       */
/*                                                                   */
/* Algorithme de principe :                                          */
/* Libere l'espace alloué pour la pile en liberant d'abord le tableau*/
/* d'elements puis la structure de la pile	                         */
/*                                                                   */
/* En entrée: un pointeur sur la pile                                */
/*                                                                   */
/* En sortie:                                                        */	
/*                                                                   */
/* Lexique :                                                         */
/* ------------------------------------------------------------------*/
void libererPile(pile_t* pile){
    free(pile->base);
    free(pile);
}
