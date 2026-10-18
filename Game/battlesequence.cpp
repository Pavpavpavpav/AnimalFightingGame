#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "battlesequence.h"
#include "filesystem.h"
#include "inventorysystem.h"
#include "main.h"

using namespace std;

Opponent::Opponent(int numAnimals) {
    random_device rd;
    mt19937 gen(rd());

    vector<string> names = {"Anastasia", "Balthazar", "Cassandra", "Dmitri", "Evangeline", "Ferdinand", "Gwendolyn", "Hector", "Isadora", "Jasper"};
    uniform_int_distribution<int> randnamenum(0, names.size() - 1);
    name = names[randnamenum(gen)];

    for (int i = 0; i < numAnimals; i++) {
        uniform_int_distribution<int> randanimalid(0, 11);
        animalIDs.push_back(randanimalid(gen) * 5 + 1);
        animalExaustion.push_back(0);
    }

    numberofAnimals = numAnimals;

}

string Opponent::getName() {
    return name;
}

int Opponent::getNumberofAnimals() {
    return numberofAnimals;
}

int Opponent::getAnimalID(int animalIndex){
    return animalIDs[animalIndex];
}

int Opponent::getExaustion(int animalIndex){
    return animalExaustion[animalIndex];
}

void Opponent::changeExaustion(int animalIndex, int change){
    int maxExhaustion = stoi(getData(2, animalIDs[animalIndex] + 1));
    if (animalExaustion[animalIndex] + change < maxExhaustion) {
        animalExaustion[animalIndex] += change;
    }
    else {
        animalExaustion[animalIndex] = maxExhaustion;
    }
}

bool Opponent::isAnimalExausted(int animalIndex){
    int maxExhaustion = stoi(getData(2, animalIDs[animalIndex] + 1));
    return animalExaustion[animalIndex] >= maxExhaustion;
}



int gameround(){
    random_device rd;
    mt19937 gen(rd());


    return 0;
}