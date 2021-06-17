#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
 int mouvment(hero leon,SDL_Event *event){

 	int mouvment;

 	SDL_PollEvent(event);
 	switch (event->type)
        {
        case SDL_QUIT:
           mouvment=0;
            break;
  	case SDL_MOUSEBUTTONUP:               
                    
           	mouvment=1;
	 break;
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
            case SDLK_ESCAPE:
                mouvment=100;
                break;
            case SDLK_RIGHT:
				mouvment=1;
                //scrolling (hero *evan,background *bckg);
                break;
            case SDLK_LEFT:
            	mouvment=2;
                //scrolling (hero *evan,background *bckg);
                break;
            case SDLK_UP: 
                mouvment=3;  
                 break;
          case SDLK_m: 
                mouvment=7;  
                 break;
            case SDLK_SPACE:
            mouvment=5;  
                 break;
            }
            break;
             default: 	mouvment=9;
 }
 //printf("%d c",mouvment);
 return mouvment;

}
