//
// Created by SML on 1/8/19.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int ans, limit;
int arr[9];

int main(){
    string s;
    cin >> s;
    int sSize = s.size();
    for (int i = 0; i < sSize; ++i) {
        int temp = s[i] - '0';
        if(temp == 9) temp = 6;
        if(temp == 6){
            if(limit == 1){
                limit = 0;
            }else {
                limit++;
                arr[6]++;
            }
        }else arr[temp]++;
    }
    for (int i = 0; i < 9; ++i) {
        ans = max(arr[i], ans);
    }
    cout << ans << '\n';
    return 0;
}
