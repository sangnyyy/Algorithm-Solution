//
// Created by SML on 1/28/19.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int arr[1001];
int memo[1001];

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    memo[1] = 1;
    for (int i = 2; i <= n; ++i) {
        memo[i] = 1;
        for (int j = 1; j <= i-1; ++j) {
            if(arr[j] < arr[i]){
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, memo[i]);
    }
    cout << ans << '\n';
    return 0;
}