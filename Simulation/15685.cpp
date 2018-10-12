#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int a[101][101];
int n;

char dir[] = {'r', 'u', 'l', 'd'};

int getAns(){
    int ans = 0;
    for (int i = 0; i <= 99; ++i) {
        for (int j = 0; j <= 99; ++j) {
            if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) ans++;
        }
    }
    return ans;
}

void start(int x, int y, int d, int g,vector<char> v){
    v.push_back(dir[d]);
    x = x + dx[d];
    y = y + dy[d];
    a[y][x] = 1;
    for (int j = 0; j < g; ++j) {
        int vSize = v.size()-1;
        for (int k = vSize; k >= 0; --k) {
            for (int l = 0; l < 4; ++l) {
                if(v[k] == dir[l]) {
                    int num = (l+1)%4;
                    v.push_back(dir[num]);
                    x = x + dx[num];
                    y = y + dy[num];
                    a[y][x] = 1;
                }
            }
        }
    }
}


int main(){
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        a[y][x] = 1;
        vector<char> v;
        start(x, y, d, g, v);
    }
    cout << getAns() << '\n';
    return 0;
}