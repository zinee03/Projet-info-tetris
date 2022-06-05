#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>   //Définition des différentes bibliothèques qui vont servir à notre code
#define TAILLE 10       //Cette constante va définir la taille des colonnes et lignes du tableau

typedef struct{     //definition de la structure qui servira aux pièces
		int hauteur;    //hauteur de la pièce
		int largeur;    //largeur de la pièce
		char **forme;   //étage de la pièce
	}Piece;

void vide_buffer();
unsigned long getTimeMicroSec();
void InitPlateau(char plateau[TAILLE][TAILLE]);
void affichePlateau(char plateau[TAILLE][TAILLE]);
int placer_piece(char plateau_joueur[TAILLE][TAILLE],Piece i,int c);
void affiche_orien(Piece tabPiece[7][4], int piece);
int choix_piece(char plateau_joueur[TAILLE][TAILLE],Piece tabPiece[7][4],int tour);
int ligne(char plateau_joueur[TAILLE][TAILLE]);
int partie(char plateau_joueur[TAILLE][TAILLE], Piece tabPiece[7][4]);
