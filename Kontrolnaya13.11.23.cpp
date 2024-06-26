//
//  main.cpp
//  Kontrolnaya 13.11.23
//
//  Created by Michael Malinovsky on 13.11.23.
//
//Малиновский Михаил, 2 вариант
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

char* allocationc1(char *s, int n){
    s = new char[n];
    return s;
}

float* allocationf1(float *f, int n){
    f = new float[n];
    return f;
}
int** allocation(int **array, int n, int m){
    array = new int*[n];
    for (int i = 0; i<n; i++){
        array[i] = new int[m];
    }
    return array;
}
int substr_max_length(float *f){
    int current_length = 1, max_length = 1;
    for (int i = 0; i < 9; i++){
        if (f[i+1] > f[i]){
            current_length++;
        }
        else{
            if (current_length > max_length){
                max_length = current_length;
            }
            current_length = 1;
        }
    }
    return max_length;
}

void rounding(float *f){
    float *res;
    res = allocationf1(res, 10);
    int j = 0;
    for (int i = 0; i < 10; i++){
        if (f[i] > 20 && f[i] <= 50){
            res[j] = ceilf(f[i]);
            j++;
        }
    }
    for (int i = 0; i < j; i++){
        f[i] = res[i];
    }
}
void fill_random(float *array, int n){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        array[i]=rand()%100001/1000.7;
    }
}

int count_t(char *s){
    int count = 0;
    for (int i = 0; i < strlen(s); i++){
        if (!isalpha(s[i]) && !isdigit(s[i])){
            count++;
        }
    }
    return count;
}
void fill_matrix(int n, int m, int **a){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (abs(i - j)%4 < 2){
                a[i][j] = 1;
            }
            else{
                a[i][j] = 0;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    char *c;
    float *f;
    int n, m;
    cout << "VVedite razmernosti matricy" << endl;
    cin >> n >> m;
    int **a;
    f = allocationf1(f, 256);
    c = allocationc1(c, 256);
    a = allocation(a, n, m);
    fgets(c, 256, stdin);
    fill_random(f, 10);
    for (int i = 0; i < strlen(c); i++){
        cout << c[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++){
        cout << f[i] << " ";
    }
    cout << endl;
    cout << substr_max_length(f);
    cout << endl;
    rounding(f);
    for (int i = 0; i < 10; i++){
        cout << f[i] << " ";
    }
    cout << endl;
    cout << count_t(c);
    fill_matrix(n, m, a);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
