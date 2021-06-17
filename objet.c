#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
void initialiser_objet(objet *chouka) {
	chouka->afficher_objet=NULL;
	chouka->afficher_objet=IMG_Load("s1.png");

	chouka->pos_objet.x=1000;
	chouka->pos_objet.y=0;
}



void afficher_objet(objet *chouka,SDL_Surface *ecran,hero evan){

	if (chouka->pos_objet.x==0){
			srand(time(NULL)); 
		chouka->pos_objet.x=(rand()%900)+450;  
		chouka->pos_objet.y=0;
	}
	if ((chouka->pos_objet.y<600)&&(evan.pos_hero2.x<=300)){
		if ((evan.heromoved==1)&&(evan.pos_hero2.x==300)){
			chouka->pos_objet.x=chouka->pos_objet.x-5;
				

				}
			chouka->pos_objet.y++;
			if (evan.heromoved==2){
				chouka->pos_objet.x=chouka->pos_objet.x+5;
			
			}


			
			
				chouka->pos_objet.y+=5;
	}

	else {
			srand(time(NULL)); 
		chouka->pos_objet.x=(rand()%900+300);  
		chouka->pos_objet.y=0;
	}
	if(evan.pos_hero2.x>100)
		SDL_BlitSurface(chouka->afficher_objet,NULL,ecran,&(chouka->pos_objet));
	else if (evan.pos_hero2.x>300)
		 chouka->afficher_objet=NULL;
}
