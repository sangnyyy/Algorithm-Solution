#include <iostream>
using namespace std;

int d[2][100001];
int a[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, result;
    cin >> n;
    for(int i =1; i<= n; i++){
        cin >> a[i];
    }
    result = d[0][1] = d[1][1] = a[1];
    for(int i =2; i<=n; i++){
        d[0][i] = max(d[0][i-1] + a[i], a[i]);
        d[1][i] = max(d[1][i-1] + a[i], d[0][i-2] + a[i]);
        d[1][i] = max(d[1][i], a[i]);
    }
    for(int i =1; i<=n; i++){
        if(result < d[1][i]) result = d[1][i];
    }
    cout << result <<'\n';


    return 0;
}