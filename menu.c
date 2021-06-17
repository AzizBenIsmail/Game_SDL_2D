#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include"struct.h"

void initialiser_menu(menu *menu){
	
	menu->background=NULL;
	menu->bplay=NULL;
	menu->beplay=NULL;
	menu->droit=NULL;
	menu->droite=NULL;
	menu->gauche=NULL;
	menu->gauchee=NULL;
	menu->msetting=NULL;
	menu->besetting=NULL,
	menu->bsetting=NULL;
	menu->bquit=NULL;
	menu->bequit=NULL;

	menu->sousmenukey1=NULL;
	menu->sousmenukey2=NULL;
	menu->sousmenuoff1=NULL;
	menu->sousmenuoff2=NULL;
	menu->sousmenuon1=NULL;
	menu->sousmenuon2=NULL;
	menu->sousmenucont1=NULL;
	menu->sousmenucont2=NULL;

	menu->sousmenuquit=NULL;
	menu->positionsousmenuquit.x=190;
	menu->positionsousmenuquit.y=50;
	menu->sousmenuquit=IMG_Load("quit.png");
	
	
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_OpenAudio(48000, AUDIO_S16SYS, 1, 2048);
	Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	menu->son=Mix_LoadMUS("music.mp3");


	menu->background=IMG_Load("backgroundmenu.png");
	menu->bplay=IMG_Load("play.png");
	menu->beplay=IMG_Load("playe.png");
	menu->gauche=IMG_Load("droite.png");
	menu->droit=IMG_Load("gauche.png");
	menu->gauchee=IMG_Load("a.png");
	menu->droite=IMG_Load("options.png");
	menu->bsetting=IMG_Load("setting.png");
	menu->besetting=IMG_Load("settinge.png");
	menu->bquit=IMG_Load("quit.png");
	menu->bequit=IMG_Load("quite.png");
	menu->msetting=IMG_Load("sous.png");

	menu->positionbplay.x=320;
	menu->positionbplay.y=180;

	menu->positiondroit.x=400;
	menu->positiondroit.y=250;

	menu->positiongauche.x=220;
	menu->positiongauche.y=250;

	menu->positionecran.x=0;
	menu->positionecran.y=0;
	menu->action=1;
	menu->po=1;

	menu->sousmenukey1=IMG_Load("quite.png");
	menu->sousmenukey2=IMG_Load("key2.png");
	menu->sousmenuoff1=IMG_Load("off1.png");
	menu->sousmenuoff2=IMG_Load("off2.png");
	menu->sousmenuon1=IMG_Load("on1.png");
	menu->sousmenuon2=IMG_Load("on2.png");
	menu->sousmenucont1=IMG_Load("cont1.png");
	menu->sousmenucont2=IMG_Load("cont2.png");

	menu->positionsouskey.x=800;
	menu->positionsouskey.y=300;
	menu->positionsousoff.x=650;
	menu->positionsousoff.y=175;
	menu->positionsouson.x=800;
	menu->positionsouson.y=175;
	menu->positionsouscont.x=650;
	menu->positionsouscont.y=300;
	menu->sousetatsound=1;
	menu->sousetatcontrole=1;
}

int controle_menu (){

	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type)
        {
        case SDL_QUIT:
             SDL_Quit();
            	return 0;
            break;
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
            	return 10;
                break;
            case SDLK_RIGHT:
            	return 1;
            break;

            case SDLK_LEFT:
            	return 2;
           }
           break;
        	case SDL_MOUSEBUTTONUP:
        		return 5;

                    break;
            default: 	return 9;
		}

}


