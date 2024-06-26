//
//  main.cpp
//  telephonePlanss
//
//  Created by Michael Malinovsky on 19.01.24.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
int compare(const void *a, const void *b){
    const int* x = (int*) a;
    const int* y = (int*) b;
    if (*x > *y){
        return -1;
    }
    else if(*x < *y){
        return 1;
    }
    return 0;
}
struct MinP{
    string name;
    string plan;
    double sum;
};
struct Plan{
    string plan;
    double sms;
    double calls;
    int freeMinutes;
};
struct Client{
    string name;
    int sms;
    int calls;
};
class TPlan{
public:
    Client cl;
    int count;
    TPlan(Client c, int a){
        cl = c;
        count = a;
    }
    friend istream& operator>>(istream& in, TPlan *obj);
    friend ostream& operator<<(ostream& out, TPlan *obj);
};
istream& operator>>(istream& in, TPlan *obj){
        char *str = new char[256];
        char *token = new char[256];
        in.getline(str, 256);
        token = strtok(str, " ");
        while(!isdigit(token[0])){
            obj->cl.name += token;
            obj->cl.name += " ";
            token = strtok(NULL, " ");
        }
        obj->cl.sms = atoi(token);
        token = strtok(NULL, " ");
        obj->cl.calls = atoi(token);
        return in;
}
ostream& operator<<(ostream& out, TPlan *obj){
    string result;
    result += obj->cl.name;
    result += "  ";
    result += to_string(obj->cl.sms);
    result += " ";
    result += to_string(obj->cl.calls);
    result += "\n";
    out.write(result.c_str(), result.length());
    return out;
}
Plan* readFromFile(){
    int count;
    ifstream inputFile3("TPlan.txt");
    inputFile3 >> count;
    Plan* p = new Plan[count];
    for (int i = 0; i < count; i++){
        inputFile3 >> p[i].plan;
        inputFile3 >> p[i].sms;
        inputFile3 >> p[i].calls;
        inputFile3 >> p[i].freeMinutes;
    }
    inputFile3.close();
    return p;
}
MinP MinPlan(TPlan* p, Plan* ppp){
    double minSum;
    double currentSum; 
    MinP mp;
    int j = 0;
    mp.name = p->cl.name;
    for (int i = 0; i < 6; i++){
        currentSum = ppp[i].sms * (double)p->cl.sms + (p->cl.calls - (double)ppp[i].freeMinutes) * (double)ppp[i].calls;
        if (i == 0){
            minSum = currentSum;
        }
        if (minSum > currentSum){
            minSum = currentSum;
            j = i;
        }
    }
    mp.plan = ppp[j].plan;
    mp.sum = minSum;
    return mp;
}
int main(){
    ofstream outputFile("SClient.txt");
    ifstream inputFile("Clients.txt");
    Client cl1 = {"", 0, 0};
    int lineCount = 0;
    string line;
    while (getline(inputFile, line)) {
        lineCount++;
    }
    inputFile.close();
    ifstream inputFile2("Clients.txt");
    TPlan** tp = new TPlan*[lineCount];
    for (int i = 0; i < lineCount; i++){
        tp[i] = new TPlan(cl1, 0);
        inputFile2 >> tp[i];
        tp[i]->count = lineCount;
        cout << tp[i]->cl.name << " " << tp[i]->cl.sms << " " << tp[i]->cl.calls << endl;
    }
    inputFile2.close();
    int* mas;
    mas = new int[lineCount];
    for (int i = 0; i < lineCount; i++){
        mas[i] = tp[i]->cl.calls;
    }
    qsort(mas, lineCount, sizeof(int), compare);
    for (int i = 0; i < lineCount; i++){
        if (i!=0){
            if (mas[i] != mas[i-1]){
                for (int j = 0; j < lineCount; j++){
                    if (mas[i] == tp[j]->cl.calls){
                        outputFile << tp[j];
                        //cout << mas[i] << endl;
                    }
                 }
            }
        }
        else{
            for (int j = 0; j < lineCount; j++){
                    if (mas[i] == tp[j]->cl.calls){
                        outputFile << tp[j];
                        //cout << mas[i] << endl;
                    }
                 }
        }
    }
    Plan* pl = new Plan[6];
    pl = readFromFile();
    for (int i = 0; i < 6; i++){
        cout << pl[i].plan << " ";
        cout << pl[i].sms << " ";
        cout << pl[i].calls << " ";
        cout << pl[i].freeMinutes << endl;
    }
    MinP* mip = new MinP[lineCount];
    ofstream outputFile2("PlanSort.txt");
    for (int i = 0; i < lineCount; i++){
        mip[i] = MinPlan(tp[i], pl);
        outputFile2 << mip[i].name << " " << mip[i].plan << " " << mip[i].sum << endl;
    }
    outputFile.close();
    outputFile2.close();
    return 0;
}
