#include "header.h"

int choix_piece(char plateau_joueur[TAILLE][TAILLE],Piece tabPiece[7][4],int tour){
    int piece,perdu,a,b,c,d,e;
    srand(time(NULL));  //initialisation fonction qui va gérer le temps
    unsigned long t1=getTimeMicroSec(); //1ere prise de temps
    piece=rand()%7; //choix de la piece au hasard
    printf("Choisissez l'orientation de la piece \n");
    affiche_orien(tabPiece,piece); //on affiche les orientations et demande à l'utilisateur celle qu'il veut placer 
    scanf("%d", &c);
    vide_buffer(); //on vérifie que linformation récupérée est un entier
    while(c>4 || c<1){ //on vérifie que la donnée est valide
    	printf("\nOrientation ou colonne invalide, veuillez réessayer !\n");
    	affichePlateau(plateau_joueur);
    	choix_piece(plateau_joueur,tabPiece,tour);
    }
   c=c-1;
   printf("dans quelle colonne voulez vous mettre votre piece ?\n");
   scanf("%d", &d);
   unsigned long t2=getTimeMicroSec();  //2nde prise de temps apres que l'utilisateur ait placé sa piece
   while(d>9 || d<0){ //on vérifie que la donnée est valide
		printf("\nLa pièce ne rentre pas dans le tableau ou la saisie est invalide, veuillez réessayer !\n");
		affichePlateau(plateau_joueur);
		choix_piece(plateau_joueur,tabPiece,tour);
	}
	while((tabPiece[piece][c].largeur+d)>10){ //on vérifie que la donnée est valide
		printf("Pièce hors tableau !\n");
		affichePlateau(plateau_joueur);
    	choix_piece(plateau_joueur,tabPiece,tour);
    }
        
    if (t2-t1>(120000000-tour*1000000)){ // on soustrait les deux prises de temps pour obtenir le temps que l'utilisateur a mis pour placer sa piece et appliquer ou non un pénalité en conséquence
    	printf("Vous avez mis trop de temps !!!\nPiece et colonne choisies aléatoirement\n");
    	d=rand()%10;
    	c=rand()%4;
    }
   
     
    perdu=placer_piece(plateau_joueur,tabPiece[piece][c],d); //maintenant que nous savons ou placer la piece, on appelle ma seconde fonction pour la placer dans la grille
    return perdu;
}