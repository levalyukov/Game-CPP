#include "animations.hpp"

void Animations::setAnimation(
    sf::Sprite& sprite,
    sf::Texture& texture,
    sf::Vector2i& animStart,
    int frameCount,
    int frameX,
    int frameY,
    float& timer,
    float frameDuration,
    float deltaTime
) {
    timer += deltaTime;

    sprite.setTexture(texture);
    sprite.setTextureRect(
        sf::IntRect(
            animStart.x, animStart.y,
            frameX, frameY
        )
    );

    if (timer >= frameDuration) {
        timer = 0;

        animStart.x += frameX;
        if (animStart.x >= frameX * frameCount) {
            animStart.x = 0;
        }

        sprite.setTextureRect(
            sf::IntRect(
                animStart.x, animStart.y,
                frameX, frameY
            )
        );
    }
}