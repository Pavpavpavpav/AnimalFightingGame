#include <iostream>
#include <fstream>
#include <string>
#include "filesystem.h"
#include <filesystem>
#include <vector>

using namespace std;

void createDatafile(){
    const string filename = "GameSave.txt";

    if (!filesystem::exists(filename)) {
        ofstream createNewFile(filename);
        createNewFile.close(); 
    }
}

void saveData(string& data, int Line){
    const string filename = "GameSave.txt";

    vector<string> currentdata;
    string currentline;

    ifstream inFile(filename);
    while (getline(inFile, currentline)) {
        currentdata.push_back(currentline);
    }
    inFile.close();

    if (Line > currentdata.size()) {
        currentdata.resize(Line, ""); 
    }

    currentdata[Line - 1] = data;

    ofstream GameSave(filename); 
    if (GameSave.is_open()) {
        for (const string l : currentdata) {
            GameSave << l << "\n";
        }
        GameSave.close();
    } else {
        cerr << "Error: Could not open " << filename << endl;
    }

}