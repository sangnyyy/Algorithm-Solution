//
// Created by SML on 1/4/19.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, ans;
int d[1001][1001];

class node{
public:
    int s, c;
    node(int s, int c){
        this->s = s;
        this->c = c;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    memset(d, -1, sizeof(d));
    queue<node> q;
    d[1][0] = 0;
    q.push(node(1, 0));
    while(!q.empty()){
        int s = q.front().s;
        int c = q.front().c;
        q.pop();
        if(d[s][s] == -1){
            d[s][s] = d[s][c] + 1;
            q.push(node(s, s));
        }
        if(s+c <= n && d[s+c][c] == -1) {
            d[s+c][c] = d[s][c] + 1;
            q.push(node(s+c, c));
        }
        if( s-1 >= 0 && d[s-1][c] == -1){
            d[s-1][c] = d[s][c] + 1;
            q.push(node(s-1, c));
        }
    }
    ans = -1;
    for (int i=0; i<=n; i++) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}