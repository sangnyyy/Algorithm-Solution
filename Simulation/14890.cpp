#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
int a[101][101];


bool go(int now, char stat, vector<int> v) {
    if (now == n - 1) {
        return true;
    }
    bool b = false;
    if (now + 1 < n && (v[now] == v[now + 1])) b = go(now + 1, 'n', v);
    //오름
    bool isSame = true;
    int val = v[now];
    for (int i = 1; i < m; ++i) {
        if(v[now + i] != val) isSame = false;
    }
    if(v[now + m] -1 != v[now + m-1]) isSame = false;
    if(isSame && (now + m < n) && stat != 'd'){
        if(!b){
            b = go(now + m, 'a', v);
        }
    }

    //내림
    if (v[now] - 1 == v[now + 1] && (now + m) < n) {
        isSame = true;
        for (int i = 1; i < m; ++i) {
            if (v[now + i] != v[now + i + 1]) isSame = false;
        }
        if (isSame && (now + m < n)) {
            if (!b) {
                b = go(now + m, 'd', v);
            }
        }
    }
    return b;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> v;
        for (int j = 1; j <= n; ++j) {
            v.push_back(a[i][j]);
        }
        if (go(0, 'n', v)) ans++;
    }

    for (int i = 1; i <= n; ++i) {
        vector<int> v;
        for (int j = 1; j <= n; ++j) {
            v.push_back(a[j][i]);
        }
        if (go(0, 'n', v)) ans++;
    }

    cout << ans << '\n';
    return 0;
}