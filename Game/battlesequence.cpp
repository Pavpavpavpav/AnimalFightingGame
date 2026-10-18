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
    return animalIDs[animalIndex - 1];
}

int Opponent::getExaustion(int animalIndex){
    return animalExaustion[animalIndex - 1];
}

void Opponent::changeExaustion(int animalIndex, int to){
    animalExaustion[animalIndex - 1] = to;
}

bool Opponent::isAnimalExausted(int animalIndex){
    int maxExhaustion = stoi(getData(2, animalIDs[animalIndex - 1] + 1));
    return animalExaustion[animalIndex - 1] >= maxExhaustion;
}

bool isExausted(int id){
    int exaustion = stoi(getData(1, 2 * id + 2));
    int animalid = stoi(getData(1, 2 * id + 1));
    int maxexaustion = stoi(getData(2, animalid + 1));

    if (exaustion >= maxexaustion){
        return true;
    }
    else {
        return false;
    }
}

int gameround(){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> animals(2, 4);
    Opponent opponent(animals(gen)); 

    string playername = getData(1,1);
    int curranimal;
    int curranimalopp = 1;

    if (isExausted(1) == 0){
        curranimal = 1;
    }
    else if (isExausted(2) == 0){
        curranimal = 2;
    }
    else if (isExausted(3) == 0){
        curranimal = 3;
    }
    else if (isExausted(4) == 0){
        curranimal = 4;
    }
    else {
        clearScreen();
        cout << "You cannot battle without any non-exhausted animals! Please create a new save!" << endl;
        presskey();
        exit(EXIT_SUCCESS);
    }

    bool usedturn = 0;

    while(true){
        string playername = getData(1, 1);
        int playeranimalid = stoi(getData(1, 2 * curranimal + 1));
        int exaustionp = stoi(getData(1,2 * curranimal + 2));
        string playeranimalname = getData(2, playeranimalid);
        int maxexaustionp = stoi(getData(2, playeranimalid + 1));
        string animalclassp = getData(2, playeranimalid + 2);

        string oppname = opponent.getName();
        int oppanimalid = opponent.getAnimalID(curranimalopp);
        string oppanimalname = getData(2, oppanimalid);
        int exaustionopp = opponent.getExaustion(curranimalopp);
        int maxexaustionopp = stoi(getData(2, oppanimalid + 1));
        string animalclassopp = getData(2, oppanimalid + 2);
        bool oppexausted = 0;

        clearScreen();

        if (usedturn == 0){
            cout << "A turn did not pass. (placeholder)" << endl;
            presskey();
        }
        else {
            cout << "A turn has passed. (placeholder)" << endl;
            presskey();
        }

        clearScreen();

        cout << "PLAY-OFF" << endl;
        cout << endl;
        cout << playername << endl;
        cout << playeranimalname << " with " << exaustionp << "/" << maxexaustionp << " exhaustion" << endl;
        cout << "versus" << endl;
        cout << oppname << endl;
        cout << oppanimalname << " with " << exaustionopp << "/" << maxexaustionopp << " exhaustion" << endl;
        cout << "A - play, B - Inventory, C - Switch Animal" << endl;

        char choice;
        cin >> choice;

        usedturn = 0;
        clearScreen();

        if (choice == 'A'){
            int plminhit = stoi(getData(2, playeranimalid + 3));
            int plmaxhit = stoi(getData(2, playeranimalid + 4));

            uniform_int_distribution<int> hitfor(plminhit, plmaxhit);
            int hit = hitfor(gen);

            if (animalclassp == "Light" && animalclassopp == "Heavy" || animalclassp == "Medium" && animalclassopp == "Light" || animalclassp == "Heavy" && animalclassopp == "Medium"){
                hit = hit * 1.25;
                cout << "The " << animalclassp << " " << playeranimalname << " exhausts the " << animalclassopp << " " << oppanimalname << " more!" << endl;
            }
            else if (animalclassp == "Light" && animalclassopp == "Medium" || animalclassp == "Medium" && animalclassopp == "Heavy" || animalclassp == "Heavy" && animalclassopp == "Light"){
                hit = hit * .75;
                cout << "The " << animalclassp << " " << playeranimalname << " exhausts the " << animalclassopp << " " << oppanimalname << " less!" << endl;
            }
            exaustionopp += hit;  

            if (exaustionopp > maxexaustionopp){
                cout << "Your " << playeranimalname << " dealt " << hit << " exhaustion to the opponent's " << oppanimalname << endl;
                cout << "The opponent's " << oppanimalname << " has been exhausted." << endl;

                opponent.changeExaustion(curranimalopp, maxexaustionopp);
                oppexausted = 1;
            }
            else {
                cout << "Your " << playeranimalname << " dealt " << hit << " exhaustion to the opponent's " << oppanimalname << endl;
                cout << "The opponent's " << oppanimalname << " now has " << exaustionopp << " exhaustion" << endl;
                opponent.changeExaustion(curranimalopp, exaustionopp);
            }

            presskey();
            usedturn = 1;
        }
        else if (choice == 'B'){
            bool itemused = openInventory(1);
            if (itemused == 1){
                usedturn = 1;
            }
        }
        else if (choice == 'C'){
            clearScreen();

            cout << "Select the animal you want to switch to: " << endl;
            cout << "1. - " << getData(2, stoi(getData(1,3))) << " with " << getData(1,4) << "/" << getData(2,stoi(getData(1,3))+1) << " exhaustion" << endl;
            cout << "2. - " << getData(2, stoi(getData(1,5))) << " with " << getData(1,6) << "/" << getData(2,stoi(getData(1,5))+1) << " exhaustion" << endl;
            cout << "3. - " << getData(2, stoi(getData(1,7))) << " with " << getData(1,8) << "/" << getData(2,stoi(getData(1,7))+1) << " exhaustion" << endl;
            cout << "4. - " << getData(2, stoi(getData(1,9))) << " with " << getData(1,10) << "/" << getData(2,stoi(getData(1,9))+1) << " exhaustion" << endl;
            
            int selection;
            cin >> selection;
            
            int selectedid = stoi(getData(1, 2*selection +1));
            int selectedidexh = stoi(getData(1, 2*selection + 2));
            int selectedidmexh = stoi(getData(2, selectedid + 1));

            clearScreen();
            if (selectedidexh >= selectedidmexh){
                cout << "You cannot switch to a fully exhausted animal!" << endl;
                presskey();
            }
            else if (selection == curranimal){
                cout << "You have already selected this animal!" << endl;
                presskey();
            }
            else {
                cout << "You have switched to your " << getData(2, selectedid) << "!" << endl;
                cout << selectedidexh << " " << selectedidmexh;
                curranimal = selection;
                presskey();
                usedturn = 1;

            }
            
        }
        

    }

}