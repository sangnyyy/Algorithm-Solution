#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][1001];
int a[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    d[1][1] = a[1][1];
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            if((i <= n && i>=2)&& (j <=m && j >=2)) d[i][j] = max(d[i-1][j] + a[i][j], d[i][j-1] + a[i][j]);
            if((j <= m && j >=2) && (i >n || i <= 1)) d[i][j] = d[i][j-1] + a[i][j];
            if((j > m || j <=1 ) && (i>=2  && i <=n)) d[i][j] = d[i-1][j] + a[i][j];
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}