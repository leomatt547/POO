#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Engimon.hpp"
#include "Position.hpp"

using namespace std;

class Map
{
private:
    int xmax;
    int ymax;
    int maxEngimonLiar;
    vector<vector<char>> peta;
    vector<pair<Position, Engimon>> engimonLiar;
    int setCapital; /* X >= setCapital (Huruf Besar), X < setCapital (Huruf Kecil)*/
    int dimensiWater;
    Position playerPosition;
    Position activeEngimonPositon;

public:
    Map();
    ~Map();
    void printMap();
    int getmaxEngimonLiar();
    Position getplayerPosition();
    vector<pair<Position, Engimon>> getengimonLiar();
    int getplayerPositionX();
    int getplayerPositionY();
    int getxmax();
    int getymax();
    void setplayerPosition(int _x, int _y);
    Position getactiveEngimonPosition();
    int getactiveEngimonPositionX();
    int getactiveEngimonPositionY();
    void setactiveEngimonPosition(int _x, int _y);
    void addEngimonLiar();
    /*void moveAllEngimonLiar();
    void moveEngimonLiar(Engimon eng);*/
};
#endif
