//
// Created by SML on 2018. 10. 1..
//

#include <iostream>
#include <utility>

#define ll long long

using namespace std;
ll d[31][31];

ll go(int w, int h) {
    if (w == 0 && h == 0) return 1;
    if (d[w][h] > 0) return d[w][h];
    if (w == 0) {
        d[w][h] = go(w, h - 1);
    }
    if (h == 0) {
        d[w][h] = go(w - 1, h + 1);
    }
    if(w != 0 && h != 0) d[w][h] = go(w, h-1) + go(w-1, h+1);
    return d[w][h];
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        cout << go(n - 1, 1) << '\n';
    }
    return 0;
}