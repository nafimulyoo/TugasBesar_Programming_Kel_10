//
// Created by lenovo on 25/02/2023.
//

#ifndef TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H
#define TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H


class kapal {
private:
    int heath;
    int position_x;
    int position_y;
public:
    kapal(int x,int y);

    void setX(int x);
    void setY(int y);
    void setHealth(int health);

    int getX();
    int getY();
    int getHealth();
};


#endif //TUGASBESAR_PROGRAMMING_KEL_8_KAPAL_H
