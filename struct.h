/*
** EPITECH PROJECT, 2019
** struct_h
** File description:
** struct_h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <stdlib.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Export.h>
#include <sys/types.h>
#include <sys/stat.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
char *nb_tochar(int i);
int game(sfRenderWindow* window, int fd);
int game_over(sfRenderWindow* window, float scoore);
int win(sfRenderWindow* window, float scoore);

struct main_menu
{
    sfRenderWindow* window;
    sfTime time;
    sfEvent event;
    sfFont* font;
    sfTexture* texturebg;
    sfTexture* texturebgback;
    sfTexture* texturebgmiddle;
    sfTexture* bgfront;
    sfTexture* dino1;
    sfTexture* dino2;
    sfTexture* dino3;
    sfTexture* dino4;
    sfSprite* dino;
    sfSprite* background;
    sfText* title;
    sfText* footer;
    sfMusic* music;
};

struct my_game
{
    sfRenderWindow* window;
    sfText* score;
    sfTexture* texturebg;
    sfTexture* dino1;
    sfTexture* dino2;
    sfTexture* dino3;
    sfTexture* dino4;
    sfTexture* textureobs;
    sfTexture* textureground;
    sfTexture* texturebg2;
    sfTexture* texturebg3;
    sfTexture* texturehills;
    sfTexture* textureclouds;
    sfSprite* obs;
    sfSprite* dino;
    sfSprite* bg;
    sfSprite* bg2;
    sfSprite* bg3;
    sfSprite* hills;
    sfSprite* ground;
    sfSprite* clouds;
    sfFont* font;
    sfEvent event;
    sfIntRect bgrect;
    sfMusic* hit;
    sfMusic* press;
    sfMusic* reached;
};

struct lose
{
    sfRenderWindow* window;
    sfTime time;
    sfEvent event;
    sfFont* font;
    sfTexture* texturebg;
    sfTexture* texturebgback;
    sfTexture* texturebgmiddle;
    sfTexture* bgfront;
    sfSprite* background;
    sfText* title;
    sfText* score;
    sfText* text;
};

struct win
{
    sfRenderWindow* window;
    sfTime time;
    sfEvent event;
    sfFont* font;
    sfTexture* texturebg;
    sfTexture* texturebgback;
    sfTexture* texturebgmiddle;
    sfTexture* bgfront;
    sfSprite* background;
    sfText* title;
    sfText* score;
    sfText* text;
};