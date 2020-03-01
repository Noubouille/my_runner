/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_runner
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"

void setup_texts(struct main_menu menu)
{
    sfVector2f titlepos = {400, 0};
    sfVector2f footerpos = {100, 700};
    sfVector2f dinopos = {800, 400};
    sfVector2f scale = {2, 2};
    sfText_setString(menu.title, "Dinosaur Runner");
    sfText_setPosition(menu.title, titlepos);
    sfText_setFont(menu.title, menu.font);
    sfText_setCharacterSize(menu.title, 300);
    sfText_setString(menu.footer, "Press Enter button to begin");
    sfText_setPosition(menu.footer, footerpos);
    sfText_setFont(menu.footer, menu.font);
    sfText_setCharacterSize(menu.footer, 300);
    sfSprite_setPosition(menu.dino, dinopos);
    sfSprite_setScale(menu.dino, scale);
}

void destroy(struct main_menu menu, sfRenderWindow* window)
{
    sfText_destroy(menu.title);
    sfText_destroy(menu.footer);
    sfTexture_destroy(menu.dino1);
    sfTexture_destroy(menu.dino2);
    sfTexture_destroy(menu.dino3);
    sfTexture_destroy(menu.dino4);
    sfTexture_destroy(menu.texturebg);
    sfSprite_destroy(menu.dino);
    sfSprite_destroy(menu.background);
    sfMusic_destroy(menu.music);
    sfRenderWindow_destroy(window);
}

void drawanddisplay(struct main_menu menu, sfRenderWindow* window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu.background, NULL);
    sfRenderWindow_drawSprite(window, menu.dino, NULL);
    sfRenderWindow_drawText(window, menu.title, NULL);
    sfRenderWindow_drawText(window, menu.footer, NULL);
    sfRenderWindow_display(window);
}

int main(int ac, char** av)
{
    struct main_menu menu;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\n- Runner -\n\n");
        my_putstr("-  Usage: ./my_runner map.txt \n\n");
        my_putstr("-  Your goal \n\n");
        my_putstr("   Go as far as you can without dying.\n");
        my_putstr("   Good luck and have fun :)\n\n");
        return (0);
    }
    sfVideoMode mode = {1920, 1080, 32};
    sfClock* clock = sfClock_create();
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, "my_runner", sfResize| sfClose, NULL);
    menu.font = sfFont_createFromFile("Gilberto.ttf");
    menu.title = sfText_create();
    menu.footer = sfText_create();
    menu.dino = sfSprite_create();
    menu.texturebg = sfTexture_createFromFile("assets/backgrounds/bg.jpg", NULL);
    menu.dino1 = sfTexture_createFromFile("assets/sprites/dino1a.png", NULL);
    menu.dino2 = sfTexture_createFromFile("assets/sprites/dino2a.png", NULL);
    menu.dino3 = sfTexture_createFromFile("assets/sprites/dino3a.png", NULL);
    menu.dino4 = sfTexture_createFromFile("assets/sprites/dino4a.png", NULL);
    menu.music = sfMusic_createFromFile("musics/Tetris.ogg");
    setup_texts(menu);
    menu.background = sfSprite_create();
    sfSprite_setTexture(menu.background, menu.texturebg, sfTrue);
    sfMusic_setLoop(menu.music, sfTrue);
    sfMusic_play(menu.music);

    int seconds = 0;
    char const *filepath = av[1];
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("Pass map.txt in argument");
        return (84);
    }
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &menu.event)) {
        if (menu.event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(window);
        } else if (menu.event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyReturn)) {
            game(window, fd);
        }
        }
        drawanddisplay(menu, window);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.07) {
            if (seconds == 0) {
                sfSprite_setTexture(menu.dino, menu.dino1, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 1) {
                sfSprite_setTexture(menu.dino, menu.dino2, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 2) {
                sfSprite_setTexture(menu.dino, menu.dino3, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 3) {
                sfSprite_setTexture(menu.dino, menu.dino4, sfTrue);
                seconds = 0;
            }
            sfClock_restart(clock);
        }
    }
    destroy(menu, window);
    return (0);
}