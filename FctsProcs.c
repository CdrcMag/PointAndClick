#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//------------- Bibliotheques SDL --------------//

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

void changement(coord souris, SDL_Renderer *renderer, SDL_Texture *cable, SDL_Texture *sangTable, SDL_Texture *sangTete)
{
    //**************************************************************************************************************//
    //
    //  Description : procédure affichant certaines images en fonction de la position de la souris sur l'écran
    //
    //  Entrées : la position de la souris
    //
    //  Sorties : l'image affichée le temps que la souris est dans la "hitbox"
    //
    //  Notes :
    //
    //***************************************************************************************************************//
    printf("x : %d, y : %d\n", souris.nX, souris.nY);
    //--------------//,

    //Xmin, Xmax, Ymin, Ymax
    if(((souris.nX > 888) && (souris.nX < 975)) && ((souris.nY > 400) && (souris.nY < 1020)))
    {
        SDL_RenderCopy(renderer, cable, NULL, NULL);
    }
    if(((souris.nX > 130) && (souris.nX < 276)) && ((souris.nY > 476) && (souris.nY < 564)))
    {
        SDL_RenderCopy(renderer, sangTete, NULL, NULL);
    }
    if(((souris.nX > 526) && (souris.nX < 602)) && ((souris.nY > 154) && (souris.nY < 227)))
    {
        SDL_RenderCopy(renderer, sangTable, NULL, NULL);
    }
}

void sceneOne(coord souris, SDL_Renderer *renderer, SDL_Texture *faux, SDL_Texture *vrai, SDL_Texture *Conclusion)
{
    //**************************************************************************************************************//
    //
    //  Description : procédure affichant certaines images en fonction de la position et clic de la souris sur l'écran
    //
    //  Entrées : la position de la souris
    //
    //  Sorties : l'image affichée en fonction du choix
    //
    //  Notes :
    //
    //***************************************************************************************************************//
    printf("x : %d, y : %d\n", souris.nX, souris.nY);

    //Xmin, Xmax, Ymin, Ymax
    if(((souris.nX > 170) && (souris.nX < 1024)) && ((souris.nY > 500) && (souris.nY < 624)))
    {
        SDL_RenderCopy(renderer, vrai, NULL, NULL);
    }
    if(((souris.nX > 235) && (souris.nX < 773)) && ((souris.nY > 403) && (souris.nY < 457)))
    {
        SDL_RenderCopy(renderer, faux, NULL, NULL);
    }
    if(((souris.nX > 259) && (souris.nX < 786)) && ((souris.nY > 709) && (souris.nY < 770)))
    {
        SDL_RenderCopy(renderer, faux, NULL, NULL);
    }
}
