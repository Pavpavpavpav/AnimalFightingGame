#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <random>
#include "filesystem.h"


using namespace std;

void clearScreen() {
    cout << "\033[2J" << flush;
}

void title(){
    cout << "#########################" << endl;
    cout << "| Animal Fighting Game  |" << endl;
    cout << "| version: beta         |" << endl;
    cout << "#########################" << endl << endl << endl << endl;


    cout << "Have you read the README document yet? (Y/N): ";
    char answer;
    cin >> answer;
    cout << endl;

    while (0<1){
        if (answer == 'Y'){
            break;
        }
        else if (answer == 'N'){
            cout << "It is recommended you do so!" << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press any key to continue...";

            cin.get();
            break;
        }
        else {
            cout << "Please input a either a Y for yes, or a N for no:";
            cin >> answer;
            cout << endl;
        }
    }
}

int userRegister(){
    
    string username;

    cout << "Please input your name: ";
    cin >> username; 
    saveData(username, 1);

    cout << "Welcome " << username << ", are you ready to select your animals?" << endl;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press any key to continue...";

            cin.get();

    return 0;

}

void selectAnimals(){
vector<string> ordinals = {"first", "second", "third", "fourth", "fifth"};

    cout << "List of all available animals:" << endl << endl;

    int i = 1;
    while(i < 61){
        cout << "ID " << i << ", Animal: " << getData(2,i);
        i++;
        cout << ", Max Exaustion: " << getData(2,i);
        i++;
        cout << ", Class: " << getData(2,i);
        i++;
        cout << ", Min - Max Exaustion Dealt: " << getData(2,i);
        i++;
        cout << " - " << getData(2,i) << endl;
        i++;
    }

    cout << endl << "Scroll up if needed to see the full list of 12 Animals" << endl;
    
    int d = 0;
    int id;
    int saveto = 3;
    char choice;

    for (d = 0; d < 4;){
        cout << "Please input the id of your " << ordinals[d] << " selected animal (doesn't need to be unique): ";
        cin >> id;
        if (id % 5 == 1){
            cout << endl << "You have selected " << getData(2,id) << " as your animal, is that correct? (Y/N): ";
            cin >> choice;

            if (choice == 'Y'){
                string idstr = to_string(id);
                saveData(idstr, saveto);
                string animalmaxexaustion = getData(2, id+1);
                saveData(animalmaxexaustion, saveto+1);
                saveto += 2;
                d++;
            }
        }
        else {
            cout << endl << "Please input a valid ID from the animal list (leftmost number)!";
        }

        cout << endl;
    }


    clearScreen();

    cout << "Meet your animals!: " << endl;
    for (int i = 3; i < 11; i+=2){
        cout << "Animal: " << getData(2, stoi(getData(1,i))) << ", Max Exaustion: " << getData(1,i+1) << ", Class: " << getData(2, stoi(getData(1,i))+2) << ", Min - Max Exaustion Dealt: " << getData(2, stoi(getData(1,i))+3) << " - " << getData(2, stoi(getData(1,i))+4) << endl;
    }

    cout << endl << "Are you ready to go into a 'play-off' with your animals? ";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Press any key to continue...";

    cin.get();
}

void addItems(){
    random_device rd;
    mt19937 gen(rd());

    discrete_distribution<int> dropchance({.50, .40, .10});
    int addedstreats = dropchance(gen);
    int totalsmalltreats = stoi(getData(1, 11)) + addedstreats;
    int addedbigtreats = dropchance(gen);
    int totalbigtreats = stoi(getData(1, 12)) + addedbigtreats;

    discrete_distribution<int> dropchance2({.70, .30});
    int addedtoys = dropchance2(gen);
    int totaltoys = stoi(getData(1, 13)) + addedtoys;

    cout << "You have recieved " << addedstreats << " small treats, you now have a total of " << totalsmalltreats << " small treats!" << endl;
    string totalsmalltreatsstr = to_string(totalsmalltreats);
    saveData(totalsmalltreatsstr, 11);
    cout << "You have recieved " << addedbigtreats << " big treats, you now have a total of " << totalbigtreats << " big treats!" << endl;
    string totalbigtreatsstr = to_string(totalbigtreats);
    saveData(totalbigtreatsstr, 12);
    cout << "You have recieved " << addedtoys << " toys, you now have a total of " << totaltoys << " toys!" << endl;
    string totaltoysstr = to_string(totaltoys);
    saveData(totaltoysstr, 13);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Press any key to continue...";

    cin.get();
}


int main(){
    int newgame = 1; //change with load function

    if (newgame == 1){
        createDatafile();

        title();
        clearScreen();

        userRegister();
        clearScreen();

        selectAnimals();
        clearScreen();
        
        addItems();
        clearScreen();

        //TODO
        //while loop to repeat the game untill exit with options to use items, save and to start fight
        //fight system
        //inventory system with usable items before and during fights
        //Names for the AI oppoenents and unique animal combos (pre set names with certain animals, possible new document that is read only (add option 3 to load that using getData()))

    }
    else {

    }
    
}
