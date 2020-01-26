//
// Created by SML on 1/23/20.
//

#include <iostream>
#include <queue>
using namespace std;


// F 총 층, S 현 위치, G 목적지 위치, U 위로 가기, D 아래로 가기
int f, s, g, u, d;

bool visit[1000001];

class pos{
public:
    int floor;
    int count;
    pos(int floor, int count) : floor(floor), count(count) {}
};

queue<pos> q;

int main(){

    cin >> f >> s >> g >> u >> d;

    q.push(pos(s, 0));
    visit[s] = true;

    bool success = false;

    while (!q.empty()){
        int count = q.front().count;
        int floor = q.front().floor;
        q.pop();

        if(floor == g){
            success = true;
            cout << count << '\n';
        }

        int upFloor = floor + u;
        int downFloor = floor - d;

        if(upFloor <= g && !visit[upFloor]){
            visit[upFloor] = true;
            q.push(pos(upFloor, count + 1));
        }

        if(downFloor >= 1 && !visit[downFloor]){
            visit[downFloor] = true;
            q.push(pos(downFloor, count + 1));
        }

    }

    if(!success) cout << "use the stairs" << '\n';


    return 0;
}