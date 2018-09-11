//
// Created by SML on 2018. 9. 11..
//

#include <iostream>
#include <algorithm>

using namespace std;

int a[501][501];
int point[19][3][2] = {
        {{0, 1}, {0,  2},  {0,  3}},
        {{1, 0}, {2,  0},  {3,  0}},
        {{1, 0}, {1,  1},  {1,  2}},
        {{0, 1}, {1,  0},  {2,  0}},
        {{0, 1}, {0,  2},  {1,  2}},
        {{1, 0}, {2,  0},  {2,  -1}},
        {{0, 1}, {0,  2},  {-1, 2}},
        {{1, 0}, {2,  0},  {2,  1}},
        {{0, 1}, {0,  2},  {1,  0}},
        {{0, 1}, {1,  1},  {2,  1}},
        {{0, 1}, {1,  0},  {1,  1}},
        {{0, 1}, {-1, 1},  {-1, 2}},
        {{1, 0}, {1,  1},  {2,  1}},
        {{0, 1}, {1,  1},  {1,  2}},
        {{1, 0}, {1,  -1}, {2,  -1}},
        {{0, 1}, {0,  2},  {-1, 1}},
        {{0, 1}, {0,  2},  {1,  1}},
        {{1, 0}, {2,  0},  {1,  1}},
        {{1, 0}, {2,  0},  {1,  -1}},

};

int main() {
    int n, m, MAX = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 19; ++k) {
                int temp = a[i][j];
                bool ok = true;
                for (int l = 0; l < 3; ++l) {
                    int x = j + point[k][l][1];
                    int y = i + point[k][l][0];
                    if (x >= 1 && x <= m && y >= 1 && y <= n) {
                        temp += a[y][x];
                    } else {
                        break;
                        ok = false;
                    }
                }
                if (ok) {
                    MAX = max(MAX, temp);
                }
            }
        }
    }

    cout << MAX << '\n';
    return 0;
}