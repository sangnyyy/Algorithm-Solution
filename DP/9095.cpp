#include <iostream>
using namespace std;

int d[11];

int go(int n){
    if(n == 1) return 1;
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(d[n] > 0) return d[n];
    d[n] = go(n-1) + go(n-2) + go(n-3);
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;

    for(int i = 0; i< t; i++){
        cin >> n;
        cout << go(n) << endl;
    }

    return 0;
}

