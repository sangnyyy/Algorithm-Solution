//
// Created by SML on 1/1/19.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = {0, 1, 0,-1};
int dy[] = {1, 0, -1, 0};

int t;

int main(){
    ios::sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int dir, locX, locY, maxX, maxY, minX, minY;
        dir = locX = locY = maxX = maxY = minX = minY = 0;
        string order;
        cin >> order;
        for (int j = 0, len = order.size(); j < len; ++j) {
            if(order[j] == 'F'){
                int dirX = dx[dir], dirY = dy[dir];
                locX += dirX; locY += dirY;
                maxX = max(maxX, locX); maxY = max(maxY, locY);
                minX = min(minX, locX); minY = min(minY, locY);
            }if(order[j] == 'B'){
                int dirX = dx[dir]* (-1), dirY = dy[dir]* (-1);
                locX += dirX; locY += dirY;
                maxX = max(maxX, locX); maxY = max(maxY, locY);
                minX = min(minX, locX); minY = min(minY, locY);
            }
            if(order[j] == 'L'){if(dir == 0) dir = 3; else dir--;}
            if(order[j] == 'R'){if(dir == 3) dir = 0; else dir++;}
        }
        int ans = (maxX - minX) * (maxY - minY);
        cout << ans << '\n';
    }
    return 0;
}