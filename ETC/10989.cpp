//
// Created by SML on 2018. 10. 10..
//

#include <iostream>
#include <algorithm>
using namespace std;

int d[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        d[temp]++;
    }

    for (int i = 0; i < 10001; ++i) {
        if(d[i] > 0){
            for (int j = 0; j < d[i]; ++j) {
                cout << i << '\n';
            }
        }
    }
    return 0;
}