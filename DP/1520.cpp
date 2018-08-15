//
// Created by SML on 2018. 8. 15..
//

#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int d[501][501];
int a[501][501];

const int dy[] = { -1, 1, 0 ,0};
const int dx[] = {0, 0, -1, 1};

int go(int y, int x){
    if(d[y][x] != -1) return d[y][x];
    if(x == 1 && y == 1) return 1;
    d[y][x] = 0;
    for(int i =0; i < 4; i++) {
        if(y + dy[i] < 1 || y +dy[i] > n || x + dx[i] < 1 || x + dx[i] > m) continue;
        if((a[y][x] < a[y+dy[i]][x+dx[i]])){
            d[y][x] += go(y + dy[i], x + dx[i]);
        }
    }
    return d[y][x];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m ; ++j) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));

    cout << go(n, m) << '\n';

    return 0;
}