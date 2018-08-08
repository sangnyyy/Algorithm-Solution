#include <iostream>
using namespace std;

int d[100001];
int c[101];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i =1; i<=n; i++){
        cin >> c[i];
        d[c[i]] = 1;
    }

    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++){
            if(i-c[j] < 0) continue;
            if(d[i-c[j]]>0) {
                if (d[i] > 0) {
                    d[i] = (d[i] > d[i - c[j]] + 1) ? d[i - c[j]] + 1 : d[i];
                } else {
                    d[i] = d[i - c[j]] + 1;
                }
            }
        }
    }
    if(d[k] > 0) cout << d[k] << '\n';
    else cout << -1 << "\n";

    return 0;
}