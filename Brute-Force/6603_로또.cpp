//
// Created by SML on 1/25/20.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[14];

vector<int> elems;

void dfs(int now, vector<int> elems, int count){
    if(count == 6){
        int size = elems.size();
        for (int i = 0; i < size; ++i) {
            cout << elems[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = now + 1; i <= n; ++i) {
        elems.push_back(arr[i]);
        dfs(i, elems, count + 1);
        elems.pop_back();
    }
}

int main(){

    while(true){
        cin >> n;
        if(!n) break;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            elems.push_back(arr[i]);
            dfs(i, elems, 1);
            elems.pop_back();
        }
        cout << '\n';
    }
    return 0;
}