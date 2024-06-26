//
//  main.cpp
//  Kontrolnaya16.05.24
//
//  Created by Michael Malinovsky on 16.05.24.
//
//Малиновский 2 вариант
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Elem{
    string leks;
    double numb;
    friend ostream& operator <<(ostream& out, Elem& e){
        out << e.leks << " " << e.numb << endl;
        return out;
    }
    friend istream& operator >>(istream& in, Elem& e) {
        in >> e.leks >> e.numb;
        return in;
    }
};
template <class X>
class Massiv{
    public:
    vector <X> elem;
    int count;
    friend istream& operator>>(istream& in, Massiv *obj){
        in >> obj->count;
        obj->elem.resize(obj->count);
        for (int i = 0; i < obj->count; i++){
            in>>obj->elem[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Massiv *obj)
    {
        for (int i = 0; i < obj->count; i++){
            out << obj->elem[i];
        }
        return out;
    }
    void operator-(int k){
        int i = 0;
        while ((i < k) && (i < this->count)){
            if((this->elem[i].numb % 2) == 0){
                elem.erase(elem.begin() + i);
                i++;
            }
        }
    }
    Massiv(){}
};

int main(int argc, const char * argv[]) {
    Massiv <Elem> *mas;
    mas = new Massiv <Elem>;
    ifstream inputFile2("input2.txt");
    ifstream inputFile22("input22.txt");
    if(!inputFile22.is_open()){
        cout << "Can't open file" << endl;
    }
    while (!inputFile22.eof()){
        inputFile22 >> mas;
    }
    cout << mas;
    mas = mas - 2;//компилятор не заходит в функцию
    cout << mas;
    Massiv <int> *massint;
    return 0;
}
