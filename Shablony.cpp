//
//  main.cpp
//  prMASSIVc++Shablony
//
//  Created by Michael Malinovsky on 21.03.24.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Element1 {
    public:
        char Name[50];
        char Addr[50];
        friend ostream& operator <<(ostream& out, Element1& e1){
            out << e1.Name << " " << e1.Addr << endl;
            return out;
        }
        friend istream& operator >>(istream& in, Element1& e1) {
            in >> e1.Name >> e1.Addr;
            return in;
        }
};
struct Element2 {
    public:
        char Name[50];
        int date;
        friend ostream& operator <<(ostream& out, Element2& e2){
            out << e2.Name << " " << e2.date << endl;
            return out;
        }
        friend istream& operator >>(istream& in, Element2& e2) {
            in >> e2.Name >> e2.date;
            return in;
        }
        Element2& operator =(const Element2& other){
            strcpy(this->Name, other.Name);
            this->date = other.date;
            return *this;
        }
};
struct Element3 {
    public:
        char Name[50];
        char Addr[50];
        double Price;
        friend ostream& operator <<(ostream& out, Element3& e3){
            out << e3.Name << " " << e3.Addr << " " << e3.Price << endl;
            return out;
        }
        friend istream& operator >>(istream& in, Element3& e3) {
            in >> e3.Name >> e3.Addr >> e3.Price;
            return in;
        }
        Element3& operator =(const Element3& other){
            strcpy(this->Name, other.Name);
            strcpy(this->Addr, other.Addr);
            this->Price = other.Price;
            return *this;
        }
};
/*
int compare(const void *x, const void *y){
    int a = ((Element2*)x)->date;
    int b = ((Element2*)y)->date;
    if (a > b){
        return 1;
    }
    return a==b? 0 : -1;
}*/
bool operator >(const Element2& e1, const Element2& e2){
    if (e1.date > e2.date){
        return true;
    }
    else return false;
}
/*bool CompChar1(const Element1 &e1, const char *s){
    if(strcmp(e1.Name, s)) return false;
    else return true;
}
bool CompChar2(const Element2 &e2, const char *s){
    if(strcmp(e2.Name, s)) return false;
    else return true;
}
bool CompChar3(const Element3 &e3, const char *s){
    if(strcmp(e3.Name, s)) return false;
    else return true;
}*/
vector <Element3> Substraction(vector <Element1> e1, vector <Element2> e2, vector <Element3> e3) {
    vector <Element3> e32(e3.begin(), e3.end());
    for (int i = 0; i < e3.size(); i++){
        //cout << "Name " << i << ": " << e1[i].Name << endl;
        const char *searchName = e3[i].Name;
        if (find_if(e2.begin(), e2.end(), [searchName](const Element2 &e2){
            return (strcmp(e2.Name, searchName) == 0);
        }) != e2.end())
        {
            auto it = find_if(e32.begin(), e32.end(), [searchName](const Element3 &e32){
            return (strcmp(e32.Name, searchName) == 0);
        });
            e32.erase(it);
        }
    }
    int sizeOfE32 = e32.size();
    int j = 0;
    for (int i = 0; i < sizeOfE32; i++){
        const char *searchName = e32[j].Name;
        j++;
        if (find_if(e1.begin(), e1.end(), [searchName](const Element1 &e1){
            return (strcmp(e1.Name, searchName) == 0);
        }) == e1.end())
        {
            j--;
            e32.erase(e32.begin() + j);
        }
    }
    return e32;
}
vector <Element2> AfterDate(vector <Element2> e2, int D){
    vector <Element2> after;
    //after = new Element2[size];
    //int j = 0;
    for (int i = 0; i < e2.size(); i++){
        if (e2[i].date > D){
            after.push_back(e2[i]);
            //strcpy(after[j].Name, e2[i].Name);
            //j++;
        }
    }
    /*Element2 *result;
    result = new Element2[j];
    for (int i = 0; i < j; i++){
        result[i].date = after[i].date;
        strcpy(result[i].Name, after[i].Name);
    }*/
    return after;
}
/*
vector <Element2> Sorted(vector <Element2> e2){
    qsort(&e2[0], e2.size(), sizeof(Element2), compare);
    return e2;
}*/

