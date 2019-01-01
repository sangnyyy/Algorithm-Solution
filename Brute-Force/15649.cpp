//
// Created by SML on 1/1/19.
//

#include <iostream>
#include <vector>

using namespace std;
int n, m;
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
        bool inVector = false;
        for (int j = 0; j < v.size(); ++j) {
            if (i == v[j]) inVector = true;
        }
        if (!inVector) {
            v.push_back(i);
            dfs(count + 1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
        dfs(1);
        v.pop_back();
    }
    return 0;
}