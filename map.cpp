//
// Created by lenovo on 25/02/2023.
//

#include "map.h"

map::map(int size) {
    this->size=size;

    this->objMap = new string*[this->size+2];
}

void map::setObj(kapal x) {
    this->objMap[x.getX()][x.getY()]=
}