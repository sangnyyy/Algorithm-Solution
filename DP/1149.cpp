#include <iostream>
using namespace std;

int a[1001][3];
int d[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, MIN;
    cin >> n;
    for(int i =1; i<=n;i++){
        for(int j=0; j<3; j++){
            cin >> a[i][j];
        }
    }
    d[1][0] = a[1][0]; d[1][1] = a[1][1]; d[1][2] = a[1][2];

    for(int i=2; i<=n; i++){
        d[i][0] = a[i][0] + min(d[i-1][1], d[i-1][2]);
        d[i][1] = a[i][1] + min(d[i-1][0], d[i-1][2]);
        d[i][2] = a[i][2] + min(d[i-1][0], d[i-1][1]);
    }

    MIN = d[n][0]; if(MIN > d[n][1]) MIN = d[n][1]; if(MIN > d[n][2]) MIN = d[n][2];

    cout << MIN << '\n';

    return 0;
}
