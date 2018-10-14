//
// Created by SML on 2018. 10. 14..
//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int MAX, MIN;
int a[12];
int oper[4];
bool flag = false;

void dfs(int at, int result) {
    if (at == n) {
        if(!flag){
            MIN = result;
            MAX = result;
            flag = true;
        }else{
            MAX = max(MAX, result);
            MIN = min(MIN, result);
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (oper[i] && i == 0) {
            result += a[at + 1];
            oper[i]--;
            dfs(at + 1, result);
            oper[i]++;
            result -= a[at + 1];
        }
        if (oper[i] && i == 1) {
            result -= a[at + 1];
            oper[i]--;
            dfs(at + 1, result);
            oper[i]++;
            result += a[at + 1];
        }
        if (oper[i] && i == 2) {
            result *= a[at + 1];
            oper[i]--;
            dfs(at + 1, result);
            oper[i]++;
            result /= a[at + 1];
        }
        if (oper[i] && i == 3) {
            if(result > 0) {
                result /= a[at + 1];
                oper[i]--;
                dfs(at + 1, result);
                oper[i]++;
                result *= a[at + 1];
            }else{
                result *= -1;
                result /= a[at + 1];
                result *= -1;
                oper[i]--;
                dfs(at + 1, result);
                oper[i]++;
                result *= -1;
                result *= a[at + 1];
                result *= -1;
            }
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> oper[i];
    }
    dfs(1, a[1]);

    cout << MAX << '\n';
    cout << MIN << '\n';

    return 0;
}