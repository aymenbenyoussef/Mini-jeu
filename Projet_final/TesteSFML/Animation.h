#pragma once
#include<SFML/Graphics.hpp>

// D�finition de la classe Animation
class Animation
{
private:
    // Temps total �coul� depuis le d�but de l'animation
    float elapsedTime;
    // Temps n�cessaire pour passer � l'image suivante dans l'animation
    float switchingTime;
    // Nombre total d'images dans la texture (en lignes : 1, colonnes : 10)
    sf::Vector2u totalImages;
    // Position de l'image courante dans la texture (ligne, colonne)
    sf::Vector2u currentImagePosition;

    
public:
    // Rectangle d'encadrement dans la texture pour afficher l'image courante
    sf::IntRect uvRect;

    // Param�tres : la texture de l'animation, le nombre d'images dans la texture et le temps de changement d'image
    Animation(sf::Texture* texture, sf::Vector2u totalImages, float switchingTime);

    // M�thode pour mettre � jour l'animation
    // Param�tres : le num�ro de ligne dans la texture, le temps �coul� depuis la derni�re mise � jour et la direction de l'animation
    // Dans notre cas nous n'avons qu'une seule ligne

    void update(int rowNumber, float deltaTime, bool playerFacingRight);

};


