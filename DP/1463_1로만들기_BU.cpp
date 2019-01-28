//
// Created by SML on 1/28/19.
//

#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001];
int x;

int main(){
    cin >> x;
    for (int i = 2; i <= x; ++i) {
        d[i] = i-1;
        if(i%3 == 0) d[i] = min(d[i], d[i/3] + 1);
        if(i%2 == 0) d[i] = min(d[i], d[i/2] + 1);
        d[i] = min(d[i], d[i-1] + 1);
    }
    cout << d[x] << '\n';

    return 0;
}