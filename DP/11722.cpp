//
// Created by SML on 2018. 8. 20..
//

#include <stdio.h>
int a[1001];
int d[1001];

int go(int n){
    if(n==1) return 1;
    if(d[n] > 0) return d[n];
    d[n] = 1;
    for (int i = 1; i < n ; ++i) {
        if(a[n] < a[n-i]){
            int temp = go(n-i) + 1;
            if(temp > d[n]) d[n] = temp;
        }
    }
    return d[n];
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <=n ; ++i) {
        scanf("%d", &a[i]);
    }
    int MAX = go(1);
    for (int i = 2; i <=n ; ++i) {
        int temp = go(i);
        if(MAX < temp) MAX = temp;
    }
    printf("%d", MAX);
    return 0;
}