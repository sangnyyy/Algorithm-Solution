#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, e, ans, maxDist, farNode;
bool a[10001][10001];
bool check[10001];
int edge[10001];

void getMaxDistNode(int node, int dist){
    if(maxDist < dist) {maxDist = dist; farNode = node;}
    for (int i = 1; i <= e; ++i) {
        if(a[node][i] && !check[i]){
            check[i] = true;
            if(i > node) getMaxDistNode(i, dist + edge[i]);
            else getMaxDistNode(i, dist + edge[node]);
            check[i] = false;
        }
    }
}

void getAns(int node, int dist){
    for (int i = 1; i <= e; ++i) {
        if(a[node][i] && !check[i]){
            check[i] = true;
            if(i > node) getAns(i, dist + edge[i]);
            else getAns(i, dist + edge[node]);
            check[i] = false;
        }
    }
    ans = max(ans, dist);
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int p, c, w;
        cin >> p >> c >> w;
        e = max(e, c);
        a[p][c] = a[c][p] = true;
        edge[c] = w;
    }
    check[1] = true;
    getMaxDistNode(1, 0);
    check[1] = false;
    check[farNode] = true;
    getAns(farNode, 0);
    check[farNode] = false;
    cout << ans << '\n';
    return 0;
}
