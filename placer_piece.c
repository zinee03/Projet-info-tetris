#include "header.h"

//----------Placement pièces-----------------
int placer_piece(char plateau_joueur[TAILLE][TAILLE],Piece i,int c){ //la variable c prise en paramètre représentera la colonne ou la piece sera placée
	int a,z,j,k,l,y,o,minimum;
	int min[i.largeur]; //création tableau qui va contenir les différents minimum des colonnes concernées par le placement de la piece 
	int hauteur; //hauteur à laquelle la piece va être placée dans le tableau
	hauteur=0;
	
	// recherche minimum ('@' le plus haut) par colonne
	for (y=c;y<i.largeur+c;y++){
		a=0;
		while ((plateau_joueur[a][y]==' ') && a<9){
			a++;
		}
		
		a--;
		
		if(i.forme[0][y-c]==' '){
			hauteur ++;
			if(i.forme[1][y-c]==' '){
				hauteur++;
			}
		}
		a=a+hauteur;
		if(a>8){
		    a=8;
		}
    
		min[y-c]=a; // on place le minimum de chaque colonne concernée dans la case du tableau min
		
		
	}
    //comparaison des différents minimum et dédution du minimum général
    
	minimum=min[0];
	for (o=0;o<i.largeur;o++){
			if(minimum>min[o]){
				minimum=min[o];
				
				}
		}
	
	//placement de la pièce
	if (minimum-i.hauteur<0){ //condition vérifiant si la pièce ne dépasse pas le tableau
		return 1;
	}
	
	a=0;
	for (z=0;z<i.hauteur;z++){ //si la pièce ne dépasse pas du tableau alors on la place dans la grille
		for (j=c;j<(c+i.largeur);j++){
			if (i.forme[z][a]=='@'){
				plateau_joueur[minimum-z][j]='@';
			}
			
			a++;
		}
		a=0; 
	}
	return 0;
}