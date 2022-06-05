
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>   //définition des différentes bibliothèques qui vont servir à notre code
#define TAILLE 10       //cette constante va définir la taille des colonnes et lignes du tableau
    
    
typedef struct{     //definition de la structure qui servira aux pièces
		int hauteur;    //hauteur de la pièce
		int largeur;    //largeur de la pièce
		char **forme;   //étage de la pièce
	}Piece;
    
void vide_buffer(){ //fonction permettant d'éviter les erreurs durant les scanf
	while(getc(stdin)!='\n'){
	}
}
    
unsigned long getTimeMicroSec(){struct timeval tv;gettimeofday(&tv,NULL);return (1000000 * tv.tv_sec) + tv.tv_usec;}
//initialisation de la fonction qui va permettre de gérer le temps que diposera le joueur pour placer sa piece
    
    
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

    
//--------------Affichage tableau----------------------
void affichePlateau(char plateau[TAILLE][TAILLE]){
	int i,j;
	char c;
	printf("\nVoici votre grille :\n\n");
	printf(" ");
	for (c='0';c< ('0'+TAILLE);c++){	//boucle affichant les indices des colonnes (0-9)
		printf("%c ", c);
	}
	printf("\n");
	for (i=0;i<TAILLE-1;i++){   //double boucle for pour afficher les caractères contenus dans le tableau
		for (j=0;j<TAILLE;j++){
			printf("|");
			printf("%c",plateau[i][j]);
		}
		
		printf("|\n");
	}
	printf("\n");
		
}

    
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
    
    
    
