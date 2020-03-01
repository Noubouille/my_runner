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

void setup_text(struct lose loose, float scoore)
{
    sfVector2f titlepos = {400, 0};
    sfVector2f footerpos = {1300, 200};
    sfVector2f textpos = {400, 200};
    sfVector2f scale = {2, 2};
    sfText_setString(loose.title, "You loose");
    sfText_setPosition(loose.title, titlepos);
    sfText_setFont(loose.title, loose.font);
    sfText_setCharacterSize(loose.title, 300);
    sfText_setString(loose.text, "Your score is");
    sfText_setPosition(loose.text, textpos);
    sfText_setFont(loose.text, loose.font);
    sfText_setCharacterSize(loose.text, 300);
    sfText_setString(loose.score, nb_tochar(scoore));
    sfText_setPosition(loose.score, footerpos);
    sfText_setFont(loose.score, loose.font);
    sfText_setCharacterSize(loose.score, 300);
}

void destroyy(struct lose loose, sfRenderWindow* window)
{
    sfText_destroy(loose.title);
    sfText_destroy(loose.score);
    sfText_destroy(loose.text);
    sfTexture_destroy(loose.texturebg);
    sfSprite_destroy(loose.background);
    sfRenderWindow_destroy(window);
}

void drawanddisplayy(struct lose loose, sfRenderWindow* window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, loose.background, NULL);
    sfRenderWindow_drawText(window, loose.title, NULL);
    sfRenderWindow_drawText(window, loose.score, NULL);
    sfRenderWindow_drawText(window,loose.text, NULL);
    sfRenderWindow_display(window);
}

int game_over(sfRenderWindow* window, float scoore)
{
    struct lose loose;
    sfVideoMode mode = {1920, 1080, 32};
    sfClock* clock = sfClock_create();
    loose.font = sfFont_createFromFile("Gilberto.ttf");
    loose.title = sfText_create();
    loose.score = sfText_create();
    loose.text = sfText_create();
    loose.texturebg = sfTexture_createFromFile("assets/backgrounds/bggameover.jpg", NULL);
    setup_text(loose, scoore);
    loose.background = sfSprite_create();
    sfSprite_setTexture(loose.background, loose.texturebg, sfTrue);

    int seconds = 0;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &loose.event)) {
        if (loose.event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(window);
        }
        }
        drawanddisplayy(loose, window);
    }
    destroyy(loose, window);
    return (0);
}