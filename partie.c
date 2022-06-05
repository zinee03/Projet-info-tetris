#include "header.h"

int partie(char plateau_joueur[TAILLE][TAILLE], Piece tabPiece[7][4]){ //fonction qui va simuler une partie
	int i,j,score,perdu,tour,rep;
	char pseudo[50];    //tableau de caracteres qui va contenir le pseudo du joueur
	FILE *f;
	f=fopen("resultat.txt","r");
	fprintf(f,"Tableau de score\n\n");
	perdu=0;
    score=0;
    tour=1; //variable s'incrémentant apres chaque tour et qui va permettre de diminuer le temps de choix au fur et a mesure des tours 
    InitPlateau(plateau_joueur);
    printf("Veuillez ecrire votre pseudo (50 caractères max)\n");
    scanf("%s", pseudo);
    printf("Bienvenue %s\n", pseudo);
   	affichePlateau(plateau_joueur);
	do{ 
	    printf("Tour n°%d\n", tour);
	    printf("Temps pour placer votre pièce: %d secondes\n", 121-tour);
	    printf("Veuillez placer votre piece\n");
	    printf("Attention le temps pour placer cette derniere diminue de 1 sec par tour!\n\n");
	    perdu=choix_piece(plateau_joueur,tabPiece,tour);
	    if (perdu==1){ //si le joueur perd, on arrete la partie 
	        break;
	    }
	    score+=10; // on ajoute 10 au score apres la placement de chaque piece
	    score=ligne(plateau_joueur)+score;
	    affichePlateau(plateau_joueur);
	    printf("Vous avez posé une piece: +10pts\n");
	    printf("score=%d\n\n", score);
	    tour+=1;
	}while(perdu==0);
	for (i=0;i<TAILLE;i++){ //si le joueur perd, on le lui fait comprendre en remplissant le tableau de '@' et en écrivant PERDU !
			for (j=0;j<TAILLE;j++){
				plateau_joueur[i][j]='@';
			}
	}
	affichePlateau(plateau_joueur);
	printf("PERDU !!!\nscore final: %s->%dpts\n", pseudo, score);
	printf("voulez vous rejouer ?\n1:OUI\n2:NON\n");
	scanf("%d",&rep);
	vide_buffer(); //on vérifie que linformation récupérée est un entier
    while(rep>2 || rep<1){ //on vérifie que la donnée est valide
    	printf("\n\nvoulez vous rejouer ?\n1:OUI\n2:NON\n");
    	scanf("%d",&rep);
    }
    if(rep==1){
        fprintf(f,"%s ---> %d points\t", pseudo, score);
        partie(plateau_joueur,tabPiece);
    }
    else{
        printf("\nLes scores de vos parties se trouvent dans le fichier resultat.txt");
        fprintf(f,"%s ---> %d pointP\t", pseudo, score);
        fclose(f);
        return 0;
    }
}