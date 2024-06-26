//
//  main.cpp
//  BertStevens
//
//  Created by Michael Malinovsky on 7.11.23.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;

void push_back_int(char *s, vector<string> tokens_int){
    int num;
    string str;
    num = int(atof(s));
    str = to_string(num);
    tokens_int.push_back(str);
}
char* allocationc1(char *s, int n){
    s = new char[n];
    return s;
}

int main(int argc, const char * argv[]) {
    string inputString, delimiters;
    /*char buffer[256];
    FILE *f1, *f2;
    f1 = fopen("Input.txt", "r");
    while (!feof(f1)){
        fgets(buffer, sizeof(buffer), f1);
        inputString = buffer;
        fgets(buffer, sizeof(buffer), f1);
        delimiters = buffer;
    }
    
    f2 = fopen("Output.txt", "w");*/
    // Read user input
    cin >> inputString;
    cin >> delimiters;
    
    // Split the first string into tokens using any of the specified delimiters
    vector<string> tokens;
    vector<string> tokens_int;
    vector<string> double_first_token;
    vector<string> remove_last_number;
    size_t start = 0;
    size_t pos;
    size_t i = 0;
    size_t j = 0;
    char *s;
    int num;
    string str;
    s = allocationc1(s, 50);
        while ((pos = inputString.find_first_of(delimiters, start)) != string::npos) {
            if (pos != start) {
                // Add the substring before the delimiter
                tokens.push_back(inputString.substr(start, pos - start));
                
                //copy substring to char*
                strcpy(s, tokens[i].c_str());
                //if number - add integer to tokens_int
                if (atof(s)!=0 && s[0] != '0'){
                    num = int(atof(s));
                    str = to_string(num);
                    tokens_int.push_back(str);
                    j = i;
                }
                else{
                    tokens_int.push_back(inputString.substr(start, pos - start));
                }
            }
            i += 2;
            // Add the delimiter itself
            tokens.push_back(inputString.substr(pos, 1));
            tokens_int.push_back(inputString.substr(pos, 1));
            start = pos + 1;
        }

        if (start < inputString.length()) {
            // Add the remaining part of the string
            tokens.push_back(inputString.substr(start));
            strcpy(s, inputString.substr(start).c_str());
            if (atof(s)!=0 && s[0] != '0'){
                num = int(atof(s));
                str = to_string(num);
                tokens_int.push_back(str);
                j = i;
            }
            else {
                tokens_int.push_back(inputString.substr(start));
            }
            
        }
    //for (string& token : tokens){
      //  token += ' m ';
    //}
    for (const string& token : tokens){
        cout << token << " ";
    }
    cout << endl;
    for (const string& token : tokens_int){
        cout << token;
    }
    cout << endl;
    double_first_token = tokens;
    size_t t = double_first_token[0].length();
    double_first_token[0].insert(0, tokens[0]);
    double_first_token[0].insert(t, " ");
    for (const string& token : double_first_token){
        cout << token << " ";
    }
    cout << endl;
    const string empty;
    remove_last_number = tokens;
    i = remove_last_number[j].length();
    remove_last_number[j].replace(0, i, empty);
    for (const string& token : remove_last_number){
        cout << token << " ";
    }
    cout << endl;
    return 0;
}
