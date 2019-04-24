#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//------------- Bibliotheques SDL --------------//

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//------------- PROGRAMME PRINCIPAL ------------//

int main( int argc, char* args[] )
{
    //------------- Variables ----------------------//

    //La souris
    coord souris;
        souris.nX = 0;
        souris.nY = 0;

    int scene = 0;

    //----------------------------------------------//

    //Initialisation de la SDL, de la fenêtre et du renderer
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* pWindow = NULL;
    SDL_Renderer *renderer = NULL;

    //création de la fenêtre
    pWindow = SDL_CreateWindow("Super Healer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    //et du renderer
    renderer = SDL_CreateRenderer(pWindow, -1, 0);

    //l'évenement
    SDL_Event event;

    SDL_Surface *image;

//----- Les textures ----//
    SDL_Texture *base;
    SDL_Texture *cable;
    SDL_Texture *sangTable;
    SDL_Texture *sangTete;
    SDL_Texture *main;
    SDL_Texture *rules;
    SDL_Texture *reponses;
    SDL_Texture *Conclusion;
    SDL_Texture *vrai;
    SDL_Texture *faux;
//-----------------------//

    //chargment du "menu"
    image=IMG_Load("Assets/Fini/main.png");
    main = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargment de la photo de base
    image=IMG_Load("Assets/Fini/rules.png");
    rules = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargment des réponses de la scene 1
    image=IMG_Load("Assets/Fini/reponses.png");
    reponses = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

     //chargment des réponses de conclusion
    image=IMG_Load("Assets/Fini/Conclusion.png");
    Conclusion = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargment des réponses vrai
    image=IMG_Load("Assets/Fini/vrai.png");
    vrai = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargment des réponses faux
    image=IMG_Load("Assets/Fini/faux.png");
    faux = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargment de la photo de base
    image=IMG_Load("Assets/Fini/base.png");
    base = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargement de la photo avec cable surligné
    image=IMG_Load("Assets/Fini/cable.png");
    cable = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargement de la photo avec le sang sur la table surligné
    image=IMG_Load("Assets/Fini/sangTable.png");
    sangTable = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    //chargement de la photo avec le sang sur la tête surligné
    image=IMG_Load("Assets/Fini/sangTete.png");
    sangTete = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    while(pWindow)
    {
        SDL_PollEvent(&event);

        switch(event.type)
        {
            //appuyer sur la croix
            case SDL_QUIT:
            {
                pWindow = 0;
                break;
            }
            //clic
            case SDL_MOUSEBUTTONDOWN:
            {
                souris.nX = event.button.x;
                souris.nY = event.button.y;
                break;
            }
            //appuyer sur enter
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_RETURN:
                    {
                        scene += 1;
                        SDL_Delay(200);
                        break;
                    }
                }
        }

        if(scene == 0)//menu principal
        {
            SDL_RenderCopy(renderer, main, NULL, NULL);//affichage du main
        }

        if(scene == 1)
        {
            SDL_RenderCopy(renderer, rules, NULL, NULL);//affichage des règles
        }

        if(scene == 2)
        {
            SDL_RenderCopy(renderer, base, NULL, NULL);//affichage de la base
            changement(souris, renderer, cable, sangTable, sangTete);
        }
        if(scene == 3)
        {
            SDL_RenderCopy(renderer, reponses, NULL, NULL);//affichage des réponses
            sceneOne(souris, renderer, faux, vrai, Conclusion);

            SDL_PollEvent(&event);

            switch(event.type)
            {
                //appuyer sur la croix
                case SDL_QUIT:
                {
                    pWindow = 0;
                    break;
                }

                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_RETURN:
                    {
                        scene += 1;
                        SDL_Delay(200);
                        break;
                    }
                }
            }
        }

        if(scene == 4)
        {
            SDL_PollEvent(&event);

            switch(event.type)
            {
                //appuyer sur la croix
                case SDL_QUIT:
                {
                    pWindow = 0;
                    break;
                }

                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    //ENTER
                    case SDLK_RETURN:
                    {
                        SDL_RenderCopy(renderer, Conclusion, NULL, NULL);
                        break;
                    }
                }
            }
        }




        printf("x : %d, y : %d\n", souris.nX, souris.nY);
        SDL_RenderPresent(renderer);

    }

	//Quitter les sous systèmes de la SDL
	TTF_Quit();
	SDL_Quit();


	return 0;
}




