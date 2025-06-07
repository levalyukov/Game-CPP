#include "animations.h"

void Animations::UpdateAnimation(
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
    timer += 0.16f;
    if (timer >= frameDuration) {
        sprite.setTexture(texture);
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