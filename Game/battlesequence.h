#pragma once


#include <string>
#include <vector>
#include <random>

class Opponent {
private:
    std::string name;

    int numberofAnimals;
    std::vector<int> animalIDs;
    std::vector<int> animalExaustion;
public:
    Opponent(int numAnimals);

    std::string getName();
    int getNumberofAnimals();
    int getAnimalID(int animalIndex);
    int getExaustion(int animalIndex);
    void changeExaustion(int animalIndex, int change);
    bool isAnimalExausted(int animalIndex);
};

int gameround();

