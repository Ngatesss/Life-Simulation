#pragma once
#include "NEAT.hpp"
#include "raylib.h"

enum EntityType {
    NO,
    PREY,
    PREDATOR,
};

class Entity {
    public:
    Entity(float x,float y, EntityType EntType, int nb_in,int nb_out) {
        this->x = x;
        this->y = y;
        this->EntType = EntType;
        agent = new Agent(new Genome(nb_in,nb_out));
    }

    Agent* agent;
    float x;
    float y;
    float orientation = 0.f; // between 0 and 2pi

    EntityType EntType;

    void update() {
        x += cos(orientation);
        y += sin(orientation);
    }

    void draw() const {
        DrawCircle(x,y, 5.0f, { 0, 228, 48, 100 });
        DrawCircle(x,y, 3.5f, { 0, 228, 48, 100 });
        DrawCircle(x+cos(orientation)*2,y+sin(orientation)*2, 1.5f, GOLD);
    }
};
