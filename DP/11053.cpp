#include <iostream>
using namespace std;

int d[1001];
int a[1001];

int go(int n){
    if(n == 1) return 1;
    if(d[n] > 0) return d[n];
    d[n] = 1;
    for (int i = 1; i <= n-1; ++i) {
        if(a[n-i] < a[n]){
            int temp = go(n-i) + 1;
            if(d[n] < temp) d[n] = temp;
        }
    }
    return d[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, MAX = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int temp = go(i);
        if(MAX < temp) MAX = temp;
    }

    cout<< MAX << '\n';

    return 0;
}