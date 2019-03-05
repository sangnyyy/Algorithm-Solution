//
// Created by SML on 3/5/19.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, ans;
vector<int> want[1001];
bool visit[1001];
int task[1001];

bool canDo(int person){
    if(visit[person]) return false;
    visit[person] = true;
    for(int w : want[person]){
        if(!task[w] || canDo(task[w])){
            task[w] = person;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int count; cin >> count;
        for (int j = 1; j <= count; ++j) {
            int taskNumber; cin >> taskNumber; want[i].push_back(taskNumber);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            memset(visit, 0, sizeof(visit));
            if(canDo(i)) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}