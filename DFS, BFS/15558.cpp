//
// Created by SML on 2018. 8. 30..
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;


int a[200001][2];
bool v[200001][2];

int main() {

    int n, k, ans = 0;
    queue<pair<pair<int, int>, int>> q;
    cin >> n >> k;
    string temp;
    cin >> temp;
    for (int j = 1; j <= n; ++j) {
        a[j][0] = temp[j - 1] - '0';
    }
    cin >> temp;
    for (int j = 1; j <= n; ++j) {
        a[j][1] = temp[j - 1] - '0';
    }

    v[1][0] = true;
    q.push(make_pair(make_pair(1, 0), 1));
    while(!q.empty()){
        pair<pair<int, int>, int> temp = q.front();
        q.pop();
        int loc = temp.first.first, line = temp.first.second, count = temp.second;
        if(loc+1 > n || loc+k > n){
            ans = 1;
            break;
        }
        if(a[loc+1][line]&&!v[loc+1][line] && (loc+1 <= n)){
            q.push(make_pair(make_pair(loc+1, line), count+1));
            v[loc+1][line] = true;
        }
        if(a[loc-1][line]&&!v[loc-1][line] && (loc>count+1)){
            q.push(make_pair(make_pair(loc-1, line), count+1));
            v[loc-1][line] = true;
        }
        if(a[loc+k][!line]&&!v[loc+k][!line] && (loc+k <= n)){
            q.push(make_pair(make_pair(loc+k, !line), count+1));
            v[loc+k][!line] = true;
        }

    }
    cout << ans << '\n';
    return 0;
}