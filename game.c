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
#include <unistd.h>
#include "struct.h"

int game(sfRenderWindow* window, int fd)
{
    struct my_game game;
    sfVideoMode mode = {1920, 1080, 32};
    sfClock* clock = sfClock_create();
    sfClock* clockground = sfClock_create();
    sfClock* clockbg2 = sfClock_create();
    sfClock* clockbg3 = sfClock_create();
    sfClock* clockobs = sfClock_create();
    sfClock* clockhills = sfClock_create();
    sfClock* clockclouds = sfClock_create();
    int seconds = 0;
    int speed = 1;
    int k = 0;
    int event = 0;
    float scoore = 0;
    int nbobs = 0;

    sfVector2f dinopos = {10, 750};
    sfVector2f obspos = {800, 770};
    sfVector2f dinojump = {10, 700};
    sfVector2f dinoscale = {1.5, 1.5};
    sfVector2f textpos = {1800, 10};
    sfVector2f groundpos = {0, 0};
    sfVector2f bg2pos = {0, 0};
    sfVector2f bg3pos = {0,0};
    sfVector2f bgpos = {0,0};
    sfVector2f hillspos = {0,0};
    sfVector2f cloudspos = {0,0};

    game.font = sfFont_createFromFile("Gilberto.ttf");
    game.texturebg = sfTexture_createFromFile("assets/platformer_background_4/Layers/layer07_Sky.png", NULL);
    game.texturebg2 = sfTexture_createFromFile("assets/platformer_background_4/Layers/long_hills_castle.png", NULL);
    game.texturebg3 = sfTexture_createFromFile("assets/platformer_background_4/Layers/long_rocks.png", NULL);
    game.textureground = sfTexture_createFromFile("assets/platformer_background_4/Layers/groundlong.png", NULL);
    game.textureobs = sfTexture_createFromFile("assets/platformer_background_4/Layers/cactus.png", NULL);
    game.texturehills = sfTexture_createFromFile("assets/platformer_background_4/Layers/long_hills.png", NULL);
    game.textureclouds = sfTexture_createFromFile("assets/platformer_background_4/Layers/long_clouds.png", NULL);
    game.dino1 = sfTexture_createFromFile("assets/sprites/dino1a.png", NULL);
    game.dino2 = sfTexture_createFromFile("assets/sprites/dino2a.png", NULL);
    game.dino3 = sfTexture_createFromFile("assets/sprites/dino3a.png", NULL);
    game.dino4 = sfTexture_createFromFile("assets/sprites/dino4a.png", NULL);
    game.hit = sfMusic_createFromFile("musics/offline-sound-hit.wav");
    game.press = sfMusic_createFromFile("musics/offline-sound-press.wav");
    game.reached = sfMusic_createFromFile("musics/offline-sound-reached.wav");
    game.bg = sfSprite_create();
    game.bg2 = sfSprite_create();
    game.bg3 = sfSprite_create();
    game.dino = sfSprite_create();
    game.obs = sfSprite_create();
    game.score = sfText_create();
    game.ground = sfSprite_create();
    game.hills = sfSprite_create();
    game.clouds = sfSprite_create();
    game.bgrect.top = 0;
    game.bgrect.width = 1920;
    game.bgrect.left = 0;
    game.bgrect.height = 1080;
    sfText_setString(game.score, nb_tochar(scoore));
    sfText_setPosition(game.score, textpos);
    sfText_setFont(game.score, game.font);
    sfText_setCharacterSize(game.score, 100);
    sfSprite_setTexture(game.bg, game.texturebg, sfTrue);
    sfSprite_setTexture(game.bg2, game.texturebg2, sfTrue);
    sfSprite_setTexture(game.hills, game.texturehills, sfTrue);
    sfSprite_setTexture(game.clouds, game.textureclouds, sfTrue);
    sfSprite_setTexture(game.bg3, game.texturebg3, sfTrue);
    sfSprite_setTexture(game.ground, game.textureground, sfTrue);
    sfSprite_setTexture(game.obs, game.textureobs, sfTrue);

    char* buffer = malloc(sizeof(char* ) * 100);
    int nb_read = read(fd, buffer, 100);

    int z = 0;
    for(int i = 0; buffer[i] != '\0'; i++) {
        if(buffer[i] == '1') {
            z++;
        }
    }

    while(sfRenderWindow_isOpen(window)) {
        obspos.x -= speed;
        game.bgrect.width += speed;
        scoore = scoore +0.05;
        sfText_setString(game.score, nb_tochar(scoore));

        if (obspos.x < -400) {
            nbobs++;
            obspos.x = 1920;
            sfText_setString(game.score, nb_tochar(scoore));
        }
        sfSprite_getPosition(game.dino);
        sfSprite_getPosition(game.obs);

        if (obspos.x > dinopos.x - 100 && obspos.x < dinopos.x + 100 && obspos.y > dinopos.y - 50 && obspos.y < dinopos.y + 120) {
            sfMusic_play(game.hit);
            game_over(window,scoore);
        }
        while (sfRenderWindow_pollEvent(window, &game.event)) {
            if (game.event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfRenderWindow_close(window);
            }
            if(game.event.type == sfEvtKeyPressed) {
                if(game.event.key.code == sfKeySpace) {
                    sfMusic_play(game.press);
                    k = 1;
                }
            }
        }
                 if (k == 1) {
                    if (dinopos.y != 500 && event == 0) {
                        dinopos.y -= 2;
                    }
                    else if (dinopos.y == 500 && event == 0) {
                        event = 1;
                    }
                    else if (dinopos.y != 750 && event == 1) {
                        dinopos.y += 2;
                    }
                    else {
                        event = 0;
                        k = 0;
                    }
                }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game.bg, NULL);
        sfRenderWindow_drawSprite(window, game.bg3, NULL);
        sfRenderWindow_drawSprite(window, game.hills, NULL);
        sfRenderWindow_drawSprite(window, game.clouds, NULL);
        sfSprite_setPosition(game.bg2, bg2pos);
        sfRenderWindow_drawSprite(window, game.bg2, NULL);
        sfSprite_setPosition(game.dino, dinopos);
        sfRenderWindow_drawSprite(window, game.dino, NULL);
        sfSprite_setPosition(game.obs, obspos);
        sfRenderWindow_drawSprite(window, game.obs, NULL);
        sfSprite_setPosition(game.ground, groundpos);
        sfRenderWindow_drawSprite(window, game.ground, NULL);
        sfRenderWindow_drawText(window,game.score, NULL);
        sfRenderWindow_display(window);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clockground)) > 0.03) {
            groundpos.x -= 20;
            sfClock_restart(clockground);
            if (groundpos.x == -1920) {
                groundpos.x = 0;
            }
        }

        if(sfTime_asSeconds(sfClock_getElapsedTime(clockhills)) > 0.05) {
            hillspos.x -= 1;
            sfClock_restart(clockhills);
            if (groundpos.x == -1920) {
                groundpos.x = 0;
            }
        }

        if(sfTime_asSeconds(sfClock_getElapsedTime(clockclouds)) > 0.05) {
            cloudspos.x -= 1;
            sfClock_restart(clockclouds);
            if (cloudspos.x == -1920) {
                cloudspos.x = 0;
            }
        }

        if (sfTime_asSeconds(sfClock_getElapsedTime(clockobs)) > 0.03) {
            if (nbobs != z) {
            obspos.x -= 20;
            sfClock_restart(clockobs);
            if (obspos.x == 0) {
            }
            } else if (nbobs == z) {
            win(window,scoore);
        }
        }

        if (sfTime_asSeconds(sfClock_getElapsedTime(clockbg2)) > 0.1) {
            bg2pos.x -= 1;
            sfClock_restart(clockbg2);
            if (bg2pos.x == -1920) {
                bg2pos.x = 0;
            }
        }
        if (sfTime_asSeconds(sfClock_getElapsedTime(clockbg3)) > 0.05) {
            bg3pos.x -= 1;
            sfClock_restart(clockbg3);
            if (bg3pos.x == -1920) {
                bg3pos.x = 0;
            }
        }
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.03) {
            if (seconds == 0) {
                sfSprite_setTexture(game.dino, game.dino1, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 1) {
                sfSprite_setTexture(game.dino, game.dino2, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 2) {
                sfSprite_setTexture(game.dino, game.dino3, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 3) {
                sfSprite_setTexture(game.dino, game.dino4, sfTrue);
                seconds = 0;
            }
            sfClock_restart(clock);
        }
    }
    sfTexture_destroy(game.dino1);
    sfTexture_destroy(game.dino2);
    sfTexture_destroy(game.dino3);
    sfTexture_destroy(game.dino4);
    sfSprite_destroy(game.ground);
    sfSprite_destroy(game.hills);
    sfSprite_destroy(game.clouds);
    sfSprite_destroy(game.bg3);
    sfSprite_destroy(game.bg2);
    sfSprite_destroy(game.bg);
    sfTexture_destroy(game.texturebg2);
    sfTexture_destroy(game.texturebg);
    sfTexture_destroy(game.textureground);
    sfTexture_destroy(game.textureobs);
    sfTexture_destroy(game.texturehills);
    sfTexture_destroy(game.textureclouds);
    sfSprite_destroy(game.dino);
    sfSprite_destroy(game.obs);
    sfMusic_destroy(game.press);
    sfMusic_destroy(game.hit);
    sfMusic_destroy(game.reached);
    sfRenderWindow_destroy(window);
}