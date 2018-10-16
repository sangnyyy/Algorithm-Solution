//
// Created by SML on 2018. 10. 16..
//

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

int a[5][8];    //톱니
int k;

void rotate(int wheel, int dir) {
    if (dir == 0) return;
    if (dir == 1) {
        int temp = a[wheel][7];
        for (int j = 7; j > 0; --j) {
            a[wheel][j] = a[wheel][j - 1];
        }
        a[wheel][0] = temp;
    }
    if (dir == -1) {
        int temp = a[wheel][0];
        for (int j = 0; j < 7; ++j) {
            a[wheel][j] = a[wheel][j + 1];
        }
        a[wheel][7] = temp;
    }
}

void rotateFunc(int wheel, int dir, int * arr){
    arr[wheel] = dir;
    for (int i = wheel; i > 1 ; --i) {
        if(a[i-1][2] == a[i][6]){
            break;
        }
        dir *= -1;
        arr[i-1] = dir;
    }
    dir = arr[wheel];
    for (int i = wheel; i < 4; ++i) {
        if(a[i+1][6] == a[i][2]){
            break;
        }
        dir *= -1;
        arr[i+1] = dir;
    }
}



int main() {
    string stat;
    for (int i = 0; i < 4; ++i) {
        cin >> stat;
        for (int j = 0; j < stat.size(); ++j) {
            a[i + 1][j] = stat[j] - '0';
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int arr[5];
        memset(arr, 0, sizeof(arr));
        int wheel, dir;
        cin >> wheel >> dir;
        rotateFunc(wheel, dir, arr);
        for (int j = 1; j < 5; ++j) {
            rotate(j, arr[j]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 4; i++)
        ans += (a[i][0] == 1 ? pow(2, i-1) : 0 );

    cout << ans << '\n';

    return 0;
}