//
// Created by SML on 2018. 8. 19..
//

#include <stdio.h>

long long d[101][21];
int a[101];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    d[1][a[1]] = 1;
    for (int i = 2; i <n ; ++i) {
         for (int j = 0; j < 21; ++j) {
            if(d[i-1][j] > 0){
                if(j - a[i] >= 0) d[i][j - a[i]] += d[i-1][j];
                if(j + a[i] <= 20) d[i][j + a[i]] += d[i-1][j];
            }
        }
    }
    printf("%lld\n", d[n-1][a[n]]);
    return 0;
}