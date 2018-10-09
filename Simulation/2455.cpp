//
// Created by SML on 2018. 10. 9..
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int temp = ans;
        int on, off;
        cin >> off >> on;
        temp += (on - off);
        ans = max(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}