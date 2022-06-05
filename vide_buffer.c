#include "header.h"

void vide_buffer(){ //fonction permettant d'éviter les erreurs durant les scanf
	while(getc(stdin)!='\n'){
	}
}