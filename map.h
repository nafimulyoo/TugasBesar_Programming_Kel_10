//
// Created by lenovo on 25/02/2023.
//

#ifndef TUGASBESAR_PROGRAMMING_KEL_8_MAP_H
#define TUGASBESAR_PROGRAMMING_KEL_8_MAP_H


#include "kapal.h"
#include <iostream>

using namespace std;

class map {
private:
    int size;
    string** objMap;
public:
    map(int size);

    int getSize();
    void setObj(kapal x);
    void showMap();

};


#endif //TUGASBESAR_PROGRAMMING_KEL_8_MAP_H
