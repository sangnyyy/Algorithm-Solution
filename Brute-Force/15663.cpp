//
// Created by SML on 1/1/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
int arr[10];
bool isUse[10];
vector<int> v;
vector<vector<int>> vv;

void dfs(int count){
    if(count == m){
        vv.push_back(v);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if(isUse[i]) continue;
        isUse[i] = true;
        v.push_back(arr[i]);
        dfs(count + 1);
        v.pop_back();
        isUse[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    dfs(0);
    sort(vv.begin(), vv.end());
    vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
    for (int i = 0, len = vv.size(); i < len; ++i) {
        for (int j = 0, len2 = vv[i].size(); j < len2; ++j) {
            cout << vv[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}