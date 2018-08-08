#include <iostream>
using namespace std;
int d[1001];
int p[10001];

int go(int n){
    if(n == 0) return 0;
    if(n == 1) return p[1];
    if(d[n] > 0) return d[n];
    d[n] = go(n-1) + p[1];
    for(int i =2; i<=n; i++){
        int temp = go(n-i) + p[i];
        if(d[n] < temp) d[n] = temp;
    }
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    cout << go(n) << '\n';
    return 0;
}