template <class T>
class MASSIV {
public:
    int count;
    //int countE2;
    //int countE3;
    vector <T> elem ;/*= {
        {"V", 2},
        {"P", 2},
        {"A", 2},
        {"O", 2},
        {"D", 2},
        {"S", 2},
        {"I", 2}
    };*/
    /*vector <Element1> e1 = {
        {"V", "S1s"},
        {"P", "S22"},
        {"A", "S999"},
        {"S", "w"},
        {"I", "A02"}
    };
    vector <Element3> e3 = {
        {"V", "S", 2.2},
        {"P", "S", 2.2},
        {"A", "S", 2.2},
        {"O", "L", 3.4},
        {"D", "P", 2.2},
        {"S", "S", 9.9},
        {"I", "A02", 1.1}
    };*/
public:
    MASSIV(){
        //e1 = {"Vasya", "Syrokomli22-100"};
    }
    MASSIV(int size){
        //e1 = {"Vasya", "Syrokomli22-100"};
        elem.resize(size);
        
    }
    friend istream& operator>>(istream& in, MASSIV *obj){
        in >> obj->count;
        obj->elem.resize(obj->count);
        for (int i = 0; i < obj->count; i++){
            in>>obj->elem[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, MASSIV *obj)
    {
        for (int i = 0; i < obj->count; i++){
            out << obj->elem[i];
        }
        return out;
    }

};
/*ofstream& operator<<(ofstream& out, MASSIV <Element1> *obj){
    for (int i = 0; i < obj->count; i++){
        out << obj->elem[i];
    }
    return out;
}
ofstream& operator<<(ofstream& out, MASSIV <Element2> *obj){
    for (int i = 0; i < obj->count; i++){
        out << obj->elem[i];
    }
    return out;
}
ofstream& operator<<(ofstream& out, MASSIV <Element3> *obj){
    for (int i = 0; i < obj->count; i++){
        out << obj->elem[i];
    }
    return out;
}*/
    /*
    out << obj->e1.Name;
    out << obj->e1.Addr;
    out << obj->e2.Name;
    out << obj->e2.date;
    out << obj->e3.Name;
    out << obj->e3.Addr;
    out << obj->e3.Price;
    */

/*ifstream& operator>>(ifstream& in, MASSIV <Element1> *obj){
    // int size;
    // in >> size;
    // char Name[50];
    // char Addr[50];
    in >> obj->count;
    for (int i = 0; i < obj->count; i++){
       in>>obj->elem[i];
    }
    // for(int i = 0; i < size; i++){
    //     in>>Name>>Addr;
    // }
    return in;
}
ifstream& operator>>(ifstream& in, MASSIV <Element2> *obj){
    in >> obj->count;
    for (int i = 0; i < obj->count; i++){
        in>>obj->elem[i];
    }
    return in;
}
ifstream& operator>>(ifstream& in, MASSIV <Element3> *obj){
    in >> obj->count;
    for (int i = 0; i < obj->count; i++){
        in>>obj->elem[i];
    }
    return in;
}*/
template <class T>
void Sort(MASSIV <T> *obj){
    for(int i = 0; i < obj->count; i++){
        for(int j = i + 1; j < obj->count; j++){
            if (obj->elem[i] > obj->elem[j]){
                swap(obj->elem[i], obj->elem[j]);
            }
        }
    }

}
/*Element3& Element3::operator = (Element3& other){
    strcpy(this->Name, other.Name);
    strcpy(this->Addr, other.Addr);
    this->Price = other.Price;
    return *this;
}*/
    /*char **buff = new char*[6];
    for (int i = 0; i < 6; i++){
        buff[i] = new char[256];
    }
    char *p = new char[256];
    in.getline(buff[0], 256);
    int NumberOfElem1 = atoi(buff[0]);
    obj->countE1 = NumberOfElem1;
    for (int i = 0; i < NumberOfElem1; i++){
        in.getline(buff[1], 256);
        p = strtok(buff[1], " ");
        //while (p!=NULL)
        //{
        strncpy(obj->e1[i].Name, p, 49);
        obj->e1[i].Name[49] = '\0';
        p = strtok(NULL, " ");
        strncpy(obj->e1[i].Addr, p, 49);
        obj->e1[i].Addr[49] = '\0';
        //}
    }
    in.getline(buff[2], 256);
    int NumberOfElem2 = atoi(buff[2]);
    for (int i = 0; i < NumberOfElem2; i++){
        in.getline(buff[3], 256);
        p = strtok(buff[3], " ");
        strncpy(obj->e2[i].Name, p, 49);
        obj->e2[i].Name[49] = '\0';
        p = strtok(NULL, " ");
        obj->e2[i].date = atoi(p);
        buff[3][0] = '\0';
    }
    in.getline(buff[4], 256);
    int NumberofElem3 = atoi(buff[4]);
    for (int i = 0; i < NumberofElem3; i++){
        in.getline(buff[5], 256);
        p = strtok(buff[5], " ");
        strncpy(obj->e3[i].Name, p, 49);
        obj->e3[i].Name[49] = '\0';
        p = strtok(NULL, " ");
        strncpy(obj->e3[i].Addr, p, 49);
        obj->e3[i].Name[49] = '\0';
        p = strtok(NULL, " ");
        char *endPtr;
        obj->e3[i].Price = strtod(p, &endPtr);
        buff[5][0] = '\0';

    }*/

int main(int argc, const char * argv[]) {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    MASSIV <Element1> *mass1;
    MASSIV <Element2> *mass2, *outMass2;
    MASSIV <Element3> *mass3;
    MASSIV <Element3> *outMass3;
    MASSIV <int> *massint;
    massint = new MASSIV <int>(6);
    inputFile >> massint;
    cout << massint << endl;
    mass1 = new MASSIV <Element1>();
    mass2 = new MASSIV <Element2>();
    mass3 = new MASSIV <Element3>();
    outMass3 = new MASSIV <Element3>();
    outMass2 = new MASSIV <Element2>();
    //outMass = new MASSIV <Element2>();
    inputFile >> mass1;
    inputFile >> mass2;
    inputFile >> mass3;
    inputFile.close();
    cout << mass1 << endl << mass2 << endl << mass3 << endl;
    // vector <Element2> empty1;
    // vector <Element2> empty2;
    // vector <Element3> empty3;
    outMass3->elem = Substraction(mass1->elem, mass2->elem, mass3->elem);
    outMass3->count = outMass3->elem.size();
    Sort(mass2);
    Sort(massint);
    cout << massint << endl;
    outMass2->elem = AfterDate(mass2->elem, 20090101);
    outMass2->count = outMass2->elem.size();
    outputFile << "Sorted: " << endl;
    outputFile << mass2;
    outputFile << "Substraction: " << endl;
    outputFile << outMass3;
    outputFile << "After Date: " << endl;
    outputFile << outMass2;
    outputFile.close();
    /*for (auto x: mass->e1){
        cout << "Name: " << x.Name << endl;
        cout << "date: " << x.Addr << endl;
    }*/
        /*
    empty3 = Substraction(mass->e1, mass->e2, mass->e3);
    empty1 = AfterDate(mass->e2, 20081010);
    empty2 = Sorted(mass->e2);
    outMass->e3 = empty3;
    outMass->e2 = empty1;
    outMass2->e2 = empty2;
    outputFile << outMass;
    outputFile << outMass2;
    outputFile.close();
*/
    /*empty3 = Substraction(mass->e1, mass->e2, mass->e3);
    empty1 = AfterDate(mass->e2, 20081010);
    empty2 = Sorted(mass->e2);
    cout << "Substraction: " << endl;
    for (auto x: empty3){
        cout << "Name: " << x.Name << endl;
        cout << "Address: " << x.Addr << endl;
        cout << "Price: " << x.Price << endl;
    }
    cout << "Sorted: " << endl;
    for (auto x: empty2){
        cout << "Name: " << x.Name << endl;
        cout << "date: " << x.date << endl;
    }
    cout << "After Date: " << endl;
    for (auto x: empty1){
        cout << "Name: " << x.Name << endl;
        cout << "date: " << x.date << endl;
    }*/

    return 0;
}
