#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, result = -1;
char arr[11][11];
bool visit[11][11][11][11];

class loc {
public:
    int ry;
    int rx;
    int by;
    int bx;
    int c;

    loc(int ry, int rx, int by, int bx, int c) : ry(ry), rx(rx), by(by), bx(bx), c(c) {}
};

int sry, srx, sby, sbx;

queue<loc> q;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'B') {
                sby = i;
                sbx = j;
            }
            if (arr[i][j] == 'R') {
                sry = i;
                srx = j;
            }
        }
    }

    q.push(loc(sry, srx, sby, sbx, 0));
    visit[sry][srx][sby][sbx] = true;
}

int main() {

    input();

    while (!q.empty()) {

        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int c = q.front().c;

        q.pop();

        if(c > 10){
            break;
        }

        if (arr[ry][rx] == 'O' && arr[by][bx] != 'O') {
            result = c;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;

            while (true) {
                if (arr[nry + dy[i]][nrx + dx[i]] == '#') break;
                nry = nry + dy[i];
                nrx = nrx + dx[i];
                if (arr[nry][nrx] == 'O') break;
            }

            while (true) {
                if (arr[nby + dy[i]][nbx + dx[i]] == '#') break;
                nby = nby + dy[i];
                nbx = nbx + dx[i];
                if (arr[nby][nbx] == 'O') break;
            }

            if (arr[nby][nbx] == 'O') continue;

            if (nrx == nbx && nry == nby) {
                if (arr[nby][nbx] == 'O') continue;
                if (abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by)) {
                    nrx -= dx[i];
                    nry -= dy[i];
                } else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (!visit[nry][nrx][nby][nbx]) {
                visit[nry][nrx][nby][nbx] = true;
                q.push(loc(nry, nrx, nby, nbx, c + 1));
            }
        }

    }

    cout << result << '\n';

    return 0;
}