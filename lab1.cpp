//
//  main.cpp
//  prlab1_2023sem1
//
//  Created by Michael Malinovsky on 9.09.23.
//

#include <iostream>
#include <math.h>
using namespace std;

int min_val(int *a, int m){
    int sum = 1;
    for (int i = 0; i < m; i++){
        if (a[i] > sum){
            return sum;
        }
        sum = sum + a[i];
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter non-decreasing array" << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << min_val(arr, n);
}
