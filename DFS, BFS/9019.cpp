//
// Created by SML on 2018. 8. 21..
//

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define MOD 10000
using namespace std;

int from[10001];
char how[10001];
bool isChecked[10001];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        int next;
        memset(from, 0, sizeof(from));
        memset(how, 0, sizeof(how));
        memset(isChecked, false, sizeof(isChecked));
        cin >> a >> b;
        isChecked[a]= true;
        from[a] = -1;
        queue<int> q;
        q.push(a);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            //D
            next = (now * 2) % MOD;
            if(!isChecked[next]) {
                q.push(next);
                from[next] = now;
                how[next] = 'D';
                isChecked[next] = true;
            }
            //S
            next = (now + 9999)%10000;
            if(!isChecked[next]) {
                q.push(next);
                from[next] = now;
                how[next] = 'S';
                isChecked[next] = true;
            }
            //L
            next = (now % 1000) * 10 + (now/1000);
            if(!isChecked[next]) {
                q.push(next);
                from[next] = now;
                how[next] = 'L';
                isChecked[next] = true;
            }
            //R
            next = (now/10) + (now%10)*1000;
            if(!isChecked[next]) {
                q.push(next);
                from[next] = now;
                how[next] = 'R';
                isChecked[next] = true;
            }
        }

        string ans = "";
        while (a != b) {
            ans += how[b];
            b = from[b];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';

    }
    return 0;
}

