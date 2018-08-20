//
// Created by SML on 2018. 8. 20..
//

#include <iostream>
#include <queue>
#include <vector>
#define MAX 200000

int d[200001];
int from[200001];
bool isVisited[200001];


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    isVisited[n] = true;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now + 1 <= MAX && !isVisited[now+1]){
            isVisited[now+1] = true;
            d[now+1] += (d[now] + 1);
            from[now+1] = now;
            q.push(now+1);
        }
        if(now - 1 >= 0 && !isVisited[now-1]){
            isVisited[now-1] = true;
            d[now-1] += (d[now] + 1);
            from[now-1] = now;
            q.push(now-1);
        }
        if(2*now <= MAX && !isVisited[2*now]){
            isVisited[now*2] = true;
            d[now*2] += (d[now] + 1);
            from[now*2] = now;
            q.push(now*2);
        }
    }
    cout << d[k] << '\n';
    int at = k;
    vector<int> v;
    v.push_back(k);
    while(at != n){
        v.push_back(from[at]);
        at = from[at];
    }
    vector<int>::reverse_iterator rit;
    for (rit = v.rbegin(); rit != v.rend(); rit++) {
        cout << *rit << ' ';
    }
    return 0;
}