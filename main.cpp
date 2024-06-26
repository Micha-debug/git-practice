//
//  main.cpp
//  Kontr.23.05.24
//
//  Created by Michael Malinovsky on 23.05.24.
//

#include <iostream>
#include <list>
#include <string>
#include <numeric>
#include <algorithm>
#include <regex>
#include <map>
using namespace std;
class Elem{
public:
    double numb;
    int number;
    Elem(double n, int num) : numb(n), number(num) {}
};
int count_occurrences(const list<string>& container, const string& S) {
return accumulate(container.begin(), container.end(), 0, [&S](int acc, const string& item) {
return acc + (item == S ? 1 : 0);
});
}
int main(int argc, const char * argv[]) {
    list<string> container{"stroka", "stroka", "nestroka", "tozhenestroka"};
    string S = "stroka";
    int occurrences = count_occurrences(container, S);
    cout << "The string '" << S << "' appears " << occurrences << " times in the list." << endl;
    regex pattern("^A.*ok.*");
    string example = "A djlg ok slsl";
    if (regex_match(example, pattern)){
        cout << "The string matches the condition" << endl;
    }
    else{
        cout << "The string doesn't match the condition" << endl;
    }
//    map <double, Elem> myMap;
//    myMap[1.1] = Element(2.2, 3); - пишет no matching constructor for initialization of 'Elem'
//    // Вывод содержимого map
//    for (const auto& pair : myMap) {
//    cout << "Ключ: " << pair.first << ", Значения: " << pair.second.numb << ", " << pair.second.number << endl;
//    }

    return 0;
}
