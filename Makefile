all : exec

main.o : main.c header.h
	gcc -c main.c -o main.o

vide_buffer.o : vide_buffer.c header.h
	gcc -c vide_buffer.c -o vide_buffer.o

getTimeMicroSec.o : getTimeMicroSec.c header.h
	gcc -c getTimeMicroSec.c -o getTimeMicroSec.o

InitPlateau.o : InitPlateau.c header.h
	gcc -c InitPlateau.c -o InitPlateau.o

affichePlateau.o : affichePlateau.c header.h
	gcc -c affichePlateau.c -o affichePlateau.o

placer_piece.o : placer_piece.c header.h
	gcc -c placer_piece.c -o placer_piece.o

affiche_orien.o : affiche_orien.c header.h
	gcc -c affiche_orien.c -o affiche_orien.o

choix_piece.o : choix_piece.c header.h
	gcc -c choix_piece.c -o choix_piece.o

ligne.o : ligne.c header.h
	gcc -c ligne.c -o ligne.o

partie.o : partie.c header.h
	gcc -c partie.c -o partie.o