#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include"struct.h"
void main(void)
{


	SDL_Surface *ecran =NULL,*gameover=NULL;
	hero evan;
	int continuer =1;
	objet chouka;
	
	background bckg;
	int k,a;
	
	menu menu;
	
	int coe;
	int c;
	Score score;
        Time time;
	

	
	//int i;
	SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();
    ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    initialiser_background(&bckg);
    initialiser_leon(&evan);
    initialiser_objet(&chouka);
    initialiser_menu(&menu);
    initialiserScore(&score);
    initializerTemps(&time);
   
    SDL_Event event;
	gameover=IMG_Load("gameover.png");
       evan.farm=0;
       

       Enemy e;
       int stat;
       int collision;
   
  
	
   e=InitEnemy(e,5500,350);
    //usleep(20000000);
	while(continuer){
		printf("%d\n",evan.mouvment);
		if (menu.action==1){
			 k=affcihier(&menu,ecran);
                          
			 SDL_Flip(ecran);
		}
		//SDL_Flip(ecran);
		if(menu.action==10){

			afficher_background(bckg,ecran);
			afficher_leon(evan,ecran);                      
			evan.farm=animation_perso(evan);               
		        afficher_objet(&chouka,ecran,evan);
                        afficherTemps(&time,ecran);
                        afficherScore(ecran ,&score,bckg,collision );      

		
			e=MoveEnemy(e,evan.pos_hero2,&stat,evan.heromoved);
			e=AnimateEnemy(e,stat);
			 AfficherEnemy(e,ecran);

			
			//printf("%d a\n",bckg.pos_background2.x);
			if (c==1)
				evan.hit=1;
			gestionvie(&evan,ecran);
			affichiervie(evan,ecran);
                        
			//affichiervie(evan,ecran);
			SDL_Flip(ecran);
			if(Collision_Bounding_Box (evan,chouka )==0){
				evan.hit=1;
				chouka.pos_objet.y=1000;
				SDL_Delay(1000);
			}
			coe=collision_Parfaiteennemie(bckg.calque_background,e.position,bckg.pos_background2);
			e=diedennemie(e,coe);
			if ((e.imageActuel==e.Hit)&&(e.died==0)){
				evan.hit=1;

				e.position.x=e.position.x+100;
			}
			if (menu.sousetatcontrole==1){
				evan.mouvment= mouvment(evan,&event);
			}
			



			if (evan.mouvment==0){
				continuer=0;
			}
			if (evan.mouvment==100){
				menu.action=100;
				}
				scrolling(&evan,&bckg,c);
			
			
			

				c=collision_Parfaite(bckg.calque_background,evan.afficher_hero[evan.farm],evan.pos_hero2,bckg.pos_background2);
//printf("%d  cc\n",a);
		if (evan.vie==0){
			SDL_BlitSurface(gameover,NULL,ecran,&bckg.pos_background);
			SDL_Flip(ecran);
			usleep(3000000);
			menu.action=1;
		initialiser_background(&bckg);
    	        initialiser_leon(&evan);
   		initialiser_objet(&chouka);
		
	}
	
	SDL_Delay(20);
		}
	

	}
	if (menu.action==100){

		menu.action=affcihiersousmenuingame(&menu,ecran);
		SDL_Flip(ecran);
		//evan.mouvment=9;
		SDL_Delay(19);
	}

		if(menu.action==0)	{
			//sauvegarde ("sauvegarde.bin");
			continuer=0;
		}
	
}
