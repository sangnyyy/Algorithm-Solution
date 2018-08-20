//
// Created by SML on 2018. 8. 20..
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string a, b;
    int ans = 0;
    cin >> a >> b;
    int count = b.size() - a.size();
    if (!count) {
        for (int i = 0; i < b.size(); ++i) {
            if (a[i] != b[i]) ans++;
        }
    } else {
        int MIN = 0;

        for (int j = 0; j < a.size(); ++j) {
            if (a[j] != b[j]) ans++;
        }

        for (int i = 1; i <= count; ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] != b[j + i]) MIN++;
            }
            if(MIN < ans) ans = MIN;
            MIN = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}