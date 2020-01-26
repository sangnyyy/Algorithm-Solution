//
// Created by SML on 1/25/20.
//

#include <iostream>
using namespace std;

int t;

int func(int n){
    return n*(n+1)/2;
}

void dfs(int num, int total, int count, int &result){

    if(num >= total && count < 3){
        return;
    }

    if(count == 3){
        if(num == total) result = 1;
        return;
    }
    for (int i = 1; i <= total; i++) {

        if(func(i) + num <= total){
            dfs(num + func(i), total, count + 1, result);
        }

    }

}

int main(){
    cin >> t;
    while(t--){
        int n, result = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            if(func(i) >= n) break;
            dfs(func(i), n, 1, result);
        }
        cout << result << '\n';
    }
    return 0;
}