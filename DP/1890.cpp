#include <iostream>
using namespace std;
long long d[101][101];
int a[101][101];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> a[i][j];
        }
    }
    d[1][1] = 1;
    for(int i =1; i<= N; i++){
        for(int j =1; j<= N; j++){
            if(d[i][j] == 0 || (i == N && j == N)) continue;
            if(j + a[i][j] <= N){
                d[i][j+a[i][j]] += d[i][j];
            }
            if(i + a[i][j] <= N){
                d[i+a[i][j]][j] += d[i][j];
            }
        }
    }
    cout << d[N][N] << '\n';
    return 0;
}