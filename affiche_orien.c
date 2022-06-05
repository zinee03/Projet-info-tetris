#include "header.h"

void affiche_orien(Piece tabPiece[7][4], int piece){ //fonction qui va afficher les différentes orientations de la pièce
    int k,j;
   for(k=0;k<4;k++){
        printf("%d :\t\n",k+1);
        for(j=tabPiece[piece][k].hauteur-1;j>=0;j--){
            	printf("   %s\n",tabPiece[piece][k].forme[j]);
            }
        printf("\n");
    }
}