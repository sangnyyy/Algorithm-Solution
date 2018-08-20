//
// Created by SML on 2018. 8. 20..
//

#include <iostream>
#include <queue>
#include <utility>
#define MAX 200000

bool isVisited[200001];
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, count = 0, MIN;
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    while(!q.empty()){
        int now = q.front().first;
        int seconds = q.front().second;
        q.pop();
        if(now == k){
            if(!isVisited[now]){ count++; MIN = seconds; }
            else {
                if(MIN >= seconds) count++;
            }
        }
        isVisited[now] = true;
        if(now + 1 <= MAX && !isVisited[now+1]) {q.push(make_pair(now+1, seconds+1));}
        if(now - 1 >= 0 && !isVisited[now-1]) {q.push(make_pair(now-1, seconds+1));}
        if(2*now <= MAX && !isVisited[now*2]) {q.push(make_pair(now*2, seconds+1));}
    }
    cout << MIN << '\n';
    cout << count << '\n';
    return 0;
}