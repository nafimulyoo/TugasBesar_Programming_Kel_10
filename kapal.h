//
// Created by lenovo on 25/02/2023.
//

#ifndef TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H
#define TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H

#include <iostream>

using namespace std;

class kapal {
private:
    string name;
    int heath;
    int position_x;
    int position_y;
public:
    kapal(string name,int x,int y);

    void setX(int x);
    void setY(int y);
    void setHealth(int health);

    int getX();
    int getY();
    string getName();
    int getHealth();
};


#endif //TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H
