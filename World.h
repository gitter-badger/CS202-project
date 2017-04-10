//World.h
//CS202 Final Proj
//Auth: William Horn
//4.9.2017
#ifndef WORLD_H
#define WORLD_H

#include "globals.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class World{
    private:
        /* Easily change shapes later if needed */
        typedef sf::RectangleShape StarShape;
        typedef sf::RectangleShape BulletShape;
        typedef sf::RectangleShape EnemyShape;
        typedef sf::CircleShape ShipShape;

        /* Player Ship Object */
        ShipShape playerShip;

        /* Main Containers for game entities*/
        std::vector<BulletShape> bullets;
        std::vector<StarShape> stars;
        std::vector<EnemyShape> enemies;

        /* Utility Functions for bullets */
        void makeBullet(float bulletX, float bulletY);
        void updateBullets();

        /* Utility Functions for Stars */
        void makeStar(float startingHeight);
        void populateInitialStars();
        void updateStars();

        /* Utility Functions for player ship */
        void shipSettings();
        void updateShip();
        std::vector<bounds> shipOnBound();

    public:
        World();

        /* SFML Window */
        static sf::RenderWindow screen;

        void draw();
        void update();
        void display();

        /* Random Real Generators */
        static std::random_device r;
        static std::mt19937 rng;
        static std::uniform_real_distribution<float> starDist;
};



#endif // WORLD_H