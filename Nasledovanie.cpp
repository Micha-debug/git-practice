//
//  main.cpp
//  nasledovanie4lab
//
//  Created by Michael Malinovsky on 9.03.24.
//

#include <iostream>
#include <string.h>
using namespace std;
class AbstractComputer{
protected:
    const int m_id;
    const string m_name;
public:
    static int count;
    AbstractComputer(const int id, const string name)
    : m_id(id), m_name(name){
        count++;
    }
    virtual string GetName()  = 0;
    virtual int GetId(){return m_id;}
    virtual void Show(){
        cout << "ID: " << m_id << endl << "Name: " << m_name << endl << "Count: " << count << endl;
    }
    ~AbstractComputer(){
        count--;
    }
};
class CPU{
protected:
    int m_power;
public:
    CPU(int power)
    : m_power(power){}
    int GetPower(){return m_power;}
    void SetPower(int power){
        m_power = power;
    }
};
class desktopComputer: public AbstractComputer
{
private:
    CPU m_processor;
    string m_brand;
    double m_price;
public:
    desktopComputer(const int id, const string name, string brand, double price, CPU processor)
    : m_brand(brand), m_price(price), AbstractComputer(id, name), m_processor(processor){
    }
    ~desktopComputer(){
    }
    string GetName(){return m_name;};
    string GetBrand(){return m_brand;}
    double GetPrice(){return m_price;}
    void Show(){cout << "ID: " << m_id << endl << "Name: " << m_name << endl << "Марка: " << m_brand << endl << "Цена: " << m_price << endl << "Мощность: " << m_processor.GetPower() << endl << "Count: " << count << endl;}
};
class CompWMonitor: public AbstractComputer{
private:
    double m_width;
public:
    
    CompWMonitor(const int id, const string name, double width)
    : AbstractComputer(id, name), m_width(width){
    }
    ~CompWMonitor(){
    }
public:
    void Show(){
        AbstractComputer::Show();
        cout << "Width: " << m_width << endl << "Count: " << count << endl;
    }
    string GetName(){return m_name;};

};
int AbstractComputer::count = 0;
int main(int argc, const char * argv[]) {
    CompWMonitor CompWM1(22, "Macintosh", 17.6);
    CompWM1.Show();
    CPU Pprocessor(1000);
    desktopComputer Lenovo1(11, "kkk", "Lenovo", 222.99, Pprocessor);
    Lenovo1.Show();
    return 0;
}
