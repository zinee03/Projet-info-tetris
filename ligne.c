#include "header.h"

int ligne(char plateau_joueur[TAILLE][TAILLE]){  //fonction qui va vérifier si le joueur a supprimé des lignes et les supprimer
    int i,j,k,nb,score;
    score=0;
    for (i=0;i<TAILLE;i++){
    	nb=0;
	    for (j=0;j<TAILLE;j++){
		    if (plateau_joueur[i][j]=='@'){
		        nb++; //variable s'incrémentant en fonction des '@' présents sur le ligne
		    }
		    if (nb==TAILLE){ //si la ligne est complete on la remplace par celle du dessus pour la faire disparaitre
			    score+=+100; //on ajoute un bonus au score lorsque l'on supprime une ligne
			    printf("\nFélicitations vous avez supprimé 1 ligne(s) +100pts\n");
		       	for(k=i;k>0;k--){
				    for (j=0;j<10;j++){
					    plateau_joueur[k][j]=plateau_joueur[k-1][j];
				    }
			    }
			    
		    }
	    }	
    }
    return score;
}