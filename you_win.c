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

void setup_texxt(struct win wiin, float scoore)
{
    sfVector2f titlepos = {400, 0};
    sfVector2f footerpos = {1300, 200};
    sfVector2f textpos = {400, 200};
    sfVector2f scale = {2, 2};
    sfText_setString(wiin.title, "You win");
    sfText_setPosition(wiin.title, titlepos);
    sfText_setFont(wiin.title, wiin.font);
    sfText_setCharacterSize(wiin.title, 300);
    sfText_setString(wiin.text, "Your score is");
    sfText_setPosition(wiin.text, textpos);
    sfText_setFont(wiin.text, wiin.font);
    sfText_setCharacterSize(wiin.text, 300);
    sfText_setString(wiin.score, nb_tochar(scoore));
    sfText_setPosition(wiin.score, footerpos);
    sfText_setFont(wiin.score, wiin.font);
    sfText_setCharacterSize(wiin.score, 300);
}

void destroyyy(struct win wiin, sfRenderWindow* window)
{
    sfText_destroy(wiin.title);
    sfText_destroy(wiin.score);
    sfText_destroy(wiin.text);
    sfTexture_destroy(wiin.texturebg);
    sfSprite_destroy(wiin.background);
    sfRenderWindow_destroy(window);
}

void drawanddisplayyy(struct win wiin, sfRenderWindow* window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, wiin.background, NULL);
    sfRenderWindow_drawText(window, wiin.title, NULL);
    sfRenderWindow_drawText(window, wiin.score, NULL);
    sfRenderWindow_drawText(window,wiin.text, NULL);
    sfRenderWindow_display(window);
}

int win(sfRenderWindow* window, float scoore)
{
    struct win wiin;
    sfVideoMode mode = {1920, 1080, 32};
    sfClock* clock = sfClock_create();
    wiin.font = sfFont_createFromFile("Gilberto.ttf");
    wiin.title = sfText_create();
    wiin.score = sfText_create();
    wiin.text = sfText_create();
    wiin.texturebg = sfTexture_createFromFile("assets/backgrounds/bg.jpg", NULL);
    setup_texxt(wiin, scoore);
    wiin.background = sfSprite_create();
    sfSprite_setTexture(wiin.background, wiin.texturebg, sfTrue);

    int seconds = 0;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &wiin.event)) {
        if (wiin.event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(window);
        }
        }
        drawanddisplayyy(wiin, window);
    }
    destroyyy(wiin, window);
    return (0);
}