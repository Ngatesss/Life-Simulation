//
// Created by antoi on 26/06/2026.
//
#pragma once
#include "Entity.hpp"
#include "NEAT/Mutator.hpp"

class Simulation {
public:
    Simulation(int size_x, int size_y) {
        this->size_x = size_x;
        this->size_y = size_y;
        mutator = Mutator();
    }

    void init() {
        for (int i = 0; i < nb_entity; i++) {
            entities.push_back(
                new Entity(RNGfloat<float>::get(size_x),RNGfloat<float>::get(size_y),PREY,2,1)
                );
        }
    }

    void update() {
        for (int i = 0; i < nb_entity; i++) {
            entities.at(i)->update();
        }
    }

    void draw() {
        for (int i = 0; i < nb_entity; i++) {
            entities.at(i)->draw();
        }

    }

    int size_x, size_y;
    int nb_entity = 10;

    Mutator mutator;

    std::vector<Entity*> entities;
};
