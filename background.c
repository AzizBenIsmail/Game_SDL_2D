#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
void initialiser_background(background *bckg){


	bckg->calque_background=NULL;
	bckg->calque_background=IMG_Load("calquebackground.png");

	bckg->afficher_background=NULL;
	bckg->afficher_background=IMG_Load("background.jpg");
	bckg->pos_background.x=0;
	bckg->pos_background.y=0;
	bckg->pos_background2.x=0;
	bckg->pos_background2.y=0;
	bckg->pos_background2.h=600;
	bckg->pos_background2.w=1200;
}
void afficher_background(background bckg,SDL_Surface *ecran){
	
	SDL_BlitSurface(bckg.afficher_background,&(bckg.pos_background2),ecran,&(bckg.pos_background));
	//printf("%d %d %d %d \n", bckg->pos_background2.x,bckg->pos_background2.y,bckg->pos_background2.h,bckg->pos_background2.w);
	//SDL_Flip(ecran);

}