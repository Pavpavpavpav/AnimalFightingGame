#pragma once
#include <string>


int getFileSize();
void createDatafile();
void saveData(std::string& data, int Line);
std::string getData(int doc, int Line);
