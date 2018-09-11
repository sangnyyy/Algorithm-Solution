//
// Created by SML on 2018. 9. 11..
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool p[2501][2501];
char c[2501];
int d[2501];

bool isPalin(int s, int e){
    if(p[s][e]) return p[s][e];
    if(s > e) return false;
    if(s == e) {
        p[s][e] = true;
        return true;
    }
    if(s+1 == e){
        if(c[s] == c[e]){
            p[s][e] = true;
            return true;
        }
    }
    if(c[s] == c[e] && isPalin(s+1, e-1)){
        p[s][e] = true;
    }
    return p[s][e];
}

int go(int n){
    if(n < 1){
        return 0;
    }
    if(n == 1) return 1;
    if(d[n]) return d[n];
    d[n] = n;
    for (int i = n; i >= 1; --i) {
        if(p[i][n]){
            d[n] = min(d[n], go(i-1) + 1);
        }
    }
    return d[n];
}

int main(){
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        c[i+1] = str[i];
    }

    for (int i = 1; i <= str.size(); ++i) {
        for (int j = 1; j <= str.size(); ++j) {
            isPalin(i, j);
        }
    }

    cout << go(str.size()) << '\n';


    return 0;
}
