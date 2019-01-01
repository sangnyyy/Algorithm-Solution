//
// Created by SML on 1/1/19.
//

#include <iostream>
#include <vector>

using namespace std;
int n, m;
bool useNum[9];
vector<int> v;

void dfs(int count) {
    if (count == m) {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if(useNum[i]) continue;
        v.push_back(i);
        useNum[i] = true;
        dfs(count + 1);
        useNum[i] = false;
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
        useNum[i] = true;
        dfs(1);
        useNum[i] = false;
        v.pop_back();
    }
    return 0;
}