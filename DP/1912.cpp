#include <iostream>
using namespace std;

int d[100001];
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
    result = d[1] = a[1];
    for(int i =2; i<=n; i++){/**/
        d[i] = max(d[i-1] + a[i], a[i]);
    }
    for(int i =2; i<=n; i++){
        if(result < d[i]) result = d[i];
    }
    cout << result <<'\n';


    return 0;
}