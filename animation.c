#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
int animation_perso(hero leon){


	int farm=leon.farm;
	switch(leon.mouvment){

		case 1:
				if (farm<8)
					farm++;
				else farm=0;
				//usleep(30000);
			
			break;
		case 2:
				if (farm<8)
					farm++;
				else farm=0;			
				
				//usleep(20000);
			
			break;
		case 3:
			if (farm<8)
					farm++;
				else farm=0;			
				
				//usleep(20000);
			
			break;
		default: farm=0;
	}
	return farm;
}


