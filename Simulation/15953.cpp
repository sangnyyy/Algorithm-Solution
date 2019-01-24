//
// Created by SML on 1/25/19.
//

#include <iostream>
#define WON 10000
using namespace std;

int t;

int cp1[] = {0, 500, 300, 200, 50, 30, 10};
int cp2[] = {0, 512, 256, 128, 64, 32};
int cpp1[] = {0, 1, 3, 6, 10, 15, 21};
int cpp2[] = {0, 1, 3, 7, 15, 31};

int getCp(int num, int cppSize, int cp[], int cpp[]){
    for (int i = 0; i < cppSize; ++i) {
        if(cpp[i] >= num) return cp[i];
    }
    return 0;
}

int main(){
    cin >> t;
    int cpp1Size = sizeof(cpp1)/sizeof(int);
    int cpp2Size = sizeof(cpp2)/sizeof(int);
    for (int i = 1; i <= t; ++i) {
        int a, b, ans;
        cin >> a >> b;
        ans = (getCp(a, cpp1Size, cp1, cpp1) + getCp(b, cpp2Size, cp2, cpp2))*WON;
        cout << ans << '\n';
    }
    return 0;
}