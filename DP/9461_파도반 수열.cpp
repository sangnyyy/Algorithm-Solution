//
// Created by SML on 1/28/19.
//

#include <iostream>
#include <cstring>
using namespace std;

int t;
long long memo[101];

long long dp(long long n){
    if(n <= 5) return memo[n];
    if(memo[n] > 0) return memo[n];
    memo[n] = dp(n-1) + dp(n-5);
    return memo[n];
}

int main(){
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        memset(memo, 0, sizeof(memo));
        memo[1] = memo[2] = memo[3] = 1;
        memo[4] = memo[5] = 2;
        cout << dp(n) << '\n';
        t--;
    }
    return 0;
}