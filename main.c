#include <stdio.h>
#include <SDL.h>
#define true 1
#define false 0
#define TAILLE_MAX 100
#define NB_IMAGE 30

//Here we create some global variables

typedef int bool;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

//The window we will be rendering on
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gImageTableau[TAILLE_MAX] = {NULL};

char gImageName[TAILLE_MAX][100] = {   "image1.bmp",
                                "image2.bmp",
                                "image3.bmp",
                                "image4.bmp",
                                "image5.bmp",
                                "image6.bmp",
                                "image7.bmp",
                                "image8.bmp",

                                "image9.bmp",
                                "image10.bmp",
                                "image11.bmp",
                                "image12.bmp",
                                "image13.bmp",
                                "image14.bmp",
                                "image15.bmp",
                                "image16.bmp",
                                "image17.bmp",
                                "image18.bmp",
                                "image19.bmp",
                                "image20.bmp",
                                "image21.bmp",
                                "image22.bmp",
                                "image23.bmp",
                                "image24.bmp",
                                "image25.bmp",
                                "image26.bmp",
                                "image27.bmp",
                                "image28.bmp",
                                "image29.bmp",
                                "image30.bmp",

                                };







// this function intialize SDL and creates a window
bool init()
{
    bool sucess = true;

    //We will initilize SDL video module
    if (SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
        sucess = false;
    }

    else
    {

        //We create a window
       gWindow = SDL_CreateWindow("Photo Anime Viewer",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n",SDL_GetError());
            sucess = false;
        }

        else
        {
            //here we get the window surface where we will blit on
            gScreenSurface = SDL_GetWindowSurface(gWindow);
            if (gScreenSurface == NULL)
            {
                printf("Surface could not be created! SDL_Error: %s\n",SDL_GetError());
            }

        }


    }
    return sucess;


}


//this functions loads an image on the screen
bool loadMedia()
{
    bool success = true;
    for(int i = 0 ; i < NB_IMAGE ; i++){
        gImageTableau[i] = SDL_LoadBMP(gImageName[i]);
        if (gImageTableau[i] == NULL)
        {
            printf( "Unable to load image %s! SDL Error: %s\n", gImageName[i], SDL_GetError() );
            success = false;
            break;
        }

    }


    {

    }

    return success;
}

void blit_image(SDL_Surface* image)
{
    SDL_BlitSurface(image,NULL,gScreenSurface,NULL);
    SDL_UpdateWindowSurface( gWindow );
    SDL_Delay( 2500 );

}



void close()
{

    for(int i = 1 ; i < NB_IMAGE ; i++ )
    {

        SDL_FreeSurface(gImageTableau[i]);
        gImageTableau[i] = NULL;

    }
    //Destroy the window
    SDL_DestroyWindow( gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();

}


//THE MAIN FUNCTION
int main(int argc, char* args[])
{



    //Start up SDL and create a window

    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }

        else
        {
            //APPLY THE IMAGE ON THE SURFACE
            for(int i = 1 ; i < NB_IMAGE ; i++ )
            {

                blit_image(gImageTableau[i]);




            }

        }

    }


    //FREE THE MEMORY FREEEEEEDOOOOM
    close();

    return 0;



}
