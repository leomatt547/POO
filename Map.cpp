#include "Map.hpp"
#include <iostream>
#include <vector>
using namespace std;

Map::Map(){
    xmax = 10;
    ymax = 10;
    setCapital = 5;
    dimensiWater = 5;
    for (int i = 0; i < xmax; i++){
        peta.push_back(vector<Position>());
        for(int j = 0; j < ymax; j++){
            peta.at(i).push_back(Position(i,j));
        }
    }
}

Map::~Map(){
    //
}

void Map::printMap(){
    for (int i = 0; i < xmax; i++){
        for(int j = 0; j < ymax; j++){
            if(i > xmax-dimensiWater || j < ymax-dimensiWater){
                cout << "- ";
            }else if (peta.at(i).at(j).getisPlayer()){
                cout << "P ";
            }else if (peta.at(i).at(j).getisActiveEngimon()){
                cout << "X ";
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Fire"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "F ";
                }else{
                    cout << "f ";
                }
            }
            else if (getCurrElement(peta.at(i).at(j)).at(0)=="Water"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "W ";
                }else{
                    cout << "w ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Ice"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "I ";
                }else{
                    cout << "i ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Ground"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "G ";
                }else{
                    cout << "g ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Electric"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "E ";
                }else{
                    cout << "e ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Fire" 
                && getCurrElement(peta.at(i).at(j)).at(0)=="Electric"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "L ";
                }else{
                    cout << "l ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Water" 
                && getCurrElement(peta.at(i).at(j)).at(0)=="Ice"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "S ";
                }else{
                    cout << "s ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Water" 
                && getCurrElement(peta.at(i).at(j)).at(0)=="Ground"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "N ";
                }else{
                    cout << "n ";
                }
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

vector<string> Map::getCurrElement(Position k){
    return k.getEngimon().getElement();
}

bool Map::isAboveLevel(Position k){
    return (k.getEngimon().getLevel() >= setCapital);
}

void Map::movePlayerUp(){
    if((player_position.getYCoordinate())-1>=0){
        int a = player_position.getXCoordinate();
        int b = player_position.getYCoordinate();
        peta.at(a).at(b-1) = player_position; 
        peta.at(a).at(b) = Position(a,b);
    }else{
        throw "Invalid move Player Up";
    }
}

void Map::movePlayerLeft(){
    if((player_position.getXCoordinate())-1>=0){
        int a = player_position.getXCoordinate();
        int b = player_position.getYCoordinate();
        peta.at(a-1).at(b) = player_position; 
        peta.at(a).at(b) = Position(a,b);
    }else{
        throw "Invalid move Player Left";
    }
}

void Map::movePlayerRight(){
    if((player_position.getXCoordinate())+1<=xmax){
        int a = player_position.getXCoordinate();
        int b = player_position.getYCoordinate();
        peta.at(a+1).at(b) = player_position; 
        peta.at(a).at(b) = Position(a,b);
    }else{
        throw "Invalid move Player Left";
    }
}

void Map::movePlayerDown(){
    if((player_position.getYCoordinate())+1 <= ymax){
        int a = player_position.getXCoordinate();
        int b = player_position.getYCoordinate();
        peta.at(a).at(b+1) = player_position; 
        peta.at(a).at(b) = Position(a,b);
    }else{
        throw "Invalid move Player Down";
    }
}

int main(int argc, char const *argv[])
{
    Map m = Map();
    m.printMap();
    return 0;
}
