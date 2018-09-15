//
// Created by SML on 2018. 9. 15..
//

#include <iostream>
#include <cstring>
using namespace std;

int a[50];
int d[7];
int n;
void dfs(int now, int depth){
    if(depth > 6){
        for (int i = 1; i <= 6; ++i) {
            cout << d[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = now; i <= n; ++i) {
        d[depth] = a[i];
        dfs(i+1, depth+1);
    }
}

int main(){

    while(true){
        memset(a, 0, sizeof(a)); memset(d, 0 ,sizeof(d));
        cin >> n;
        if(!n) break;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        dfs(1,1);
        cout << '\n';
    }


    return 0;
}