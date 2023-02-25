//
// Created by lenovo on 25/02/2023.
//

#include "kapal.h"
#include <iostream>
#include <cstdlib>
#include <math.h>


void Kapal::setX(int x) {
    this->position_x=x;
}
void Kapal::setY(int y) {
    this->position_y=y;
}
void Kapal::setHealth(int health) {
    this->health=health;
}

void Kapal::move(string direction) {
    if (direction=="up"){
        setY(this->position_y+1);
    } else if (direction=="down"){
        setY(this->position_y-1);
    } else if (direction=="left"){
        setX(this->position_x-1);
    } else if (direction=="right"){
        setX(this->position_x+1);
    }
}

void Kapal::attack(Kapal &other) {
    // calculate range
    int range = this->calculateRange(other);
    if (range<=this->max_shoot_range){
        other.health-=this->damage;
        cout << "Attack success" << endl;
    }
    else {
        cout << "Out of range" << endl;
    }
}

int Kapal::calculateRange(Kapal other) {
    int x = abs(this->position_x-other.position_x)*abs(this->position_x-other.position_x);
    int y = abs(this->position_y-other.position_y)*abs(this->position_y-other.position_y);
    return sqrt(x+y);
}

void Kapal::decreaseHealth(int damage) {
    this->health-=damage;
}



int Kapal::getX() {
    return this->position_x;
}
int Kapal::getY() {
    return this->position_y;
}
string Kapal::getName() {
    return this->name;
}
int Kapal::getHealth() {
    return this->health;
}
int Kapal::getDamage() {
    return this->damage;
}
int Kapal::getMaxShootRange() {
    return this->max_shoot_range;
}
bool Kapal::isDeath() {
    return this->health<=0;
}
