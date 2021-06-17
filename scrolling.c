#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
void scrolling (hero *leon,background *bckg,int co )
{
	 leon->heromoved=0;
	switch(leon->mouvment)
	{

		case 1: 
			if (co!=2){
			if ((bckg->pos_background2.x<6800)&&(leon->pos_hero2.x>=300))
                		bckg->pos_background2.x=bckg->pos_background2.x+5;
			if (((leon->pos_hero2.x<300)||((bckg->pos_background2.x>=6800))&&(leon->pos_hero2.x<1100)))
				leon->pos_hero2.x=leon->pos_hero2.x+5;
			leon->heromoved=1;
		}
	
		break;
		case 2:
		if (co!=2){
			if (bckg->pos_background2.x>0)
                		bckg->pos_background2.x=bckg->pos_background2.x-5;
	    		if (((bckg->pos_background2.x!=0)&&(leon->pos_hero2.x>=150))||((bckg->pos_background2.x==0)&&(leon->pos_hero2.x=50)))
				leon->pos_hero2.x=leon->pos_hero2.x-5;
			    leon->heromoved=2;
			}	
		break;
		case 3:

		if (leon->pos_hero2.y>50){
			if (bckg->pos_background2.x<6800){
				leon->pos_hero2.y=leon->pos_hero2.y-20;

			}
		}
		break;
	}
	if ((leon->mouvment!=3)&&(co!=10)&&(co!=2)){
		leon->pos_hero2.y=leon->pos_hero2.y+5;
	}
}




