//
// Created by SML on 2018. 8. 16..
//

#include <iostream>
#include <cstring>
using namespace std;

int a[2001];
int d[2001][2001];

int go(int s, int e){
    if(s > e) return 0;
    if(s == e) return 1;
    if((s+1 == e) && a[s] == a[e]) {
        d[s][e] = 1;
        return d[s][e];
    }
    if(d[s][e] != -1) return d[s][e];
    d[s][e] = 0;
    if(a[s] == a[e] && go(s+1, e-1)) d[s][e] = 1;
    return d[s][e];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(d, -1, sizeof(d));
    int n, m;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        cin >> a[i];
    }
    cin >> m;
    while(m){
        int s, e;
        cin >> s >> e;
        cout << go(s, e) << '\n';
        m--;
    }
    return 0;
}