#include <iostream>
#include <string>
#include <limits>
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

    cout << "Welcome " << username << ", please select your animals: ";

    return 0;

}


int main(){
    int newgame = 1; //change with load function

    if (newgame == 1){
        createDatafile();

        title();
        clearScreen();
        userRegister();

        //Todo:
        //SelectAnimal();

        

    }
    else {

    }
    
}
