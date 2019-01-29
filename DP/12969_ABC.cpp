//
// Created by SML on 1/29/19.
//

#include <iostream>
#define NOANSWER -1
using namespace std;

int n, k;

// 현재 위치, a의 갯수, b의 갯수, k의 범위
bool memo[31][31][31][436];
//문자열 s
char s[30];

bool dp(int x, int a, int b, int p){
    if(x == n){
        if(p == k) return true;
        else return false;
    }
    //memoization
    //방문된적 있다면 false
    if(memo[x][a][b][p]) return false;
    memo[x][a][b][p] = true;

    s[x] = 'A';
    if(dp(x+1, a+1, b, p)) return true;

    s[x] = 'B';
    if(dp(x+1, a, b+1, p + a)) return true;

    s[x] = 'C';
    if(dp(x+1, a, b, p + a + b)) return true;
}

int main(){
    cin >> n >> k;
    if(dp(0,0,0,0)) cout << s << '\n';
    else cout << NOANSWER  << '\n';
    return 0;
}