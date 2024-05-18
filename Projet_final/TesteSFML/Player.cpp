#include "player.h"
Player::Player(sf::Texture* texture, sf::Vector2u totalImages, float switchingTime,
	float playerSpeed) : animation(texture, totalImages, switchingTime)
{
	this->playerSpeed = playerSpeed;
	rowNumber = 0;
	playerFacingRight = true;
	playerBody.setSize(sf::Vector2f(100.0f, 100));
	playerBody.setPosition(640.0f, 400.0f);
	playerBody.setTexture(texture);
}

// Fonction de mise � jour pour g�rer le mouvement et l'animation du joueur
void Player::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	// V�rifie les entr�es du clavier pour le mouvement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

		movement.x -= playerSpeed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += playerSpeed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		movement.y -= playerSpeed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		movement.y += playerSpeed * deltaTime;
	// D�finit la ligne de l'animation en fonction du mouvement
	/*if (movement.x == 0.0f)
		rowNumber = 0;
	else
	{
		rowNumber = 0;
		if (movement.x > 0.0f)
			playerFacingRight = true;
		else
			playerFacingRight = false;
	}*/

	// Met � jour l'animation en fonction du mouvement et de la direction
	animation.update(rowNumber, deltaTime, playerFacingRight);
	// D�place le corps du joueur
	playerBody.setTextureRect(animation.uvRect);
	playerBody.move(movement);
}
sf::RectangleShape Player::getBody()
{
	return playerBody;
}
// Fonction pour dessiner le joueur sur la fen�tre
void Player::draw(sf::RenderWindow& window)
{
	window.draw(playerBody);
}

