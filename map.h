//
// Created by lenovo on 25/02/2023.
//

#ifndef TUGASBESAR_PROGRAMMING_KEL_8_MAP_H
#define TUGASBESAR_PROGRAMMING_KEL_8_MAP_H


#include "kapal.h"
#include <iostream>

using namespace std;

class Map {
private:
    int size;
    string** objMap;
public:
    Map(int size);

    int getSize();
    string getObj(int x, int y);
    void setObj(Kapal x);
    void deleteObj(Kapal x);
    void setMap();
    void showMap();

};


#endif //TUGASBESAR_PROGRAMMING_KEL_8_MAP_H
