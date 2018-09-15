//
// Created by SML on 2018. 8. 21..
//

#include <iostream>
#include <queue>
#include <utility>
#define MAX 200000

int d[MAX+1];
bool isVisited[MAX+1];

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    while(!q.empty()){
        int now = q.front().first;
        int seconds = q.front().second;
        q.pop();
        if(!isVisited[now]){ d[now] = seconds; isVisited[now] = true;}
        else {
            if(d[now] >= seconds) d[now] = seconds;
        }
        if(now+1 <= MAX && !isVisited[now+1]){
            q.push(make_pair(now+1, seconds+1));
        }
        if(now-1 >= 0 && !isVisited[now-1]){
            q.push(make_pair(now-1, seconds+1));
        }
        if(now*2 <= MAX && !isVisited[now*2]){
            q.push(make_pair(now*2, seconds));
        }
    }
    cout << d[k] << '\n';
    return 0;
}
