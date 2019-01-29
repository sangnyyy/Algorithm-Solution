//
// Created by SML on 1/29/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 0x3f3f3f3f
using namespace std;

const int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

class Land {
public:
    int energy;
    vector<int> tree;
};

int n, m, k, ans;

// 겨울에 주는 양분
int a[11][11];

Land land[11][11];
// 죽은 나무들에게서 가저오는 양분
int energy[11][11];

void landInit() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            land[i][j].energy = 5;
        }
    }
}

int main() {
    landInit();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        land[x][y].tree.push_back(z);
    }

    while (k > 0) {
        memset(energy, 0, sizeof(energy));
        //봄
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 나무가 존재하는가?
                if (land[i][j].tree.size() > 0) {
                    int tempCnt = 0;
                    sort(land[i][j].tree.begin(), land[i][j].tree.end());
                    for (int l = 0; l < land[i][j].tree.size(); ++l) {
                        if (land[i][j].tree[l] <= land[i][j].energy) {
                            land[i][j].energy -= land[i][j].tree[l];
                            land[i][j].tree[l]++;
                        } else {
                            energy[i][j] += ((land[i][j].tree[l]) / 2);
                            tempCnt++;
                        }
                    }
                    for (int l = 0; l < tempCnt; ++l) {
                        land[i][j].tree.pop_back();
                    }
                    // 죽은 나무를 제외하고 정렬.
                    sort(land[i][j].tree.begin(), land[i][j].tree.end());
                }
            }
        }
        //여름
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                land[i][j].energy += energy[i][j];
            }
        }
        //가을
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int l = 0; l < land[i][j].tree.size(); ++l) {
                    //나이가 5의 배수이면 번식하자!
                    if ((land[i][j].tree[l] % 5) == 0) {
                        for (int i1 = 0; i1 < 8; ++i1) {
                            int nextX = j + dx[i1], nextY = i + dy[i1];
                            if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
                            //j, i
                            land[nextY][nextX].tree.push_back(1);
                        }
                    }
                }
            }
        }
        //겨울
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                land[i][j].energy += a[i][j];
            }
        }
        k--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; ++j) {
            ans += (land[i][j].tree.size());
        }
    }
    cout << ans << '\n';
    return 0;
}