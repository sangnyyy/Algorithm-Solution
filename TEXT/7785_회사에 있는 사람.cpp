//
// Created by SML on 1/26/20.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#define ENTER "enter"

using namespace std;

int n;

bool compare(string a, string b){
    return a >= b;
}


int main(){

    cin >> n;

    map<string, bool> m;
    vector<string> result;

    for (int i = 1; i <= n; ++i) {
        string name, log;
        cin >> name >> log;
        if(log == ENTER){
            if(!m.count(name)){
                result.push_back(name);
            }
            m[name] = true;
        }else{
            m[name] = false;
        }
    }

    sort(result.begin(), result.end(), compare);

    for (int i = 0; i < result.size() ; ++i) {
        if(m[result[i]]) cout << result[i] << '\n';
    }

    return 0;
}