//
// Created by SML on 3/5/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50
using namespace std;

int n, ans;
class shark{
public:
    int size;
    int speed;
    int intel;
    shark(int size, int speed, int intel) : size(size), speed(speed), intel(intel) {}
};

vector<shark> v;
vector<int> eat[MAX + 1];
int eated[MAX + 1];
bool visit[MAX + 1];

bool canEat(int sharkNumber){
    if(visit[sharkNumber]) return false;
    visit[sharkNumber] = true;
    for (int e : eat[sharkNumber]){
        if(!eated[e] || canEat(eated[e])) {
            eated[e] = sharkNumber;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int size, speed, intel;
        cin >> size >> speed >> intel;
        v.push_back(shark(size, speed, intel));
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(v[i].size == v[j].size && v[i].speed == v[j].speed && v[i].intel == v[j].intel) eat[i+1].push_back(j+1);
            else if(v[i].size >= v[j].size && v[i].speed >= v[j].speed && v[i].intel >= v[j].intel) eat[i+1].push_back(j+1);
            else if(v[i].size <= v[j].size && v[i].speed <= v[j].speed && v[i].intel <= v[j].intel) eat[j+1].push_back(i+1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            fill(visit, visit + MAX + 1, false);
            if(canEat(i)) ans++;
        }
    }
    cout << n-ans << '\n';
    return 0;
}
