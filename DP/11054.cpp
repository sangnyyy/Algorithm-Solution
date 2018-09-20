//
// Created by SML on 2018. 9. 20..
//

#include <cstdio>
#include <algorithm>

using namespace std;
int n, MAX;
int a[1001];
int d[2][1001];

int down(int now){
    if(now == 1) return 1;
    if(d[0][now] > 0) return d[0][now];
    d[0][now] = 1;
    for (int i = now-1; i >= 1; --i) {
        if(a[i] < a[now]){
            d[0][now] = max(d[0][now], down(i) + 1);
        }
    }
    return d[0][now];
}

int up(int now){
    if(now == n) return 1;
    if(d[1][now] > 0) return d[1][now];
    d[1][now] = 1;
    for (int i = now+1; i <= n; ++i) {
        if(a[i] < a[now]){
            d[1][now] = max(d[1][now], up(i) + 1);
        }
    }
    return d[1][now];
}



int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int temp = down(i) + up(i) - 1;
        MAX = max(temp, MAX);
    }
    printf("%d\n", MAX);
    return 0;
}