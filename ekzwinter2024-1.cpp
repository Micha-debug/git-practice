//
//  main.cpp
//  ekzamen1sem
//
//  Created by Michael Malinovsky on 15.01.24.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct Human{
    string name;
    string month;
    int day;
    int year;
};
class TPerson{
public:
    Human person;
    int CRS;
    int count;
    int MAS[9];
    TPerson(Human p, int n, int c, int m[9]){
        person = p;
        CRS = n;
        count = c;
        for (int i = 0; i < count; i++){
            MAS[i] = m[i];
        }
    }
    ~TPerson(){
    }
    friend ofstream& operator<<(ofstream& out, const TPerson *obj);
    friend ifstream& operator>>(ifstream& in, const TPerson *obj);
};

ofstream& operator<<(ofstream& out, const TPerson *obj){
    out.write((char*)&obj->person, sizeof(obj->person));
    out.write((char*)&obj->count, sizeof(obj->count));
    for (int i = 0; i < obj->count; i++){
        out.write((char*)&obj->MAS[i], sizeof(obj->MAS[i]));
    }
    return out;
}

ifstream& operator>>(ifstream& in, char *str){
    in.getline(str, 128);
    return in;
}
int main(int argc, const char * argv[]) {
    ifstream inputFile("Input.txt");
    ofstream outputFile("Output.txt");
    if (inputFile.is_open() && outputFile.is_open()){
        /*string line;
        getline(inputFile, line);
        outputFile << line;
         */
        Human p = {"Ада Августа Кинг Лавлейс", "декабря", 10, 1815};
        int m[9] = {1, 2, 3, 4, 5};
        TPerson *A = new TPerson(p, 12345, 5, m);
        outputFile << A;
        inputFile.close();
        outputFile.close();
    }
    else {
        cout << "Nevozmozhno otkryt file";
    }
    cout << "OK" << endl;
    return 0;
}
