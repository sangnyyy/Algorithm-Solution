#include <iostream>
#include <cstring>
using namespace std;

int d[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t > 0){
        int n, result = 0;
        cin >> n;
        memset(d, 0, sizeof(d));
        for(int i = 1; i<=n;i++){
            d[i] = 1;
        }
        for(int i = 2; i<=n;i++){
            for(int j=1; i*j <= n; j++){
                d[i*j] = !d[i*j];
            }
        }
        for(int i = 1; i<=n;i++){
            if(d[i]) result++;
        }
        cout << result << '\n';
        t--;
    }
    return 0;
}