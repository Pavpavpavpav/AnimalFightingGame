#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <random>
#include <sstream>
#include <filesystem>
#include "filesystem.h"
#include "battlesequence.h"
#include "inventorysystem.h"

using namespace std;

void presskey() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl << "Press any key to continue...";
    cin.get();
}

void clearScreen() {
    cout << "\033[2J" << flush;
}

bool isNumber(string& str){
    istringstream isn(str);
    double test;

    return (isn >> test) && isn.eof();
}

void fileCheck(){
    const string gamesave = "GameSave.txt";
    const string animals = "Animals.txt";

    //Gamesave.txt checks
    if (filesystem::exists(gamesave)){
        for (int i = 2; i < 14; i++ ){
            string str = getData(1, i);
            bool test = isNumber(str);
            if (test == 0){
                cout << "Error: There is a letter in a number-only line in Gamesave.txt!" << endl;
                cout << "Detected in line: " << i << endl;
                cout << "Press any key to continue..." << endl;
                cin.get();
                exit(EXIT_FAILURE);
            }
        }

        int id1 = stoi(getData(1,3));
        int id2 = stoi(getData(1,5));
        int id3 = stoi(getData(1,7));
        int id4 = stoi(getData(1,9));

        if (id1 % 5 != 1 && id1 != 0 || id2 % 5 != 1 && id2 != 0 || id3 % 5 != 1 && id3 != 0 || id4 % 5 != 1 && id4 != 0){
            cout << "ERROR! One of the animal id's in GameSave.txt is incorrect!" << endl;
            cout << "Press any key to continue..." << endl;
            cin.get();
            exit(EXIT_FAILURE);
        }
    }
    else {
       createDatafile();
    }

    if(filesystem::exists(animals)){
        int FileSize = getFileSize();
        
        if (FileSize == -1){
            cout << "ERROR! Cannot open the Animals.txt file!" << endl;
            cout << "Press any key to continue..." << endl;
            cin.get();
            exit(EXIT_FAILURE);
        }
        else if (FileSize > 60){
            cout << "ERROR! Animals.txt is longer than expected (60 lines)!" << endl;
            cout << "Detected " << FileSize << " lines." << endl;
            cout << "Press any key to continue..." << endl;
            cin.get();
            exit(EXIT_FAILURE);
        }
        
        for (int i = 1; i < 61; i++){
            if (i % 5 != 1 && i % 5 != 3){
                string str = getData(2, i);
                bool isnum = isNumber(str);
                if (isnum == 0){
                    cout << "ERROR! There is a letter in an number-only line in Animals.txt!" << endl;
                    cout << "Detected in line: " << i << endl;
                    cout << "Press any key to continue..." << endl;
                    cin.get();
                    exit(EXIT_FAILURE);
                }
            }
            if (i % 5 == 3){
                string str = getData(2, i);
                if (str != "Light" && str != "Medium" && str != "Heavy" ){
                    cout << "ERROR! An animal was assigned an invalid class!" << endl;
                    cout << "Detected in line: " << i << endl;
                    cout << "Press any key to continue..." << endl;
                    cin.get();
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    else {
        cout << "ERROR! Animals.txt was not found!" << endl;
        cout << "Press any key to continue..." << endl;
        cin.get();
        exit(EXIT_FAILURE);
    }
}


void title(){
    cout << "#########################" << endl;
    cout << "| Animal Fighting Game  |" << endl;
    cout << "| version: beta         |" << endl;
    cout << "#########################" << endl << endl;


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
            presskey();
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
    
    presskey();

    return 0;

}

void selectAnimals(){
vector<string> ordinals = {"first", "second", "third", "fourth", "fifth"};

    cout << "List of all available animals:" << endl << endl;

    int i = 1;
    while(i < 61){
        cout << "ID " << i << ", Animal: " << getData(2,i);
        i++;
        cout << ", Max Exhaustion: " << getData(2,i);
        i++;
        cout << ", Class: " << getData(2,i);
        i++;
        cout << ", Min - Max Exhaustion Dealt: " << getData(2,i);
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
                string zero = "0";
                saveData(zero, saveto + 1);
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
        cout << "Animal: " << getData(2, stoi(getData(1,i))) << ", Max Exhaustion: " << getData(2, stoi(getData(1,i))+1) << ", Class: " << getData(2, stoi(getData(1,i))+2) << ", Min - Max Exhaustion Dealt: " << getData(2, stoi(getData(1,i))+3) << " - " << getData(2, stoi(getData(1,i))+4) << endl;
    }

    cout << endl << "Are you ready to go into a 'play-off' with your animals? ";
    
    presskey();
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

    cout << "Press any key to continue...";
    cin.get();
}


int main(){

    fileCheck();

    title();
    clearScreen();

    cout << "Would you like to start a new game or load a previous save? (1 for new game, 2 for load): ";
    int newgame;
    cin >> newgame;
    clearScreen();  

    if (newgame == 1){

        userRegister();
        clearScreen();

        selectAnimals();
        clearScreen();
        
        addItems();
        
    }    
    else {
        cout << "The following data was loaded from the save:" << endl;
        cout << "Name: " << getData(1, 1) << " Wins: " << getData(1, 2) << endl;
        cout << "Animal 1: " << getData(2, stoi(getData(1,3))) << " with " << getData(1, 4) << "/" << getData(2, stoi(getData(1,3))+1) << " exhaustion" << endl;
        cout << "Animal 2: " << getData(2, stoi(getData(1,5))) << " with " << getData(1, 6) << "/" << getData(2, stoi(getData(1,5))+1) << " exhaustion" << endl;
        cout << "Animal 3: " << getData(2, stoi(getData(1,7))) << " with " << getData(1, 8) << "/" << getData(2, stoi(getData(1,7))+1) << " exhaustion" << endl;
        cout << "Animal 4: " << getData(2, stoi(getData(1,9))) << " with " << getData(1, 10) << "/" << getData(2, stoi(getData(1,9))+1) << " exhaustion" << endl;
        cout << "Small Treats: " << getData(1, 11) << " Big Treats: " << getData(1, 12) << " Toys: " << getData(1, 13) << endl;
        cout << endl << "Is this correct? (Y/N): ";

        char answer;
        cin >> answer;

        if (answer == 'N'){
            cout << "Please delete the GameSave.txt file and restart the game to start a new game." << endl;
            presskey();
            return 0;
        }

    }

    while(true){
        clearScreen();
        cout << "INTERMISSION" << endl;
        cout << "You have: " << getData(1,2) << " wins!" << endl;
        cout << "Please select an option: " << endl;
        cout << "P - Go into a play-off with your animals" << endl;
        cout << "I - Open inventory" << endl;
        cout << "Q - Quit the game (Game is saved automatically)" << endl;

        char choice;
        cin >> choice;

        if (choice == 'P'){
            int win = gameround();

            if (win == 1){
                clearScreen();

                int wins = stoi(getData(1,2));
                wins++;
                string winsstr = to_string (wins);
                saveData(winsstr, 2);
                cout << "Congratulations on your win!" << endl;
                cout << "You now have: " << wins << " wins" << endl;
                cout << "Press any key to continue..." << endl;
                cin.get();
            }
            else {
                cout << "You have lost!" << endl;
                cout << "You had a win streak of: " << getData(1,2) << " wins" << endl;
                cout << "Delete ur save (GameSave.txt) to restart!" << endl;
                cout << "Press any key to continue..." << endl;
                cin.get();
                return 0;
            }
        }
        else if (choice == 'I'){
            openInventory(0);
        }
        else if (choice == 'Q'){
            cout << "Thank you for playing!";
            presskey();
            return 0;
        }
        else {
            cout << endl << "Please input a valid option!";
            presskey();
        }
    }

    
    
}
