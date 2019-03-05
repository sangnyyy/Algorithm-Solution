//
// Created by SML on 3/5/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int> want[1001];
int tasks[1001];
bool visit[1001];

bool canWork(int person){
    if(visit[person]) return false;
    visit[person] = true;
    for (int w : want[person]){
        if(!tasks[w] || canWork(tasks[w])) {
            tasks[w] = person;
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
            int taskNumber;
            cin >> taskNumber;
            want[i].push_back(taskNumber);
        }
    }
    for (int i = 1; i <= n; ++i) {
        fill(visit, visit + n, false);
        if(canWork(i)){
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
