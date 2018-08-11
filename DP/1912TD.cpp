#include <iostream>
using namespace std;

int d[100001];
int a[100001];

int go(int n){
    if(n == 0) return 0;
    if(d[n] > 0) return d[n];
    d[n] = max(go(n-1) + a[n], a[n]);
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, result;
    cin >> n;
    for(int i =1; i<= n; i++){
        cin >> a[i];
    }
    result = go(n);
    for(int i =1; i<= n-1; i++){
        if(result < d[i]) result = d[i];
    }
    cout << result << '\n';
    return 0;
}