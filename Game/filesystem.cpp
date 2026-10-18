#include <iostream>
#include <fstream>
#include <string>
#include "filesystem.h"
#include "battlesequence.h"
#include "inventorysystem.h"
#include <filesystem>
#include <vector>

using namespace std;

int getFileSize(){
    const string filename = "Animals.txt";

    ifstream file(filename);

    if (!file.is_open()){
        return -1;
    }

    int linecount = 0;
    string currline;

    while (getline(file, currline)){
        linecount++;
    }
    
    return linecount;
    
} 

void createDatafile(){
    const string filename = "GameSave.txt";

    if (!filesystem::exists(filename)) {
        ofstream createNewFile(filename);
         for (int i = 0; i < 13; i++) {
            createNewFile << "0" << "\n";
        }
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

string getData(int doc, int Line){

    string filename;
    if (doc == 1){
        filename = "GameSave.txt";
    }
    else if (doc == 2){
        filename= "Animals.txt";
    } 
    else {
        return "ERROR! Bad file id in getData";
    }

    vector<string> currentdata;
    string currentline;

    ifstream inFile(filename);
    while (getline(inFile, currentline)) {
        currentdata.push_back(currentline);
    }
    inFile.close();

    return currentdata[Line - 1];
    
}