#include "header.h"

unsigned long getTimeMicroSec(){struct timeval tv;gettimeofday(&tv,NULL);return (1000000 * tv.tv_sec) + tv.tv_usec;}
//initialisation de la fonction qui va permettre de gérer le temps que diposera le joueur pour placer sa piece