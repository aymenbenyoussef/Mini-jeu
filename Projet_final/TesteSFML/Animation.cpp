#include "animation.h"
Animation::Animation(sf::Texture* texture, sf::Vector2u totalImages, float
	switchingTime)
{
	this->totalImages = totalImages;
	this->switchingTime = switchingTime;
	// Initialisation du temps écoulé à zéro
	elapsedTime = 0.0f;
	// Initialisation de la position de l'image courante sur l'axe horizontal à 0
	currentImagePosition.x = 0;
	// Calcul de la largeur et de la hauteur de chaque image dans la texture
	uvRect.width = texture->getSize().x / float(totalImages.x);
	uvRect.height = texture->getSize().y / float(totalImages.y);
}
void Animation::update(int rowNumber, float deltaTime, bool playerFacingRight)
{
	// Définition du numéro de ligne de l'image courante dans la texture
	currentImagePosition.y = rowNumber;
	// Ajout du temps écoulé depuis la dernière mise à jour
	elapsedTime += deltaTime;
	if (elapsedTime >= switchingTime)
	{
		// Réinitialisation du temps écoulé
		elapsedTime -= switchingTime;
		// Passage à l'image suivante sur l'axe horizontal
		currentImagePosition.x++;
		// Vérification si la dernière image de la ligne a été atteinte
		if (currentImagePosition.x >= totalImages.x)
		{
			currentImagePosition.x = 0;
			// Retour à la première image de la ligne

		}
	}

	// Définition de la position verticale du rectangle d'encadrement dans la
	//texture
		//uvRect.top = currentImagePosition.y * uvRect.height;
	// Vérification de la direction du joueur

	if (playerFacingRight)
	{
		// Si le joueur regarde vers la droite, la position horizontale est définie
		//directement
		uvRect.left = currentImagePosition.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		// Si le joueur regarde vers la gauche, la position horizontale est inversée
		uvRect.left = (currentImagePosition.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	//uvRect.left = currentImagePosition.x * uvRect.width;
	//uvRect.width = abs(uvRect.width);
}