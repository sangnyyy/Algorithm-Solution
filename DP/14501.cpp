#include <iostream>
using namespace std;
int T[16];
int P[16];
int d[16];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i =1; i <= n; i++){
        cin >> T[i] >> P[i];
    }
    if(T[n] == 1){
        d[n] = P[n];
    }
    for(int i = n-1; i>0; i--){
        if(i + T[i] -1 <= n) d[i] = max(d[i+1], d[i+T[i]] + P[i]);
        else d[i] = max(d[i+1], 0);
    }
    cout << d[1] << endl;
    
    return 0;
}
