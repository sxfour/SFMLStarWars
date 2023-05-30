#include "Moves.h"

int main() {
	setlocale(LC_ALL, "Russian");

	// Параметры запуска окна
	RenderWindow window(VideoMode(900, 600), "SFMLStarWars", Style::Titlebar | Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(120);

	// Иконка приложения
	Image icon;
	if (!icon.loadFromFile("Images/icon.png")) {
		return EXIT_FAILURE;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());


	// Игровая панель
	Texture TextureInfoPanel;
	TextureInfoPanel.loadFromFile("Images/panel1.png");

	Texture TextureInfoPanel2;
	TextureInfoPanel2.loadFromFile("Images/panel2.png");

	Texture TextureInfoPanel3;
	TextureInfoPanel3.loadFromFile("Images/panel3.png");

	RectangleShape GameInfoPanel(Vector2f(900, 50));
	GameInfoPanel.setTexture(&TextureInfoPanel);
	GameInfoPanel.setPosition(Vector2f(0, 10));

	// Задний фон
	Texture textureBackground;
	if (!textureBackground.loadFromFile("Images/background.png")) {
		return EXIT_FAILURE;
	}
	textureBackground.setRepeated(true);

	Sprite spriteBackground(textureBackground);
	spriteBackground.setPosition(0, 0);
	spriteBackground.setColor(Color(255, 255, 255, 200));


	// Шейдер к фону
	Shader parallaxShader;
	parallaxShader.loadFromMemory(
		"uniform float offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, Shader::Vertex);

	// Шрифт и текст
	Font pixelFont;
	if (!pixelFont.loadFromFile("Fonts/simplePixels.ttf")) {
		return EXIT_FAILURE;
	}

	Text pauseText("PAUSE", pixelFont, 30);
	pauseText.setPosition(10, 560);

	Text infoText("DEBUG v0.1  Controls - W A S D, Pause - pause, Esc - exit", pixelFont, 18);
	infoText.setPosition(130, 570);

	Text playerText("", pixelFont, 18);
	playerText.setFillColor(Color::White);

	Text enemy1Text("", pixelFont, 18);
	enemy1Text.setFillColor(Color::Yellow);

	Text enemy2Text("", pixelFont, 18);
	enemy2Text.setFillColor(Color::Yellow);

	// Игрок
	Texture playerTexture;
	playerTexture.loadFromFile("Images/player1.png");

	Sprite playerSprite;
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(IntRect(0, 0, 95, 81));
	playerSprite.setPosition(20, 300);

	// Враг 1
	Texture enemy1Texture;
	enemy1Texture.loadFromFile("Images/enemy1.png");

	Sprite enemy1Sprite;
	enemy1Sprite.setTexture(enemy1Texture);
	enemy1Sprite.setTextureRect(IntRect(0, 0, 95, 81));
	enemy1Sprite.setPosition(800, 100);

	// Враг 2
	Texture enemy2Texture;
	enemy2Texture.loadFromFile("Images/enemy2.png");

	Sprite enemy2Sprite;
	enemy2Sprite.setTexture(enemy2Texture);
	enemy2Sprite.setTextureRect(IntRect(0, 0, 95, 81));
	enemy2Sprite.setPosition(1000, 400);

	// Переменные
	Vector2f moveRec, moveEnemy1, moveEnemy2;
	Clock clock;

	float offset = 0.f;
	int frameTimer = 0;
	int lifes = 3;
	bool gamePause = false;

	// Основной цикл игры
	while (window.isOpen()) {
		Event event;
		frameTimer = static_cast<int>(std::round(offset * 15)) % 2;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			switch (event.type) {
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Pause) { gamePause = !gamePause; }
				if (event.key.code == Keyboard::Escape) { window.close(); }
				if ((event.key.code == Keyboard::S)) { moveRec.y = 7.5; }
				if ((event.key.code == Keyboard::W)) { moveRec.y = -7.5; }
				if ((event.key.code == Keyboard::A)) {  moveRec.x = -7.5; }
				if ((event.key.code == Keyboard::D)) { moveRec.x = 7.5; }

				break;
			case Event::KeyReleased:
				if ((event.key.code == Keyboard::S)) { moveRec.y = 0; }
				if ((event.key.code == Keyboard::W)) { moveRec.y = 0; }
				if ((event.key.code == Keyboard::A)) { moveRec.x = 0; }
				if ((event.key.code == Keyboard::D)) { moveRec.x = 0; }

				break;
			default:

				break;
			}
		}

		if (!gamePause) {

			// Счетчик жизни игрока
			if (lifes == 2) { GameInfoPanel.setTexture(&TextureInfoPanel2); }
			else if (lifes == 1) { GameInfoPanel.setTexture(&TextureInfoPanel3); }
			else if (lifes == 0) { lifes = 3; }

			// Движение песонажей
			playerMove(playerSprite, moveRec, playerText);
			enemy1Move(playerSprite, enemy1Sprite, moveEnemy1, lifes, enemy1Text);
			enemy2Move(playerSprite, enemy2Sprite, moveEnemy2, lifes, enemy2Text);

			// Анимация персонажей
			if (frameTimer) {
				playerSprite.setTextureRect(IntRect(95, 0, 95, 81));
				enemy1Sprite.setTextureRect(IntRect(95, 0, 95, 81));
				enemy2Sprite.setTextureRect(IntRect(95, 0, 95, 81));
			}
			else {
				playerSprite.setTextureRect(IntRect(0, 0, 95, 81));
				enemy1Sprite.setTextureRect(IntRect(0, 0, 95, 81));
				enemy2Sprite.setTextureRect(IntRect(0, 0, 95, 81));
			}

			// Шейдер заднего фона
			parallaxShader.setUniform("offset", offset += clock.restart().asSeconds() / 5);

			// Отрисовка
			window.clear();
			window.draw(spriteBackground, &parallaxShader);
			window.draw(GameInfoPanel);
			window.draw(infoText);

			window.draw(playerSprite);
			window.draw(playerText);

			window.draw(enemy1Sprite);
			window.draw(enemy1Text);

			window.draw(enemy2Sprite);
			window.draw(enemy2Text);

			window.display();
		}
		else {
			// Шейдер заднего фона
			parallaxShader.setUniform("offset", offset += clock.restart().asSeconds() / 20);

			window.clear();
			window.draw(spriteBackground, &parallaxShader);
			window.draw(GameInfoPanel);
			window.draw(playerSprite);
			window.draw(enemy1Sprite);
			window.draw(enemy2Sprite);
			window.draw(pauseText);
			window.display();
		}
	}

	return EXIT_SUCCESS;
}