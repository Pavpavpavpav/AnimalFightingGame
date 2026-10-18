#include <iostream>
#include <string>
#include "filesystem.h"
#include "battlesequence.h"
#include "inventorysystem.h"
#include "main.h"

using namespace std;

void UseItem(int itemID) {
    string itemselected;
    if (itemID == 1) {
        itemselected = "small treat";
    } else if (itemID == 2) {
        itemselected = "big treat";
    } else if (itemID == 3) {
        itemselected = "toy";
    }

    while (true){
        clearScreen();
        cout << "Please choose the animal you would like to use the " << itemselected << " (" << getData(1, 10 + itemID) << " remaining): " << endl;
        cout << "1 - " << getData(2, stoi(getData(1,3))) << " with " << getData(1,4) << "/" << getData(2,stoi(getData(1,3)) + 1) << " exaustion" <<endl;
        cout << "2 - " << getData(2, stoi(getData(1,5))) << " with " << getData(1,6) << "/" << getData(2,stoi(getData(1,5)) + 1) << " exaustion" << endl;
        cout << "3 - " << getData(2, stoi(getData(1,7))) << " with " << getData(1,8) << "/" << getData(2,stoi(getData(1,7)) + 1) << " exaustion" << endl;
        cout << "4 - " << getData(2, stoi(getData(1,9))) << " with " << getData(1,10) << "/" << getData(2,stoi(getData(1,9)) + 1) << " exaustion" << endl;
        cout << "Q - Quit" << endl;
        cout << "Input 1 - 4 or Q: ";

        char choice;
        cin >> choice;
        cout << endl;

        if (choice == '1' || choice == '2' || choice == '3' || choice == '4')  {
            int animalIndex = choice - '0';
            int currentExaustion = stoi(getData(1, 2 * animalIndex + 2));
            int maxExaustion = stoi(getData(2, stoi(getData(1, 2 * animalIndex + 1)) + 1));
            if (itemID < 3) {
                if (currentExaustion >= maxExaustion){
                    cout << "This animal is fully exausted, you cannot use a treat on it." << endl;
                    presskey();
                }
                else if (itemID == 1) {
                    currentExaustion -= 50;

                    if (currentExaustion < 0) {
                        currentExaustion = 0;
                    }

                    string currentExaustionStr = to_string(currentExaustion);
                    saveData(currentExaustionStr, 2 * animalIndex + 2);
                    
                    int smallTreats = stoi(getData(1, 11)) - 1;
                    string smallTreatsStr = to_string(smallTreats);
                    saveData(smallTreatsStr, 11);

                    cout << "You used a small treat on " << getData(2, stoi(getData(1, 2 * animalIndex + 1))) << "!" << endl;
                    cout << "It now has " << currentExaustion << "/" << maxExaustion << " exaustion." << endl;
                    cout << "You have " << smallTreats << " small treats left." << endl;

                    presskey();
                }
                else if (itemID == 2) {
                    currentExaustion -= 150;

                    if (currentExaustion < 0) {
                        currentExaustion = 0;
                    }

                    string currentExaustionStr = to_string(currentExaustion);
                    saveData(currentExaustionStr, 2 * animalIndex + 2);
                    
                    int bigTreats = stoi(getData(1, 12)) - 1;
                    string bigTreatsStr = to_string(bigTreats);
                    saveData(bigTreatsStr, 12);

                    cout << "You used a big treat on " << getData(2, stoi(getData(1, 2 * animalIndex + 1))) << "!" << endl;
                    cout << "It now has " << currentExaustion << "/" << maxExaustion << " exaustion." << endl;
                    cout << "You have " << bigTreats << " big treats left." << endl;
                    
                    presskey();
                }
            }
            else if (itemID == 3) {
                currentExaustion = 0;
                string currentExaustionStr = to_string(currentExaustion);
                saveData(currentExaustionStr, 2 * animalIndex + 2);

                int toys = stoi(getData(1, 13)) - 1;
                string toysstr = to_string(toys);
                saveData(toysstr, 13);

                cout << "You used a toy on " << getData(2, stoi(getData(1, 2 * animalIndex + 1))) << "!" << endl;
                cout << "It now has " << currentExaustion << "/" << maxExaustion << " exaustion." << endl;
                cout << "You have " << toys << " toys left." << endl;
                    
                presskey();
            }

        }
        else if (choice = 'Q'){
            break;
        }
        else {
            cout << "Invalid input. " << endl;
            presskey();
        }

    }
}

void openInventory() {
    while(true){
        clearScreen();
        cout << "INVENTORY" << endl;
        cout << "1. Small Treats: " << getData(1, 11) << endl;
        cout << "2. Big Treats: " << getData(1, 12) << endl;
        cout << "3. Toys: " << getData(1, 13) << endl;
        cout << "U - Use item, Q - Quit inventory" << endl;

        char choice;
        cin >> choice;

        if (choice == 'U'){
            int itemChoice;
            cout << endl << "Select an item to use (1-3): ";
            cin >> itemChoice;

            if (itemChoice >= 1 && itemChoice <= 3 && stoi(getData(1, 10 + itemChoice)) > 0) {
                UseItem(itemChoice);
            } else if (itemChoice >= 1 && itemChoice <= 3 && stoi(getData(1, 10 + itemChoice)) <= 0) {
                cout << endl << "Invalid item choice. You do not posses any of that item.";
                presskey();
            }
            else {
                cout << "Invalid item choice.";
                presskey();
            }
        }
        else if (choice == 'Q'){
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            presskey();
        }
    }
}