int affcihier(menu *menu,SDL_Surface *ecran){

	
	int x,y;
	int d;

		//SDL_SetEventFilter(isMouseEvent);
		//SDL_PollEvent(&e);
		SDL_GetMouseState(&x,&y);
       


	if(menu->po==2){
		       if ((340<=x)&&(x<=640)&&(y<=464)&&(198<=y)){

			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
                     
			SDL_BlitSurface(menu->besetting,NULL,ecran,&menu->positionbplay);
             
			menu->boutoneffet=22;
		}

		else if ((619<=x)&&(x<=688)&&(y<=384)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bsetting,NULL,ecran,&menu->positionbplay);
			

			menu->boutoneffet=23;
		}		else if ((220<=x)&&(x<=324)&&(y<=381)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bsetting,NULL,ecran,&menu->positionbplay);
		
			menu->boutoneffet=21;

		}
		else{
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bsetting,NULL,ecran,&menu->positionbplay);
			
			menu->boutoneffet=0;

		}
			}

	
	else if (menu->po==1){
		       if ((340<=x)&&(x<=602)&&(y<=464)&&(198<=y)){

			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			
			SDL_BlitSurface(menu->beplay,NULL,ecran,&menu->positionbplay);
                        SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			menu->boutoneffet=12;
		}

		else if ((619<=x)&&(x<=688)&&(y<=384)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bplay,NULL,ecran,&menu->positionbplay);
                        SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			
			menu->boutoneffet=13;
		}
		else{
			SDL_BlitSurface(menu->background, NULL, ecran, &(menu->positionecran));
			SDL_BlitSurface(menu->bplay,NULL,ecran,&(menu->positionbplay));
                        SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			
			SDL_Flip(ecran);
			menu->boutoneffet=10;
		}
	}

	else if (menu->po==3){
		       if ((340<=x)&&(x<=602)&&(y<=464)&&(198<=y)){

			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bequit,NULL,ecran,&menu->positionbplay);
			
			menu->boutoneffet=32;
		}
		else if ((260<=x)&&(x<=324)&&(y<=381)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bquit,NULL,ecran,&menu->positionbplay);
			
			menu->boutoneffet=31;
		}
		else{
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bquit,NULL,ecran,&menu->positionbplay);
			
			menu->boutoneffet=30;
		}
	}
	else if(menu->po==22){
			  SDL_BlitSurface(menu->droite, NULL, ecran, &menu->positionecran);
		}
	else if (menu->po==33){
		affichier_quit(menu,ecran,x,y);
	}
	/*SDL_Flip(ecran);*/
		printf("%d \t %d \n",x,y);

		if (controle_menu()==0)
            menu->action=0;

        if (controle_menu()==10){
			if (menu->po==22)
				menu->po=1;
			else
                 menu->action=0;
        }
 		if (controle_menu()==1){
			Mix_PlayMusic(menu->son,0);
 		
			if(menu->po==1){
    			menu->po=2;
				
				SDL_Flip(ecran);
				usleep(300000);
			}
			else if (menu->po==2){
				menu->po=3;
				
				SDL_Flip(ecran);
				usleep(300000);
			}
	}
		if (controle_menu()==2){
			Mix_PlayMusic(menu->son,0);
			if (menu->po==2){
	                menu->po=1;
				
				SDL_Flip(ecran);
				usleep(300000);
			}

			else if(menu->po==3){
				menu->po=2;
				
				SDL_Flip(ecran);
				usleep(300000);
            	}
            }

        if(controle_menu()==5){
        	
       		if((menu->boutoneffet==13)&&(menu->po==1)){
				menu->po=2;
				Mix_PlayMusic(menu->son,0);
			}
			else if ((menu->boutoneffet==23)&&(menu->po==2)){
				menu->po=3;
				Mix_PlayMusic(menu->son,0);
			}
			else if ((menu->boutoneffet==21)&&(menu->po==2)){
				menu->po=1;
				Mix_PlayMusic(menu->son,0);
			}
			else if ((menu->boutoneffet==31)&&(menu->po==3)){
				menu->po=2;
				Mix_PlayMusic(menu->son,0);
			}
			else if ((menu->boutoneffet==32)&&(menu->po==3)){
				menu->po=33;
				Mix_PlayMusic(menu->son,0);
			}
			else if ((menu->boutoneffet==22)&&(menu->po==2)){
				menu->po=22;
				Mix_PlayMusic(menu->son,0);
			}
			else if(((menu->boutoneffet==12)&&(menu->po==1)))
				menu->action=10;//10 solo 11 multi
			else if ((menu->boutoneffet==331)&&(menu->po==33))
				menu->po=1;
			else if ((menu->boutoneffet==332)&&(menu->po==33))
				menu->action=0;
			else if ((menu->boutoneffet==223)&&(menu->po==22))
				menu->sousetatcontrole=1;
			else if ((menu->boutoneffet==224)&&(menu->po==22))
				menu->sousetatcontrole=2;
		}
      //printf("%d\n\n",menu->boutoneffet );
	return menu->action;
}

