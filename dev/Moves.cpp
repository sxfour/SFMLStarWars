#include "Moves.h"


// Движение игрока
void playerMove(Sprite& playerSprite, Vector2f& moveRec) {
	playerSprite.move(moveRec);

	Vector2f playerPos = playerSprite.getPosition();

	if (playerPos.x > 800) { 
		playerSprite.setPosition(800, playerPos.y);
	}
	if (playerPos.x < 10) { 
		playerSprite.setPosition(10, playerPos.y);
	}
	if (playerPos.y < 70) { 
		playerSprite.setPosition(playerPos.x, 70);
	}
	if (playerPos.y > 510) { 
		playerSprite.setPosition(playerPos.x, 510);
	}

	if ((playerPos.x > 800) && (playerPos.y < 510)) { 
		playerSprite.setPosition(800, 70);
	}
	if ((playerPos.x > 800) && (playerPos.y > 70)) { 
		playerSprite.setPosition(800, 510);
	}
	if ((playerPos.x < 10) && (playerPos.y < 70)) { 
		playerSprite.setPosition(10, 70);
	}
	if ((playerPos.x < 10) && (playerPos.y > 510)) { 
		playerSprite.setPosition(10, 510);
	}
}

// Движение врага к игроку
void enemy1Move(Sprite& playerSprite, Sprite& enemy1Sprite, Vector2f& moveEnemy1, int& lifes) {
	float randomX = (float)(rand() % 800) + 800;
	float randomY = (float)(rand() % 500) + 50;

	float playerPosY = playerSprite.getPosition().y;
	float playerPosX = playerSprite.getPosition().x;

	float enemy1PosY = enemy1Sprite.getPosition().y;
	float enemy1PosX = enemy1Sprite.getPosition().x;

	moveEnemy1.y = (playerPosY - enemy1PosY) / 40;
	moveEnemy1.x = -5;

	enemy1Sprite.move(moveEnemy1);

	// Условие попадания врага по игроку
	if (((playerSprite.getGlobalBounds().left >= enemy1Sprite.getGlobalBounds().left) && (playerPosX <= enemy1PosX)) 
		|| ((playerSprite.getGlobalBounds().top >= enemy1Sprite.getGlobalBounds().top) && (playerPosY <= enemy1PosY))) {
		enemy1Sprite.setPosition(randomX, randomY);

		// Счётчик жизни
		lifes--;
	}

	// Выход за границы игровой области
	if (enemy1PosX < -200) {
		enemy1Sprite.setPosition(randomX, randomY);
	}
}

void enemy2Move(Sprite& playerSprite, Sprite& enemy2Sprite, Vector2f& moveEnemy2, int& lifes) {
	float randomX = (float)(rand() % 1600) + 600;
	float randomY = (float)(rand() % 500) + 50;

	float playerPosY = playerSprite.getPosition().y;
	float playerPosX = playerSprite.getPosition().x;

	float enemy2PosY = enemy2Sprite.getPosition().y;
	float enemy2PosX = enemy2Sprite.getPosition().x;

	moveEnemy2.y = (playerPosY - enemy2PosY) / 20;
	moveEnemy2.x = -10;

	enemy2Sprite.move(moveEnemy2);

	// Условие попадания врага по игроку
	if (((playerSprite.getGlobalBounds().left >= enemy2Sprite.getGlobalBounds().left) && (playerPosX <= enemy2PosX - 5))
		|| ((playerSprite.getGlobalBounds().top >= enemy2Sprite.getGlobalBounds().top) && (playerPosY <= enemy2PosY - 5))) {
		enemy2Sprite.setPosition(randomX, randomY);

		// Счётчик жизни
		lifes--;
	}

	// Выход за границы игровой области
	if (enemy2PosX < -400) {
		enemy2Sprite.setPosition(randomX, randomY);
	}
}
