#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
#include <time.h>
void initialiser_leon(hero *leon){
		
		leon->afficher_hero[0]=NULL;
		leon->afficher_hero[1]=NULL;
		leon->afficher_hero[2]=NULL;
		leon->afficher_hero[3]=NULL;
		leon->afficher_hero[4]=NULL;
		leon->afficher_hero[5]=NULL;
		leon->afficher_hero[6]=NULL;
		leon->afficher_hero[7]=NULL;
		leon->afficher_hero[8]=NULL;

		leon->afficher_herod[0]=NULL;
		leon->afficher_herod[1]=NULL;
		leon->afficher_herod[2]=NULL;
		leon->afficher_herod[3]=NULL;
		leon->afficher_herod[4]=NULL;
		leon->afficher_herod[5]=NULL;
		leon->afficher_herod[6]=NULL;
		leon->afficher_herod[7]=NULL;
		leon->afficher_herod[8]=NULL;
                
                leon->afficher_hit=NULL;


		leon->afficher_hero[0]=IMG_Load("1.png");
		leon->afficher_hero[1]=IMG_Load("2.png");
		leon->afficher_hero[2]=IMG_Load("3.png");
		leon->afficher_hero[3]=IMG_Load("4.png");
		leon->afficher_hero[4]=IMG_Load("5.png");
		leon->afficher_hero[5]=IMG_Load("6.png");
		leon->afficher_hero[6]=IMG_Load("7.png");
		leon->afficher_hero[7]=IMG_Load("8.png");
		leon->afficher_hero[8]=IMG_Load("9.png");

		leon->afficher_herod[0]=IMG_Load("j1.png");
		leon->afficher_herod[1]=IMG_Load("j2.png");
		leon->afficher_herod[2]=IMG_Load("j3.png");
		leon->afficher_herod[3]=IMG_Load("j4.png");
		leon->afficher_herod[4]=IMG_Load("j5.png");
		leon->afficher_herod[5]=IMG_Load("j6.png");
		leon->afficher_herod[6]=IMG_Load("j7.png");
		leon->afficher_herod[7]=IMG_Load("j8.png");
		leon->afficher_herod[8]=IMG_Load("j9.png");
			
                leon->afficher_hit=IMG_Load("hit.png");

		leon->afficher_vie[0]=IMG_Load("vie0.png");
		leon->afficher_vie[1]=IMG_Load("vie1.png");
		leon->afficher_vie[2]=IMG_Load("vie2.png");
		leon->afficher_vie[3]=IMG_Load("vie3.png");
	
	leon->vie=3;

	leon->farm=0;
	leon->hit=0;
	
	leon->pos_hero2.x=0;
	leon->pos_hero2.y=0;
	leon->pos_vie.y=0;
	leon->pos_vie.x=0;
	leon->heromoved=0;

	leon->vx =leon->vy = 0.0f;
}
void afficher_leon(hero leon,SDL_Surface *ecran){
	if ((leon.mouvment==1)||(leon.mouvment==9))
		SDL_BlitSurface(leon.afficher_hero[leon.farm],NULL,ecran,&(leon.pos_hero2));
	if (leon.mouvment==2)
		SDL_BlitSurface(leon.afficher_herod[leon.farm],NULL,ecran,&(leon.pos_hero2));
	if (leon.mouvment==3)
		SDL_BlitSurface(leon.afficher_hero[0],NULL,ecran,&(leon.pos_hero2));
                    
        if (leon.mouvment==7)
		SDL_BlitSurface(leon.afficher_hit,NULL,ecran,&(leon.pos_hero2));
}
