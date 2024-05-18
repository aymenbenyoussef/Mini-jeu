#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include "Animation.h"
#include "Player.h"
#include<sstream>
#include <random>
//Window dimensions
const unsigned int WINDOW_WIDTH = 1280;//1280
const unsigned int WINDOW_HEIGHT = 720;//720
const float PLAYER_FRAME_WIDTH = 136.0f;//136
const float PLAYER_FRAME_HEIGHT = 20.0f;
const unsigned int BALL_SPEED = 7;
const float PLAYER_SPEED = 500.0f;


void Movebarre(sf::CircleShape& ball, sf::Vector2f& position, sf::Vector2f& velocity)
{
	if (position.y > WINDOW_HEIGHT)
	{
		position.y = 0;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> distr(0, WINDOW_WIDTH);
		position.x = distr(gen);
		position.x = distr(gen);
		ball.setPosition(position);
	}
	else {
		position.y += velocity.y;
		ball.setPosition(position);

	}

}
bool checkCollision(const sf::RectangleShape& playerBody, const sf::CircleShape&
	ball) {
	return playerBody.getGlobalBounds().intersects(ball.getGlobalBounds());
}
int main()
{
	bool gamePaused = false;
	bool restart = false;
	int start = 1;
	do {
		gamePaused = false;
		restart = false;
		int BALL_SPEED = 7;

		

		
		//Init
		sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
			"MyGame");
		window.setFramerateLimit(60);
		//BackgroundAudio Buffer
		sf::SoundBuffer backgroundAudioBuffer;
		backgroundAudioBuffer.loadFromFile("audio/sound2.ogg");
		// Chargement du background audio
		sf::Sound backgroundAudio;
		backgroundAudio.setBuffer(backgroundAudioBuffer);
		// gameOverSound Buffer
		sf::SoundBuffer gameOverSoundBuffer;
		gameOverSoundBuffer.loadFromFile("audio/gameover_sound.wav");
		// Chargement du game over sound
		sf::Sound gameOverSound;
		gameOverSound.setBuffer(gameOverSoundBuffer);
		//----------------------------------
		// Lecture du background audio
		backgroundAudio.setLoop(true);
	    backgroundAudio.play();
		// background -----------------------------------------
		//Texture
		sf::Texture backgroundTexture;
		backgroundTexture.loadFromFile("images/back2.jpeg");
		//Sprite
		sf::Sprite backgroundSprite(backgroundTexture);


		sf::Font font;
		font.loadFromFile("font/RoughenCornerRegular-7RjV.ttf");
		sf::Text timeText;
		timeText.setFont(font);
		timeText.setCharacterSize(40);
		timeText.setFillColor(sf::Color::Red);
		timeText.setPosition(50, 10);
		// Timer
		sf::Clock timer;
		timer.restart();
		// Game Over Texture et Sprite
		sf::Texture gameOverTexture;
		gameOverTexture.loadFromFile("images/gameover.png");
		sf::Sprite gameOverSprite;
		gameOverSprite.setTexture(gameOverTexture);

		gameOverSprite.setPosition(WINDOW_WIDTH / 2 -
		gameOverSprite.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 -
		gameOverSprite.getGlobalBounds().height / 2);
		// ball1 -------------------------------------------------
		sf::Texture ballTexture;
		ballTexture.loadFromFile("images/bbb.png");
		sf::CircleShape ball1(15.0f);
		ball1.setTexture(&ballTexture);
		sf::Vector2f ball1Position(100, 0);
		ball1.setPosition(ball1Position);
		sf::Vector2f ball1Velocity;
		ball1Velocity.x = BALL_SPEED;
		ball1Velocity.y = BALL_SPEED;

		// ball2 -------------------------------------------------
		sf::CircleShape ball2(40.0f);
		ball2.setTexture(&ballTexture);
		sf::Vector2f ball2Position(250, -500);
		ball2.setPosition(ball2Position);
		sf::Vector2f ball2Velocity;
		ball2Velocity.x = BALL_SPEED;
		ball2Velocity.y = BALL_SPEED;
		// ball3 -------------------------------------------------
		sf::CircleShape ball3(50.0f);
		ball3.setTexture(&ballTexture);
		sf::Vector2f ball3Position(400, -100);
		ball3.setPosition(ball3Position);
		sf::Vector2f ball3Velocity;
		ball3Velocity.x = BALL_SPEED;
		ball3Velocity.y = BALL_SPEED;
		// ball4 -------------------------------------------------
		sf::CircleShape ball4(25.0f);
		ball4.setTexture(&ballTexture);
		sf::Vector2f ball4Position(550, -300);
		ball4.setPosition(ball4Position);
		sf::Vector2f ball4Velocity;
		ball4Velocity.x = BALL_SPEED;
		ball4Velocity.y = BALL_SPEED;
		// ball5 -------------------------------------------------

		sf::CircleShape ball5(35.0f);
		ball5.setTexture(&ballTexture);
		sf::Vector2f ball5Position(750, -200);
		ball5.setPosition(ball5Position);
		sf::Vector2f ball5Velocity;
		ball5Velocity.x = BALL_SPEED;
		ball5Velocity.y = BALL_SPEED;
		// player Sprite ...................................................
		sf::Texture playerTexture;
		playerTexture.loadFromFile("images/carac2.png");

		//..................................................
		Player player(&playerTexture, sf::Vector2u(1, 1), 0.08f, PLAYER_SPEED);
		float deltaTime = 0.0f;
		sf::Clock playerClock;
		// ..........................................................
		
		//Window Loop
		sf::Text scoreText;
		scoreText.setFont(font);
		scoreText.setCharacterSize(50); // en pixels
		scoreText.setFillColor(sf::Color::White);
		scoreText.setOutlineThickness(1);
		scoreText.setPosition(550, 8);
		int score = 0;

		
		

		while (window.isOpen())
		{

			// player deltatime ......................................
		deltaTime = playerClock.restart().asSeconds();
		//event
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed: window.close(); break;
				default: break;
				}
			}

			if (gamePaused == false) {
				// Compteur du temps �coul�
				int seconds = timer.getElapsedTime().asSeconds();
				
				std::stringstream time;
				time << "Time: " << seconds << "s";
				timeText.setString(time.str());
				//-------------------------------- Movements --------------------------
				std::stringstream ss;
				ss << "Score: " << score;
				scoreText.setString(ss.str());
				//----------------
				if (seconds > 10) {
					ball1Velocity.x = 9;
					ball1Velocity.y = 9;
					ball2Velocity.x = 9;
					ball2Velocity.y = 9;
					ball3Velocity.x = 9;
					ball3Velocity.y = 9;
					ball4Velocity.x = 9;
					ball4Velocity.y = 9;
					ball5Velocity.x = 9;
					ball5Velocity.y = 9;
				}
				if (seconds > 20) {
					ball1Velocity.x = 11;
					ball1Velocity.y = 11;
					ball2Velocity.x = 10;
					ball2Velocity.y = 10;
					ball3Velocity.x = 11;
					ball3Velocity.y = 11;
					ball4Velocity.x = 9;
					ball4Velocity.y = 9;
					ball5Velocity.x = 11;
					ball5Velocity.y = 11;
				}
				if (seconds > 30) {
					ball1Velocity.x = 12;
					ball1Velocity.y = 12;
					ball2Velocity.x = 10;
					ball2Velocity.y = 10;
					ball3Velocity.x = 12;
					ball3Velocity.y = 12;
					ball4Velocity.x = 10;
					ball4Velocity.y = 10;
					ball5Velocity.x = 12;
					ball5Velocity.y = 12;
				}
				if (seconds > 60) {
					ball1Velocity.x = 13;
					ball1Velocity.y = 13;
					ball2Velocity.x = 12;
					ball2Velocity.y = 12;
					ball3Velocity.x = 13;
					ball3Velocity.y = 13;
					ball4Velocity.x = 12;
					ball4Velocity.y = 12;
					ball5Velocity.x = 13;
					ball5Velocity.y = 13;
				}
				if (ball1Position.y > WINDOW_HEIGHT or ball2Position.y > WINDOW_HEIGHT or ball3Position.y > WINDOW_HEIGHT or ball4Position.y > WINDOW_HEIGHT or ball5Position.y > WINDOW_HEIGHT) {
					score++;
				}
				//Movement
				//ball1 Movement
				Movebarre(ball1, ball1Position, ball1Velocity);
				//ball2 Movement
				Movebarre(ball2, ball2Position, ball2Velocity);
				//ball3 Movement
				Movebarre(ball3, ball3Position, ball3Velocity);
				//barre4 movement
				Movebarre(ball4, ball4Position, ball4Velocity);
				//barre5 movement
				Movebarre(ball5, ball5Position, ball5Velocity);
				// player animation ......................................
				//animation.update(0, deltaTime, false);

				//....................................

				//player.setTextureRect(animation.uvRect);

				//.............................
				if (checkCollision(player.getBody(), ball1) || checkCollision(player.getBody(),
					ball2) || checkCollision(player.getBody(), ball3) || checkCollision(player.getBody(), ball4) || checkCollision(player.getBody(), ball5)) {
					gamePaused = true;
					backgroundAudio.stop();
					gameOverSound.play();

					// Play game over sound and stop background audio

				}
			}

			player.update(deltaTime);

			window.clear();
			//drawing : Rendering
			window.draw(backgroundSprite);
			//window.draw(player); //..............................
			if (start == 1) {
				gamePaused = true;
				sf::Text StartText;
				timer.restart();
				StartText.setFont(font);
				StartText.setString("Press 'Enter' To start the game");
				StartText.setCharacterSize(70);
				StartText.setOutlineThickness(1);
				StartText.setFillColor(sf::Color::Black);
				StartText.setPosition(200, 200);
				window.draw(StartText);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					gamePaused = false;
					restart = false;
					start = 0;
				}

			}
			else if (gamePaused == false and start == 0 ) {
				player.draw(window); ///////
				//window.draw(playerSprite);
				
				window.draw(ball1);
				window.draw(ball2);
				window.draw(ball3);
				window.draw(ball4);
				window.draw(ball5);
				window.draw(scoreText);
				window.draw(timeText);
			}
			else if (gamePaused == true and start == 0)
			{
				window.draw(gameOverSprite);
				sf::Text gameOverText;
				gameOverText.setFont(font);
				gameOverText.setString(" Press 'R' to Restart or 'Esc' to Exit.");
				gameOverText.setCharacterSize(50);
				gameOverText.setOutlineThickness(1);
				gameOverText.setFillColor(sf::Color::Black);
				gameOverText.setPosition(300, 450);
				window.draw(gameOverText);
				window.draw(scoreText);
				window.draw(timeText);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{

					restart = true;
					window.close();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}


			}
			

			

			window.display();
		}

	} while (restart);
	return 0;
}