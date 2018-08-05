#include <iostream>
using namespace std;

int d[1001];

int go(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(d[n] > 0) return d[n];
    d[n] = ((go(n-1)%10007) + (go(n-2)%10007))%10007;
    return d[n];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}
