#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int binary_find(int start, int end, int goal, vector<int>& v){
    int mid = (start + end)/2;
    if(start > end) return -1;
    if(v[mid] == goal) return mid;
    if(v[mid] < goal) return binary_find(start + 1, end, goal, v);
    if(v[mid] > goal) return binary_find(start, end - 1, goal, v);
}

void rvInit(vector<int>&rv){
    for (int i = 1; i <= 20; ++i) {
        rv.push_back(i);
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    vector<int> v;
    vector<int> rv;
    rvInit(rv);
    while (m) {
        int vSize = (int)v.size();
        string s;
        int num;
        cin >> s;
        if (s == "add") {
            cin >> num;
            if(binary_find(0, vSize-1, num, v) == -1) {
                v.push_back(num);
                sort(v.begin(), v.end());
                for (int i = 0; i < rv.size(); ++i) {
                    if(rv[i] == num) rv.erase(rv.begin() + i);
                }
            }
        } else if (s == "check") {
            cin >> num;
            if(binary_find(0, vSize-1, num, v) != -1) {
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        } else if (s == "remove") {
            cin >> num;
            int temp = binary_find(0, vSize-1, num, v);
            if(temp != -1) {
                v.erase(v.begin() + temp);
            }
        } else if (s == "toggle") {
            cin >> num;
            int temp = binary_find(0, vSize-1, num, v);
            if(temp != -1) {
                v.erase(v.begin() + temp);
            }else{
                v.push_back(num);
                sort(v.begin(), v.end());
                for (int i = 0; i < rv.size(); ++i) {
                    if(rv[i] == num) rv.erase(rv.begin() + i);
                }
            }
        } else if (s == "all") {
            while(!rv.empty()){
                v.push_back(rv[rv.size()-1]);
                rv.pop_back();
            }
            sort(v.begin(), v.end());
        } else {
            while(!v.empty()){
                rv.push_back(v[v.size()-1]);
                v.pop_back();
            }
            sort(rv.begin(), rv.end());
        }
        m--;
    }
    return 0;
}