//
//  main.cpp
//  lab8rec
//
//  Created by Michael Malinovsky on 17.12.23.
//

#include <iostream>
using namespace std;

int recurs(int *a, int x, int &i, int len, int &count){
    if (i<len)
    {
        if( a[i]!= x)
            count++;
        i++;
        recurs(a, x, i, len, count);
    }
    return count;
    
}
int main(int argc, const char * argv[]) {
    int *a;
    int n, x, i = 0, count = 0;
    cout << "Enter size of array and X" << endl;
    cin >> n >> x;
    a = new int[n];
    for (int j = 0; j < n; j++){
        cin >> a[j];
    }
    cout << recurs(a, x, i, n, count) << endl;
    return 0;
}
