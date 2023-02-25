//
// Created by lenovo on 25/02/2023.
//

#include "map.h"

Map::Map(int size) {
    this->size=size;

    this->objMap = new string*[this->size+2];

}
Map::~Map() {
    delete this->objMap;
}

void Map::setObj(Kapal x) {
    this->objMap[x.getX()+1][x.getY()+1]=x.getName();
}
void Map::deleteObj(Kapal x) {
    this->objMap[x.getX()+1][x.getY()+1]=" ";
}
void Map::setMap() {
    for(int i=0;i<this->size+2;i++){
        this->objMap[i] = new string[this->size+2];
        for(int j=0;j< this->size+2;j++){
            if(i==0||j==0||i== this->size+1||j== this->size+1) {
                this->objMap[i][j]="#";
            } else{
                this->objMap[i][j]=" ";
            }
        }
    }
}

string Map::getObj(int x, int y) {
    return this->objMap[x][y];
}

void Map::showMap() {
    for(int i=0;i<this->size+2;i++){
        for(int j=0;j< this->size+2;j++){
            cout<< this->objMap[j][i];
        }
        cout<<endl;
    }
}
int Map::getSize() {
    return this->size;
}