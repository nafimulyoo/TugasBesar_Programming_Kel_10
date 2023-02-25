//
// Created by lenovo on 25/02/2023.
//

#ifndef TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H
#define TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H
#include <cstdlib>
#include <string>
using namespace std;

class Kapal {
private:
    int health;
    int position_x;
    int position_y;
    int damage;
    int max_shoot_range;

public:
    Kapal() {
        this->health=100;
        this->position_x=0;
        this->position_y=0;
        this->damage=10;
        this->max_shoot_range=4;
    }

    void setX(int x);
    void setY(int y);
    void setHealth(int health);

    void move(string direction);
    void attack(Kapal &other);
    int calculateRange(Kapal other);
    void decreaseHealth(int damage);


    int getX();
    int getY();
    int getHealth();
    int getDamage();
    int getMaxShootRange();
};


#endif //TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H
