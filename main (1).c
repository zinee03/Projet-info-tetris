#include "header.h"

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