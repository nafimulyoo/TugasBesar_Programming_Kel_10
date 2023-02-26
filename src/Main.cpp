#include "kapal.h"
#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void moveEnemy(Kapal &enemy, Map &map) {
    int direction = rand() % 4 + 1;
    switch (direction) {
        case 1:
            if (enemy.getY() + 1+8 < map.getSize()) {
                if (map.getObj(enemy.getX(), enemy.getY() + 1) == " ") {
                    map.deleteObj(enemy);
                    enemy.move("up");
                    map.setObj(enemy);
                }
            }
            break;
        case 2:
            if (enemy.getY() - 1 > 0) {
                if (map.getObj(enemy.getX(), enemy.getY() - 1) == " ") {
                    map.deleteObj(enemy);
                    enemy.move("down");
                    map.setObj(enemy);
                }
            }
            break;
        case 3:
            if (enemy.getX() - 1 > 0) {
                if (map.getObj(enemy.getX() - 1, enemy.getY()) == " ") {
                    map.deleteObj(enemy);
                    enemy.move("left");
                    map.setObj(enemy);
                }
            }
            break;
        case 4:
            if (enemy.getX() + 1 < map.getSize()) {
                if (map.getObj(enemy.getX() + 1, enemy.getY()) == " ") {
                    map.deleteObj(enemy);
                    enemy.move("right");
                    map.setObj(enemy);
                }
            }
            break;
    }
}

void movePlayer(Kapal &player, Map &map) {
    int direction;
    cout << "Choose your direction: " << endl;
    cout << "1. Up" << endl;
    cout << "2. Down" << endl;
    cout << "3. Left" << endl;
    cout << "4. Right" << endl;
    cin >> direction;

    switch (direction) {
        case 1:
            if (player.getY() + 1 < map.getSize()) {
                if (map.getObj(player.getX(), player.getY() + 1) == " ") {
                    map.deleteObj(player);
                    player.move("up");
                    map.setObj(player);
                } else {
                    cout << "There is enemy ship" << endl;
                }
            } else {
                cout << "Out of range" << endl;
            }
            break;
        case 2:
            if (player.getY() - 1 > 0) {
                if (map.getObj(player.getX(), player.getY() - 1) == " ") {
                    map.deleteObj(player);
                    player.move("down");
                    map.setObj(player);
                } else {
                    cout << "There is enemy ship" << endl;
                }
            } else {
                cout << "Out of range" << endl;
            }
            break;
        case 3:
            if (player.getX() - 1 > 0) {
                if (map.getObj(player.getX() - 1, player.getY()) == " ") {
                    map.deleteObj(player);
                    player.move("left");
                    map.setObj(player);
                } else {
                    cout << "There is enemy ship" << endl;
                }
            } else {
                cout << "Out of range" << endl;
            }
            break;
        case 4:
            if (player.getX() + 1 < map.getSize()) {
                if (map.getObj(player.getX() + 1, player.getY()) == " ") {
                    map.deleteObj(player);
                    player.move("right");
                    map.setObj(player);
                } else {
                    cout << "There is enemy ship" << endl;
                }
            } else {
                cout << "Out of range" << endl;
            }
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }
}

int main(){
    srand(time(NULL));

    int mapSize = 16;

    Map Map(mapSize);
    Map.setMap();

    Kapal kapalPlayer("P");
    Kapal kapalMusuh("M");

    kapalPlayer.setX(8);
    kapalPlayer.setY(8);

    do {
        kapalMusuh.setX(rand() % 9+1);
        kapalMusuh.setY(rand() % 9+1);
    } while (kapalMusuh.getX()==kapalPlayer.getX() &&
    kapalMusuh.getY()==kapalPlayer.getY());


    int choice = 0;
    int enemyDefeated = 0;
    cout<<"posisi kita ("<<kapalPlayer.getX()-8<<","<<kapalPlayer.getY()-8<<")"<<endl;
    cout<<"posisi musuh ("<<kapalMusuh.getX()<<","<<kapalMusuh.getY()<<")"<<endl;
    Map.setObj(kapalPlayer);
    Map.setObj(kapalMusuh);

    while (kapalPlayer.getHealth() > 0) {
        system("cls");
        Map.showMap();
        cout << "Player Health: " << kapalPlayer.getHealth() << endl;
        cout << "kapalMusuh Health: " << kapalMusuh.getHealth() << endl;
        cout << "kapalMusuh Defeated: " << enemyDefeated << endl;
        cout << "Choose your action: " << endl;
        cout << "1. Move" << endl;
        cout << "2. Attack" << endl;
        cout << "3. Do Nothing" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                movePlayer(kapalPlayer, Map);
                break;
            }

            case 2: {
                kapalPlayer.attack(kapalMusuh);
            }
            case 3:
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        if (kapalMusuh.getHealth() <= 0) {
            cout << "Enemy ship destroyed!" << endl;
            enemyDefeated++;

            do {
                kapalMusuh.setX(rand() % 9+1);
                kapalMusuh.setY(rand() % 9+1);
            } while (kapalMusuh.getX()==kapalPlayer.getX() && kapalMusuh.getY()==kapalPlayer.getY());

            kapalMusuh.setHealth(100);
            Map.deleteObj(kapalMusuh);
            Map.setObj(kapalMusuh);
            break;
        } else {
            // if player is not in enemy shoot range, move enemy, else pick random between attack and move. use calculateDistance function
            if (kapalMusuh.calculateRange(kapalPlayer) < kapalMusuh.getMaxShootRange()) {
                int random = rand() % 2;
                if (random == 0) {
                    kapalMusuh.attack(kapalPlayer);
                } else {
                    moveEnemy(kapalMusuh, Map);
                }

            } else {
                moveEnemy(kapalMusuh, Map);
            }
        }
        cout<<"posisi kita ("<<kapalPlayer.getX()-8<<","<<kapalPlayer.getY()-8<<")"<<endl;
        cout<<"posisi musuh ("<<kapalMusuh.getX()<<","<<kapalMusuh.getY()<<")"<<endl;
    }

    cout << "Game Over" << endl;
    cout << "You defeated " << enemyDefeated << " enemy ships" << endl;

//    Map anu(16);
//    anu.setMap();
//    anu.showMap();

    return 0;
}