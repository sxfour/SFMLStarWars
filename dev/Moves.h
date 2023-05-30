#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void playerMove(Sprite& playerSprite, Vector2f & moveRec, Text& playerText);
void enemy1Move(Sprite& playerSprite, Sprite& enemy1Sprite, Vector2f& moveEnemy1, int& lifes, Text& enemy1Text);
void enemy2Move(Sprite& playerSprite, Sprite& enemy2Sprite, Vector2f& moveEnemy2, int& lifes, Text& enemy2Text);