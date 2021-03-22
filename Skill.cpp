#include "Skill.hpp"

using namespace std;

Skill::Skill() : skillName("Skill"), basePower(0), masteryLevel(0)
{
    vector<string> Elements;
}

Skill::Skill(string name, int power, int mastery, vector<string> Elmts) : skillName(name),
                                                                          basePower(power),
                                                                          masteryLevel(mastery),
                                                                          Elements(Elmts) {}

Skill::~Skill()
{
    // Output Message
    cout << this->skillName << " is deleted successfully." << endl;
}

bool Skill::isSkillLearnable(string engimonElmt)
{
    // STD::find
    return (find(this->Elements.begin(), this->Elements.end(), engimonElmt) != Elements.end());
}

void Skill::masteryLevelUp(int bpIncrease)
{
    // Increase mastery level and add BP
    this->masteryLevel++;
    this->basePower += bpIncrease;
}

void Skill::skillInfo()
{
    // Output attributes info
    cout << "Skill Name         : " << this->skillName << endl;
    cout << "Base Power         : " << this->basePower << endl;
    cout << "Master Level       : " << this->masteryLevel << endl;
    cout << "Available Elements : [";

    // Iterate with index
    for (int i = 0; i < Elements.size(); i++)
    {
        cout << Elements[i];
        if (i != Elements.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

string Skill::getSkillName()
{
    return this->skillName;
}