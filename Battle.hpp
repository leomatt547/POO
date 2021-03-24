#include <string>
#include <iostream>
#include <vector>
#include "Engimon.hpp"

using namespace std;

class Battle {
    private :
        Engimon engimonPlayer;
        Engimon engimonWild;
        int levelEngimonPlayer; // Level Engimon Player 1
        int levelEngimonWild; // Level Engimon Player 2
        float multiplierEngimonPlayer; // Element Advantage Engimon Player 1
        float multiplierEngimonWild; // Element Advantage Engimon Player 2
        int skillPowerPlayer; // Total skill base power Engimon Player 1
        int skillPowerWild; // Total skill base power Engimon Player 2
        float totalPowerPlayer;
        float totalPowerWild;
        string winner;
        string loser;
        
    public :
        // Constructor & Destructor
        Battle();
        Battle(Engimon engimonPlayer, Engimon engimonWild);
        ~Battle();

        // Get Class Attribute
        int getlevelEngimonPlayer();
        int getlevelEngimonWild();
        int getMultiplierEngimonPlayer();
        int getMultiplierEngimonWild();
        int getskillPowerPlayer();
        int getskillPowerWild();
        float getTotalPowerPlayer();
        float getTotalPowerWild();

        // Set Class Attribute
        void setMultiplierEngimon();
        void setSkillPower();
        void setTotalPower();
        void setElement();

        // Fungsi dan Prosedur
        float checkMultiplier(string elemen1, string elemen2);
        void showTotalPower();
        void doBattle();
};