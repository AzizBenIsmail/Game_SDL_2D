
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <unistd.h>


typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int frame;
  int direction;
  int died;

}Enemy;

typedef struct hero
{
	int mouvment,mouvment2;
	SDL_Surface *afficher_hero[9];
	SDL_Surface *afficher_herod[9];
        SDL_Surface *afficher_hit;
        SDL_Rect pos_hero[9];
	SDL_Rect pos_hero2;
	int farm,farm2;
        int hit;
	int heromoved;
	int vie;
        SDL_Rect pos_vie;
	SDL_Surface *afficher_vie[3];
	int score;
	SDL_Surface *afficher_score;
	

	float vx;
	float vy;
	float x;
	float y;
	
}hero;

typedef struct Score 
{ 
   SDL_Surface *fondScore;
   SDL_Surface *texteScore;
   SDL_Rect posFond;
   SDL_Rect posScore;
   int scoreActuel;
   TTF_Font *police;
   
}Score;

typedef struct Time {
	SDL_Surface *msg;
	TTF_Font *font;
        SDL_Rect positiontemps;
	int time;
	char timeString[10];
}Time;

typedef struct objet{

	SDL_Surface *afficher_objet;
	SDL_Rect pos_objet;
}objet;


typedef struct background{

	SDL_Surface *afficher_background;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
        SDL_Rect position;
}background;

 
typedef struct menu{
	SDL_Surface *background;
	SDL_Surface *bplay;
	SDL_Surface *beplay;
	SDL_Surface *droit;	
	SDL_Surface *droite;
	SDL_Surface *gauche;
	SDL_Surface *gauchee;
	SDL_Surface *msetting;	
	SDL_Surface *besetting;
	SDL_Surface *bsetting;
	SDL_Surface *bquit;
	SDL_Surface *bequit;
	SDL_Rect positionecran;
	SDL_Rect positionbplay;
	SDL_Rect positiondroit;
	SDL_Rect positiongauche;
	SDL_Surface *sousmenuquit;
	SDL_Rect positionsousmenuquit;

	SDL_Surface *sousmenukey1;
	SDL_Surface *sousmenukey2;
	SDL_Surface *sousmenuoff1;
	SDL_Surface *sousmenuoff2;
	SDL_Surface *sousmenuon1;
	SDL_Surface *sousmenuon2;
	SDL_Surface *sousmenucont1;
	SDL_Surface *sousmenucont2;
	SDL_Rect positionsouskey;
	SDL_Rect positionsousoff;
	SDL_Rect positionsouson;
	SDL_Rect positionsouscont;
	int sousetatsound;
	int sousetatcontrole;

	int action;
	int boutoneffet;
	int po;
	Mix_Music *son;	
	
} menu;
typedef struct pmap{
	int nbmoved;
	SDL_Surface *afficher_pmap;
	SDL_Rect pos_pmap;
	SDL_Surface *afficher_pperso;
	SDL_Rect pos_pperso;
}pmap;

       
	int affcihiersousmenuingame(menu *menu,SDL_Surface *ecran);
	void afficher_sousmenuingame(menu *menu,SDL_Surface *ecran,int x,int y);

	void initialiser_pmap(pmap *pmap);
	void afficher_pmap(pmap *pmap,SDL_Surface *ecran,int mouvment);

	void affichiervie(hero leon, SDL_Surface *ecran);
	int gestionvie(hero *leon,SDL_Surface *ecran);

        void initialiserScore(  Score *score );
        void afficherScore(SDL_Surface *ecran , Score *score, background bg,int collision );

        void initializerTemps(Time *time);
        void afficherTemps(Time *time,SDL_Surface *ecran);

        int controle_menu ();
	void initialiser_menu(menu *menu);
	int affcihier(menu *menu,SDL_Surface *ecran);
	void affichier_quit(menu *menu,SDL_Surface *ecran,int x,int y);
	void afficher_setting(menu *menu,SDL_Surface *ecran,int x,int y);

	void initialiser_background(background *bckg);
 	void afficher_background(background bckg,SDL_Surface *ecran);

	void initialiser_leon(hero *leon);
	void afficher_leon(hero leon,SDL_Surface *ecran);

        void initialiser_leon2(hero *leon2);
	void afficher_leon2(hero leon2,SDL_Surface *ecran);
	
	void scrolling (hero *leon,background *bckg, int co);

	int animation_perso(hero leon);
        int animation_perso2(hero leon2);
	int mouvment(hero leon,SDL_Event *event);
        int mouvment2(hero leon2,SDL_Event *event);

	void initialiser_objet(objet *chouka);
	void afficher_objet(objet *chouka,SDL_Surface *ecran, hero leon);

	
	int Collision_Bounding_Box (hero leon ,objet chouka );

	Enemy InitEnemy(Enemy Ennemie,int x, int y);
	void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
	Enemy AnimateEnemy(Enemy Ennemie,int stat);
	Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment);

	int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);

	

	int mouvmentarduino(hero leon,FILE *f);

	Enemy diedennemie(Enemy Ennemie,int coe);

	int collision_Parfaiteennemie(SDL_Surface *calque,SDL_Rect posennemie,SDL_Rect posmap);


	void sauvegarde (char fich[]);


	
	
	//void scrollingm(hero *evan,background *bckg,int co );
	
	SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
	extern hero leon;
        extern hero leon2;
	extern Enemy Ennemie;
	extern background bckg;
	/*extern pmap pmap;*/

#endif
