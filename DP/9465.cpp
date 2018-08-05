#include <iostream>
#include <algorithm>
using namespace std;

int a[2][100001];
int d[2][100001];

int main(){
    int t;
    cin >> t;
    while(t > 0) {
        int n;
        cin >> n;
        for(int i =0; i< 2; i++){
            for(int j =1 ;j<=n; j++){
                cin >> a[i][j];
            }
        }
        d[1][1] = a[1][1]; d[0][1] = a[0][1];
       for(int i=2; i<=n; i++){
            d[0][i] = max(d[1][i-1] + a[0][i], d[1][i-2] + a[0][i]);
            d[1][i] = max(d[0][i-1] + a[1][i], d[0][i-2] + a[1][i]);
        }
        cout << max(d[0][n], d[1][n]) << '\n';
        t--;
    }
    return 0;
}
