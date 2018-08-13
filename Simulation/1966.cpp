#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t > 0) {
        int n, m, count = 1;
        queue<pair<int, int>> q;
        cin >> n >> m;
        int * arr = new int[n];
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            arr[i] = temp;
            q.push(make_pair(temp, i));
        }
        while (!q.empty()) {
            int temp1, temp2;
            int max = 0, index;
            for(int i=0; i<n; i++){
                if(max < arr[i]){ max = arr[i]; index = i;}
            }
            if (q.front().first < max) {
                temp1 = q.front().first;
                temp2 = q.front().second;
                q.pop();
                q.push(make_pair(temp1, temp2));
            }
            else{
                if(q.front().second == m) cout << count << '\n';
                q.pop();
                arr[index] = 0;
                count ++;
            }
        }
        t--;
    }

    return 0;
}