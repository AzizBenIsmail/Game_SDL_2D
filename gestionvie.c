#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
#include <time.h>
#include <unistd.h>

void affichiervie(hero evan, SDL_Surface *ecran){
	SDL_BlitSurface(evan.afficher_vie[evan.vie],NULL,ecran,&evan.pos_vie);
}
int gestionvie(hero *evan, SDL_Surface *ecran){
	
	
	if((evan->hit==1)&&(evan->vie!=0)){
		evan->vie--;
	affichiervie(*evan,ecran);
	SDL_Flip(ecran);
	usleep(1000000);
	evan->pos_hero2.y=50;
	
	}
	evan->hit=0;
	if (evan->vie==0)
	return 0;
	else return 1;

}
