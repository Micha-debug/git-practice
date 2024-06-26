#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int compare(const void* a, const void* b)
{
    const double* x = (double*) a;
    const double* y = (double*) b;

    if (*x > *y)
        return -1;
    else if (*x < *y)
        return 1;

    return 0;
}

char* allocationc1(char *s, int n){
    s = new char[n];
    return s;
}
double* allocationd1(double *d, int n){
    d = new double[n];
    return d;
}
int* allocationi1(int *a, int n){
    a = new int[n];
    return a;
}
char** allocationc2(char **s, int n, int m){
    s = new char*[n];
    for (int i = 0; i < n; i++){
        s[i] = new char[m];
    }
    return s;
}
int main(int argc, const char * argv[]){
    char *str, **leks, *tokens, *numbers, **leks2;
    double *num_d;
    int *num_i;
    int i = 0, j = 0, rows;
    bool b = false;
    str = allocationc1(str, 50);
    tokens = allocationc1(tokens, 50);
    leks = allocationc2(leks, 50, 50);
    leks2 = allocationc2(leks2, 50, 50);
    fgets(str, 50, stdin);
    fgets(tokens, 50, stdin);
    leks[0] = strtok(str, tokens);
    while (leks[i]!=NULL){
        cout << leks[i] << " ";
        leks[i+1] = strtok(NULL, tokens);
        i++;
    }
    cout << endl;
    rows = i;
    num_d = allocationd1(num_d, rows);
    numbers = allocationc1(numbers, rows);
    num_i = allocationi1(num_i, rows);
    for (i = 0; i < rows; i++){
        /*while ((leks[i][j] >= 0 && leks[i][j] <= 9) || (leks[i][j] == '.' && !b)){
            if (leks[i][j] == '.'){
                b = true;
            }
            numbers[i][j] = leks[i][j];
            j++;
        }*/
        num_d[i] = atof(leks[i]);
        //string s(numbers[i]);
        if (num_d[i]!=0 && leks[i] !=0){
            cout << num_d[i] << " ";
        }
        num_i[i] = int(num_d[i]);
    }
    /*leks[0] = strtok(str, tokens);
    while (leks[i]!=NULL){
        leks[i+1] = strtok(NULL, tokens);
        i++;
    }*/
    cout << endl;
    i = 0;
    /*j = 0;
    unsigned long t = 0;
    leks2[0] = strtok(str, tokens);
    while (leks2[j] != NULL){
        numbers[i] = char(num_i[i]);
        t = strlen(leks2[j]);
        numbers[i + 1] = str[t];
        i += t + 1;
        j++;
        leks2[j] = strtok(NULL, tokens);
    }*/
    for (i = 0; i < rows; i++){
        if (num_i[i]!=0 && leks[i] !=0){
            cout << num_i[i] << " ";
        }
    }
    cout << endl;
    qsort(num_d, rows, sizeof(double), compare);
    for (i = 0; i < rows; i++){
        if (num_d[i]!=0){
            cout << num_d[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
