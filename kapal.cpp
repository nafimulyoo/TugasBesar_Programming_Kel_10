//
// Created by lenovo on 25/02/2023.
//

#include "kapal.h"


kapal::kapal(string name,int x, int y) {
    this->name=name;
    this->position_x=x;
    this->position_y=y;
    this->heath=1000;
}

void kapal::setX(int x) {
    this->position_x=x;
}
void kapal::setY(int y) {
    this->position_y=y;
}
void kapal::setHealth(int health) {
    this->heath=health;
}
int kapal::getX() {
    return this->position_x;
}
int kapal::getY() {
    return this->position_y;
}
int kapal::getHealth() {
    return this->heath;
}
string kapal::getName() {
    return this->name;
}
bool kapal::isDeath() {
    return this->heath<=0;
}