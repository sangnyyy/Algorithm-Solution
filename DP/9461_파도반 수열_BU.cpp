//
// Created by SML on 1/28/19.
//

#include <iostream>
#include <cstring>
using namespace std;

int t;
long long memo[101];

int main(){
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        memset(memo, 0, sizeof(memo));
        memo[1] = memo[2] = memo[3] = 1;
        memo[4] = memo[5] = 2;
        for (int i = 6; i <= n; ++i) {
            memo[i] = memo[i-1] + memo[i-5];
        }
        cout << memo[n] << '\n';
        t--;
    }
    return 0;
}