#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void playerMove(Sprite& playerSprite, Vector2f & moveRec);
void enemy1Move(Sprite& playerSprite, Sprite& enemy1Sprite, Vector2f& moveEnemy1, int& lifes);
void enemy2Move(Sprite& playerSprite, Sprite& enemy2Sprite, Vector2f& moveEnemy2, int& lifes);