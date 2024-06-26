//
//  main.cpp
//  Kontrolnaya18.12.23
//
//  Created by Michael Malinovsky on 18.12.23.
//

#include <iostream>
#include <cstring>
using namespace std;

class Element{
public:
    int ind;
    float price;
    char *name;
    Element() : ind(0), price(0.0), name("") {}
    Element(int i, float p, const char *n){
        ind = i;
        price = p;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    Element(const Element& other) : ind(other.ind), price(other.price), name(other.name) {}
    Element& operator=(const Element& other) {
            if (this != &other) {
                delete[] name;
                ind = other.ind;
                price = other.price;
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
            return *this;
        }
    Element& operator-(long k){
            Element *result = new Element(this->ind, this->price, this->name);
            result->price -=k;
            return *result;
        }
    friend ostream& operator<<(ostream& out, const Element *m);
    friend istream& operator>>(istream& in, Element *m);

    ~Element(){
        delete[] name;
    }
};

ostream& operator<<(ostream& out, const Element *m){
    out << "Index: " << m->ind << ", Price: " << m->price << ", Name: " << m->name << endl;
    return out;
}

istream& operator>>(istream& in, Element *m){
    cout << "Enter index: ";
    in >> m->ind;
    cout << "Enter price: ";
    in >> m->price;
    char buf[100];
    cout << "Enter name: ";
    in.getline(buf, 100);
    in.getline(buf, 100);
    m->name = new char[strlen(buf) + 1];
    strcpy(m->name, buf);
    return in;
}

int main() {
    Element *e1 = new Element(1, 500, "Laptop");
    Element *e2 = new Element(1, 500, "Laptop");
    cout << "Input element details" << endl;
    cin >> e1;
    cin >> e2;
    cout << e1;
    cout << e2;
    //e2 = e1;
    //cout << e2;
    Element e3 = *e2-(long)3;
    cout << "Difference = " << &e3 << endl;
    //delete e1;
    //delete e2;
    return 0;
}
