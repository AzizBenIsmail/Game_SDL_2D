#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;
	char* pPosition = ( char* ) surface->pixels ;
	pPosition += ( surface->pitch * y ) ;
	pPosition += ( surface->format->BytesPerPixel * x ) ;
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col,col2,col22,col1;
  //if(d==0)//imin
  //{
	col=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+220);
	col2=GetPixel(calque,posperso.x+50+posmap.x,posperso.y+230);
	col22=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+180);
	col1=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+220);

  //}
//else  if(d==1)
  //{
   // col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  //}
//else  if(d==2)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2)+ posmap ,posperso.y);
  //}
//else  if(d==3)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h );
 // }
   printf("%d    %d   /////////// \n",posperso.x+100+posmap.x+601,posperso.y+220 );
  printf("%d    %d   %d\n",col.r,col.b,col.g );
  //SDL_Delay(250);
if ((col.r==0)&&(col.b==0)&&(col.g==255))
  return 1;//7ofra
else if ((col22.r==0)&&(col22.b==0)&&(col22.g==0))
  return 2;//obstacle
else if ((col1.r==0)&&(col1.b==255)&&(col1.g==0))
  return 1;//choukakbira
else if ((col22.r==255)&&(col22.b==0)&&(col22.g==0))
  return 3;//door enigme
else if ((col2.r==0)&&(col2.b==0)&&(col2.g==0))
 return 10;//9a3
else
{
	return 0;
}
}
int collision_Parfaiteennemie(SDL_Surface *calque,SDL_Rect posennemie,SDL_Rect posmap){

  SDL_Color col;
  col=GetPixel(calque,posennemie.x+50+posmap.x,posennemie.y+220);
  //printf("%d    %d   %d\n",col.r,col.b,col.g);
  if ((col.r==0)&&(col.b==0)&&(col.g==255))
    return 1;//7ofra
  else 
    return 0;
}