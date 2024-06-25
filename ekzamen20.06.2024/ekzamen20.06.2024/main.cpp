//
//  main.cpp
//  ekzamen20.06.2024
//
//  Created by Michael Malinovsky on 20.06.24.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
struct Fanat1{
    string name, nationality;
    int year, n;
    //public:
    friend istream& operator>>(istream& in, Fanat1& obj){
        //string s;
        getline(in, obj.name, ',');
        getline(in, obj.nationality, ',');
        in >> obj.year;
        in >> obj.n;
        //getline(in, s);
        return in;
    }
    friend ostream& operator<<(ostream& out, Fanat1& obj){
        out << obj.name << ", ";
        out << obj.nationality << ", ";
        out << obj.year << ", ";
        out << obj.n << endl;
        return out;
    }
};
struct Fanat2{
    string name;
    int code, n;
    friend istream& operator>>(istream& in, Fanat2& obj){
        //string s;
        getline(in, obj.name, ',');
        in >> obj.code;
        in >> obj.n;
        //getline(in, s);
        return in;
    }
    friend ostream& operator<<(ostream& out, Fanat2& obj){
        out << obj.name << ", ";
        out << obj.code << ", ";
        out << obj.n << endl;
        return out;
    }
};
struct Fanat3{
    string name, nationality;
    int code, n, year;
    friend istream& operator>>(istream& in, Fanat3& obj){
        //string s;
        getline(in, obj.nationality, ',');
        getline(in, obj.name, ',');
        in >> obj.year;
        in >> obj.n;
        in >> obj.code;
        //getline(in, s);
        return in;
    }
    friend ostream& operator<<(ostream& out, Fanat3& obj){
        out << obj.nationality << ", ";
        out << obj.name << ", ";
        out << obj.year << ", ";
        out << obj.n << ", ";
        out << obj.code << endl;
        return out;
    }
    void operator=(const Fanat1& obj){
        this->name = obj.name;
        this->nationality = obj.nationality;
        this->year = obj.year;
        this->n = obj.n;
        this->code = 0;
    }
    void operator=(const Fanat2& obj){
        this->name = obj.name;
        this->nationality = "";
        this->year = 0;
        this->n = obj.n;
        this->code = obj.code;
    }
};
template <class T, class S>
bool equalNames(const T& a, const S& b){
    return (a.name == b.name);
}
//template <class T>
bool compareByName(const Fanat1& a, const Fanat1& b) {
    return a.name < b.name;
}
bool compareByNameD(const Fanat1& a, const Fanat1& b) {
    return a.name > b.name;
}
template <class T>
class DATA{
    public:
    vector <T> M;
    int count = 0;
    public:
    vector <T>& Get_M(){
        return M;
    }
    int Get_count(){
        return count;
    }
    void Set_M(vector <T> A){
        M = A;
    }
    void Set_count(int a){
        count = a;
    }
    DATA(){}; 
    ~DATA(){
        //delete[] M;
    };
    void ReadData(istream& in){
        T temp; // = new T[3];
        while (!in.eof()) {
            in >> temp;
            M.push_back(temp);
            count++;
        }
    }
    void WriteData(ostream& out){
        for (int k = 0; k < count; k++){
            out << M[k];
        }
    }
    vector <Fanat3> Unio(const DATA <Fanat1>& obj1, const DATA <Fanat2>& obj2){
        vector <Fanat3> f;
        Fanat3 temp;
        string searchName;
        temp = obj1.M[0];
        f.push_back(temp); 
        for (int i = 1; i < obj1.count; i++){
            searchName = obj1.M[i].name;
            auto it = find_if(f.begin(), f.end(), [searchName](const Fanat3& f){
            return (searchName == f.name);
            });
            if(it != f.end()){
                it->name = obj1.M[i].name;
                it->nationality = obj1.M[i].nationality;
                it->year = obj1.M[i].year;
                it->n = it->n + obj1.M[i].n;
                it->code = 0;
            }
            else{
                temp = obj1.M[i];
                f.push_back(temp);
            }
        }
        for (int i = 0; i < obj2.count; i++){
            searchName = obj2.M[i].name;
            auto it = find_if(f.begin(), f.end(), [searchName](const Fanat3& f){
            return (searchName == f.name);
            });
            if(it != f.end()){
                it->n = it->n + obj2.M[i].n;
                it->code = obj2.M[i].code;
            }
            else{
                temp = obj2.M[i];
                f.push_back(temp);
            }
        }
        return f;
    }
};

int main(int argc, const char * argv[]) {
    DATA <Fanat1> m1, m2;
    DATA <Fanat2> k1, k2;
    DATA <Fanat3> l1, l2;
    ifstream in1("Input.txt");
    ifstream in2("Input2.txt");
    ofstream o1("Output.txt");
    m1.ReadData(in1);
    k1.ReadData(in2);
    m1.WriteData(cout);
    m1.WriteData(o1);
    k1.WriteData(o1);
    vector <Fanat1> V1;
    V1 = m1.Get_M();
    sort(V1.begin(), V1.end(), compareByName);
    m1.Set_M(V1);
    o1 << "Sorted: " << endl;
    m1.WriteData(o1);
    sort(V1.begin(), V1.end(), compareByNameD);
    m1.Set_M(V1);
    o1 << "Sorted D: " << endl;
    m1.WriteData(o1);
    l1.Set_M(l1.Unio(m1, k1));
    int q = (l1.Get_M()).size(); 
    l1.Set_count(q);
    o1 << "Union:" << endl;
    l1.WriteData(o1);
    return 0;
}
