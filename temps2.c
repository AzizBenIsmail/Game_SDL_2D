#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"struct.h"

void initializerTemps(Time *time){
	time->font = TTF_OpenFont("Colleged.ttf", 25);
	time->time = 0;
	sprintf(time->timeString,"00:00");
	SDL_Color color = {255,255,255};
	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
        time->positiontemps.x=0;
        time->positiontemps.y=50;
}

void afficherTemps(Time *time, SDL_Surface *ecran){
	SDL_Color color = {255,255,255};
	time->time++;
	if(time->time % 60 == 0){
		sprintf(time->timeString,"%02d:%02d\n",time->time/60/60,(time->time/60)%60);
		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
	}
	SDL_BlitSurface(time->msg,NULL,ecran,&time->positiontemps);
}
