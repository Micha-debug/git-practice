//
//  main.cpp
//  Regexlab
//
//  Created by Michael Malinovsky on 18.04.24.
//

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "rus");
    char *s;
    s = new char[100];
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if(!inputFile.is_open()){
        cout << "Error opening file";
    }
    //ofstream outputFile("output.txt");
    int i = 1;
    while (!inputFile.eof()){
        inputFile >> s;
        regex pattern("^[+]?(8017|(375(44|33|29|25)))[0-9]{7}");
        if (regex_match(s, pattern)){
            outputFile << "Строка " << s << " соответствует номеру телефона" << endl;
        }
        else{
            outputFile << "Строка " << s << " не соответствует номеру телефона" << endl;
        }
        i++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
