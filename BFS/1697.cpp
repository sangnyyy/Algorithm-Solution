//
// Created by SML on 2018. 8. 20..
//

#include <iostream>
#include <queue>
#include <utility>
#define MAX 100000

bool isVisited[100001];
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    isVisited[n] = true;
    while(!q.empty()){
        int now = q.front().first;
        int seconds = q.front().second;
        q.pop();
        if(now == k) {cout << seconds << '\n'; break;}
        if(now + 1 <= MAX && !isVisited[now+1]) {q.push(make_pair(now+1, seconds+1)); isVisited[now+1] = true;}
        if(now - 1 >= 0 && !isVisited[now-1]) {q.push(make_pair(now-1, seconds+1));isVisited[now-1] = true;}
        if(2*now <= MAX && !isVisited[now*2]) {q.push(make_pair(now*2, seconds+1));isVisited[now*2] = true;}
    }
    return 0;
}