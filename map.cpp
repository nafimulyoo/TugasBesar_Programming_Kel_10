//
// Created by lenovo on 25/02/2023.
//

#include "map.h"

map::map(int size) {
    this->size=size;

    this->objMap = new string*[this->size+2];
}

void map::setObj(kapal x) {
    this->objMap[x.getX()+1][x.getY()+1]=x.getName();
}
void map::deleteObj(kapal x) {
    this->objMap[x.getX()+1][x.getY()+1]=" ";
}
void map::setMap() {
    for(int i=0;i<this->size+2;i++){
        for(int j=0;j< this->size+2;j++){
            if(i==0||j==0||i== this->size+1||j== this->size+1) {
                this->objMap[i][j]="#";
            } else{
                this->objMap[i][j]=" ";
            }
        }
    }
}
void map::showMap() {
    for(int i=0;i<this->size+2;i++){
        for(int j=0;j< this->size+2;j++){
            cout<< this->objMap[i][j];
        }
        cout<<endl;
    }
}