void afficher_setting(menu *menu,SDL_Surface *ecran,int x,int y){
	SDL_BlitSurface(menu->msetting, NULL, ecran, &menu->positionecran);
 if (menu->sousetatsound==1){
 	SDL_BlitSurface(menu->sousmenuon1, NULL, ecran, &menu->positionsouson);
	SDL_BlitSurface(menu->sousmenuoff2, NULL, ecran, &menu->positionsousoff);
 }
  if (menu->sousetatsound==2){
 	SDL_BlitSurface(menu->sousmenuon2, NULL, ecran, &menu->positionsouson);
	SDL_BlitSurface(menu->sousmenuoff1, NULL, ecran, &menu->positionsousoff);
 }
 if (menu->sousetatcontrole==1){
 	 SDL_BlitSurface(menu->sousmenukey1, NULL, ecran, &menu->positionsouskey);
	SDL_BlitSurface(menu->sousmenucont2, NULL, ecran, &menu->positionsouscont);
 }
 if (menu->sousetatcontrole==2){
 	SDL_BlitSurface(menu->sousmenukey2, NULL, ecran, &menu->positionsouskey);
	SDL_BlitSurface(menu->sousmenucont1, NULL, ecran, &menu->positionsouscont);
 }
	if((675<=x)&&(x<=800)&&(y<=425)&&(300<=y))//no
		menu->boutoneffet=223;

	if((650<=x)&&(x<=775)&&(y<=425)&&(300<=y))//no
		menu->boutoneffet=224;

	/*if((400<=x)&&(x<=435)&&(y<=453)&&(300<=y))//no
		menu->boutoneffet=331;
	if((400<=x)&&(x<=435)&&(y<=453)&&(300<=y))//no
		menu->boutoneffet=331;*/

 //SDL_Flip(ecran);
 
}

/*
void  affichier_quit(menu *menu,SDL_Surface *ecran,int x,int y){
	SDL_BlitSurface(menu->sousmenuquit, NULL, ecran, &menu->positionsousmenuquit);
	if((550<=x)&&(x<=585)&&(y<=453)&&(300<=y))//no
		menu->boutoneffet=331;
	else if((620<=x)&&(x<=660)&&(y<=510)&&(300<=y))//yes
		menu->boutoneffet=332;
}
void affichier_option(menu *menu,SDL_Surface *ecran,int x,int y);
int isMouseEvent(const SDL_Event* event)
{
    if (event->type == SDL_MOUSEMOTION)
        return 0;
    return 1;
}*/
void  affichier_quit(menu *menu,SDL_Surface *ecran,int x,int y){
	SDL_BlitSurface(menu->sousmenuquit, NULL, ecran, &menu->positionsousmenuquit);
	if((400<=x)&&(x<=435)&&(y<=453)&&(300<=y))//no
		menu->boutoneffet=331;
	else if((470<=x)&&(x<=510)&&(y<=510)&&(300<=y))//yes
		menu->boutoneffet=332;
}

void afficher_sousmenuingame(menu *menu,SDL_Surface *ecran,int x,int y){
	SDL_BlitSurface(menu->msetting, NULL, ecran, &menu->positionecran);
 if (menu->sousetatsound==1){
 	SDL_BlitSurface(menu->sousmenuon1, NULL, ecran, &menu->positionsouson);
	SDL_BlitSurface(menu->sousmenuoff2, NULL, ecran, &menu->positionsousoff);
 }
  if (menu->sousetatsound==2){
 	SDL_BlitSurface(menu->sousmenuon2, NULL, ecran, &menu->positionsouson);
	SDL_BlitSurface(menu->sousmenuoff1, NULL, ecran, &menu->positionsousoff);
 }
 if (menu->sousetatcontrole==1){
 	 SDL_BlitSurface(menu->sousmenukey1, NULL, ecran, &menu->positionsouskey);
	SDL_BlitSurface(menu->sousmenucont2, NULL, ecran, &menu->positionsouscont);
 }
 if (menu->sousetatcontrole==2){
 	SDL_BlitSurface(menu->sousmenukey2, NULL, ecran, &menu->positionsouskey);
	SDL_BlitSurface(menu->sousmenucont1, NULL, ecran, &menu->positionsouscont);
 }
	if((675<=x)&&(x<=800)&&(y<=425)&&(300<=y))//no
		menu->boutoneffet=223;

	if((650<=x)&&(x<=775)&&(y<=425)&&(300<=y))//no
		menu->boutoneffet=224;

	/*if((400<=x)&&(x<=435)&&(y<=453)&&(300<=y))//no
		menu->boutoneffet=331;
	if((400<=x)&&(x<=435)&&(y<=453)&&(300<=y))//no
		menu->boutoneffet=331;*/

 //SDL_Flip(ecran);
 
}


int affcihiersousmenuingame(menu *menu,SDL_Surface *ecran){
	
	int x,y;
	SDL_GetMouseState(&x,&y);


	afficher_sousmenuingame(menu,ecran,x,y);
	
	
	if(controle_menu()==5){

		if ((menu->boutoneffet==223))
			menu->sousetatcontrole=1;
		else if ((menu->boutoneffet==224))
			menu->sousetatcontrole=2;

	}
		if(controle_menu()==10){
			return 10;
		}

		return menu->action;
}
