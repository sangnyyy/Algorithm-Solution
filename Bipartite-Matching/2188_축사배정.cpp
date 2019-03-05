////
//// Created by SML on 3/5/19.
////

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 201
using namespace std;

int n,m, ans;

bool visit[MAX];
int room[MAX];
vector<int> want[MAX];

int dfs(int cowNumber){
    if(visit[cowNumber]) return 0;
    visit[cowNumber] = true;
    for(int w : want[cowNumber]){
        if(!room[w] || dfs(room[w])){
            room[w] = cowNumber;
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int count;
        cin >> count;
        for (int j = 1; j <= count; ++j) {
            int roomNumber;
            cin >> roomNumber;
            want[i].push_back(roomNumber);
        }
    }
    for (int i = 1; i <= n; ++i) {
        fill(visit, visit + n, false);
        if(dfs(i)) ans++;
    }
    cout << ans << '\n';
    return 0;
}
