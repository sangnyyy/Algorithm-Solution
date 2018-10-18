//
// Created by SML on 2018. 10. 18..
//

#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int n, k, l, ans;
int a[101][101];    // 0 - 빈칸, 1 - 사과, 2 - 뱀

int changeLoc[10001];
char direction[] = {'r', 'd', 'l', 'u'};
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> y >> x;
        a[y][x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
        int x;
        char d;
        cin >> x >> d;
        changeLoc[x] = (d - '0');
    }

    char dir = 'r';   // l, r, u, d
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(1, 1));
    while (true) {
        bool fin = false;
        ans++;
        int x = dq.back().second;
        int y = dq.back().first;
        for (int i = 0; i < 4; ++i) {
            if (dir == direction[i]) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // 끝나는 포인트~!
                if (nx > n || ny > n || nx < 1 || ny <1) {
                    fin = true;
                    break;
                }
                int tempMap[101][101];
                for (int j = 1; j <= n; ++j) {
                    for (int m = 1; m <= n; ++m) {
                        tempMap[j][m] = a[j][m];
                    }
                }
                for (int j = 0; j < dq.size(); ++j) {
                    int tx = dq[j].second;
                    int ty = dq[j].first;
                    tempMap[ty][tx] = 2;
                }
                if (tempMap[ny][nx] == 2) {
                    fin = true;
                    break;
                }
                if (tempMap[ny][nx] == 1) {
                    dq.push_back(make_pair(ny, nx));
                    a[ny][nx] = 0;
                }
                if (tempMap[ny][nx] == 0) {
                    dq.push_back(make_pair(ny, nx));
                    dq.pop_front();
                }
            }
        }
        if (changeLoc[ans] == 20) { //D
            int at;
            for (int i = 0; i < 4; ++i) {
                if(dir == direction[i]) {at = i; break;}
            }
            dir = direction[(at + 1) % 4];
        }
        else if (changeLoc[ans] == 28) {    //L
            int at;
            for (int i = 0; i < 4; ++i) {
                if(dir == direction[i]) {at = i; break;}
            }
            if(at == 0) dir = direction[3];
            else dir = direction[at-1];
        }

        if(fin) break;
    }
    cout << ans << '\n';
    return 0;
}