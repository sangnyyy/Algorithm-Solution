//
// Created by SML on 3/10/19.
//

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#define MAX 200000
using namespace std;

int t, f;
int parent[MAX + 1];
int setNumber[MAX + 1];

int getParent(int userIdx){
    if(parent[userIdx] == userIdx) return userIdx;
    return getParent(parent[userIdx]);
}

int unionParent(int user1Idx, int user2Idx){
    user1Idx = getParent(user1Idx);
    user2Idx = getParent(user2Idx);
    if(user1Idx != user2Idx){
        parent[user2Idx] = user1Idx;
        setNumber[user1Idx] += setNumber[user2Idx];
    }
    return setNumber[user1Idx];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> f;
        int userCount = 0;
        map<string, int> users;
        for (int i = 1; i <= f*2; ++i) {
            parent[i] = i;
            setNumber[i] = 1;
        }
        while(f--){
            string user1, user2;
            cin >> user1 >> user2;
            if(users.count(user1) == 0) users[user1] = ++userCount;
            if(users.count(user2) == 0) users[user2] = ++userCount;
            cout << unionParent(users[user1], users[user2]) << '\n';
        }
    }
    return 0;
}