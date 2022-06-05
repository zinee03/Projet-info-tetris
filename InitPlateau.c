#include "header.h"

//---------------Ecran d'accueil et création tableau de jeu----------------------
void InitPlateau(char plateau[TAILLE][TAILLE]){ 
	int i,j;
	printf(" _______ _______ ______ _____  _____  _____\n");  
 	printf("|__   __|  ____|__   __|  __ ||_   _|/ ____|\n");
	printf("   | |  | |__     | |  | |__)|  | |  |(___\n");  
	printf("   | |  |  __|    | |  |  _  |  | |  |___ | \n"); 
	printf("   | |  | |____   | |  | | | | _| |_ ____) |\n");
	printf("   |_|  |______|  |_|  |_| |_||_____|_____/\n");
	printf("\n\n");
	printf("Bienvenue !\n");
	
	for (i=0;i<TAILLE;i++){ //double boucle for pour créer les colonnes et lignes du tableau de jeu 
		for (j=0;j<TAILLE;j++){
			plateau[i][j]=' '; // cases vides remplies par des espaces
		}
	}
}