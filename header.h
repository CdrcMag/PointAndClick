#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//------------- Bibliotheques SDL --------------//

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//------------- Constantes ---------------------//

//Dimensions de la fenêtre
#define SCREEN_WIDTH 1168 //largeur
#define SCREEN_HEIGHT 876 //hauteur

//------------- Structures ---------------------//

typedef struct coord
{
    int nX;
    int nY;

}coord;

//------------- Prototypes ---------------------//

extern void changement(coord souris, SDL_Renderer *renderer, SDL_Texture *cable, SDL_Texture *sangTable, SDL_Texture *sangTete);
extern void sceneOne(coord souris, SDL_Renderer *renderer, SDL_Texture *faux, SDL_Texture *vrai, SDL_Texture *Conclusion);

#endif // HEADER_H_INCLUDED