int partie(char plateau_joueur[TAILLE][TAILLE], Piece tabPiece[7][4]){ //fonction qui va simuler une partie
	int i,j,score,perdu,tour,rep;
	char pseudo[50];    //tableau de caracteres qui va contenir le pseudo du joueur
	FILE *f;
	f=fopen("resultat.txt","w");
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
        fprintf(f,"%s ---> %d points\t", pseudo, score);
        fclose(f);
        return 0;
    }
}
    
    
int main(){
	Piece tabPiece[7][4];   //création tableau qui va contenir toutes les pieces et toutes les orientations
	
	Piece i1;    	//creation piece 1 orientation 1
	i1.hauteur=4;
	i1.largeur=1;
	i1.forme=malloc(i1.hauteur*sizeof(char*));
	i1.forme[0]=("@");
	i1.forme[1]=("@");
	i1.forme[2]=("@");
	i1.forme[3]=("@");
    	
	Piece i2;		//creation piece 1 orientation 2
	i2.hauteur=1;
	i2.largeur=4;
	i2.forme=malloc(i2.hauteur*sizeof(char*));
	i2.forme[0]=("@@@@@");
	tabPiece[0][0]=i1; //on remplit pour chque piece le tableau de pieces
	tabPiece[0][1]=i2;
	tabPiece[0][2]=i1;
	tabPiece[0][3]=i2;
    	
    Piece o;		//creation piece 2 orientation 1
	o.hauteur=2;
    o.largeur=2;
    o.forme=malloc(o.hauteur*sizeof(char*));
	o.forme[0]=("@@");
	o.forme[1]=("@@");
	tabPiece[1][0]=o;
	tabPiece[1][1]=o;
	tabPiece[1][2]=o;
	tabPiece[1][3]=o;
    	
    
    Piece t;    	//creation piece 3 orientation 1
    t.hauteur=2;
    t.largeur=3;
    t.forme=malloc(t.hauteur*sizeof(char*));
    t.forme[0]=("@@@");
    t.forme[1]=(" @ ");
    Piece t2;		//creation piece 3 orientation 2
    t2.hauteur=2;
    t2.largeur=3;
    t2.forme=malloc(t2.hauteur*sizeof(char*));
    t2.forme[0]=(" @ ");
    t2.forme[1]=("@@@");
	Piece t3;    	//creation piece 3 orientation 3
	t3.hauteur=3;
	t3.largeur=2;
	t3.forme=malloc(t3.hauteur*sizeof(char*));
	t3.forme[0]=("@ ");
	t3.forme[1]=("@@");
	t3.forme[2]=("@ ");
	Piece t4;		//creation piece 3 orientation 4
	t4.hauteur=3;
	t.largeur=2;
	t4.forme=malloc(t4.hauteur*sizeof(char*));
	t4.forme[0]=(" @");
	t4.forme[1]=("@@");
	t4.forme[2]=(" @");
	tabPiece[2][0]=t;
	tabPiece[2][1]=t2;
	tabPiece[2][2]=t3;
	tabPiece[2][3]=t4;  
    	
	Piece l;    	//creation piece 4 orientation 1
    l.hauteur=2;
	l.largeur=3;
	l.forme=malloc(l.hauteur*sizeof(char*));
	l.forme[0]=("@  ");
	l.forme[1]=("@@@");
	Piece l2;		//creation piece 4 orientation 2
	l2.hauteur=3;
	l2.largeur=2;
	l2.forme=malloc(l2.hauteur*sizeof(char*));
	l2.forme[0]=(" @");
	l2.forme[1]=(" @");
	l2.forme[2]=("@@");
	Piece l3;    	//creation piece 4 orientation 3
	l3.hauteur=2;
	l3.largeur=3;
	l3.forme=malloc(l3.hauteur*sizeof(char*));
	l3.forme[0]=("@@@");
	l3.forme[1]=("  @");
	Piece l4;		//creation piece 4 orientation 4
	l4.hauteur=3;
	l4.largeur=2;
	l4.forme=malloc(l4.hauteur*sizeof(char*));
	l4.forme[0]=("@@");
	l4.forme[1]=("@ ");
	l4.forme[2]=("@ ");
	tabPiece[3][0]=l;
    tabPiece[3][1]=l2;
	tabPiece[3][2]=l3;
	tabPiece[3][3]=l4;
	
	Piece j1;    	//creation piece 5 orientation 1
	j1.hauteur=2;
	j1.largeur=3;
	j1.forme=malloc(j1.hauteur*sizeof(char*));
	j1.forme[0]=("  @");
    j1.forme[1]=("@@@");
    Piece j2;		//creation piece 5 orientation 2
    j2.hauteur=3; 
    j2.largeur=2;
	j2.forme=malloc(j2.hauteur*sizeof(char*));
	j2.forme[0]=("@@");
	j2.forme[1]=(" @");
	j2.forme[2]=(" @");
	Piece j3;    	//creation piece 5 orientation 3
	j3.hauteur=2;
	j3.largeur=3;
	j3.forme=malloc(j3.hauteur*sizeof(char*));
	j3.forme[0]=("@@@");
	j3.forme[1]=("@  ");
	Piece j4;		//creation piece 5 orientation 4
	j4.hauteur=3;
	j4.largeur=2;
	j4.forme=malloc(j4.hauteur*sizeof(char*));
	j4.forme[0]=("@ ");
	j4.forme[1]=("@ ");
	j4.forme[2]=("@@");
	tabPiece[4][0]=j1;
	tabPiece[4][1]=j2;
	tabPiece[4][2]=j3;
	tabPiece[4][3]=j4;
	
	Piece z;    	//creation piece 6 orientation 1
	z.hauteur=2;
	z.largeur=3;
	z.forme=malloc(z.hauteur*sizeof(char*));
    z.forme[0]=(" @@");
    z.forme[1]=("@@ ");
	Piece z2;		//creation piece 6 orientation 2
	z2.hauteur=3;
	z2.largeur=2;
	z2.forme=malloc(z2.hauteur*sizeof(char*));
	z2.forme[0]=("@ ");
	z2.forme[1]=("@@");
	z2.forme[2]=(" @");
	tabPiece[5][0]=z;
	tabPiece[5][1]=z2;
	tabPiece[5][2]=z;
	tabPiece[5][3]=z2;
	
	Piece s;    	//creation piece 7 orientation 1
	s.hauteur=2;
	s.largeur=3;
	s.forme=malloc(s.hauteur*sizeof(char*));
	s.forme[0]=("@@ ");
	s.forme[1]=(" @@");
	Piece s2;		//creation piece 7 orientation 2
	s2.hauteur=3;
	s2.largeur=2;
	s2.forme=malloc(s2.hauteur*sizeof(char*));
	s2.forme[0]=(" @");
	s2.forme[1]=("@@");
	s2.forme[2]=("@ ");
	tabPiece[6][0]=s;
	tabPiece[6][1]=s2;
	tabPiece[6][2]=s;
	tabPiece[6][3]=s2;
    	
   	char plateau_joueur[TAILLE][TAILLE];
    partie(plateau_joueur,tabPiece);
   	
    return 0;
}